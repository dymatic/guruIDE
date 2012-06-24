#include "header/comments.h"
#include "ui_comments.h"
#include <iostream>
#include <sstream>
using namespace std;
QTextEdit *codeeditor1;
Comments::Comments(QWidget *parent,QTextEdit *a) :
    QMainWindow(parent),
    ui(new Ui::Comments)
{
    ui->setupUi(this);
    this->setWindowTitle("Comments - Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/guru/guruComments.png"));
    QObject::connect(ui->cancelButton,SIGNAL(pressed()),this,SLOT(hide()));
    codeeditor1=a;

    QObject::connect(ui->paramButton,SIGNAL(pressed()),this,SLOT(writePmet()));
    QObject::connect(ui->returnButton,SIGNAL(pressed()),this,SLOT(writeMail()));
    QObject::connect(ui->okayButton,SIGNAL(pressed()),this,SLOT(writeComment()));
}

Comments::~Comments()
{
    delete ui;
}

void Comments::writePmet(){
    if(ui->documentationB->isChecked())
    {
        ui->commentText->textCursor().insertText("*@param ");
    }
}

void Comments::writeMail(){
    if(ui->documentationB->isChecked())
        ui->commentText->textCursor().insertText("*@return ");
}

void Comments::writeComment(){
    stringstream buff;

    if(ui->oneB->isChecked())
        buff<<"//";
    if(ui->multiB->isChecked())
            buff<<"/*";
    if(ui->documentationB->isChecked()&&ui->oneB->isChecked())
        buff<<"!";
    else if(ui->documentationB->isChecked())
        buff<<"*";

    buff<<ui->commentText->toPlainText().toStdString();

    if(ui->multiB->isChecked())
        buff<<"*/";

    codeeditor1->textCursor().insertText(QString::fromStdString(buff.str()));
    this->close();
}
