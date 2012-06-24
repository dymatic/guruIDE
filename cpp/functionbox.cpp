#include "functionbox.h"
#include "ui_functionbox.h"
#include <iostream>
#include <sstream>
#include <QTextBrowser>
using namespace std;
QTextEdit *editor;
FunctionBox::FunctionBox(QWidget *parent,QTextEdit *a) :
    QMainWindow(parent),
    ui(new Ui::FunctionBox)
{
    ui->setupUi(this);
    editor=a;
    ui->voidButton->setChecked(true);
    this->setWindowTitle("Functions - Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/guru/guruFunc.png"));
    QObject::connect(ui->cancelButton,SIGNAL(pressed()),this,SLOT(hide()));
    QObject::connect(ui->okayButton,SIGNAL(pressed()),this,SLOT(writeFun()));

    QObject::connect(ui->charButton,SIGNAL(pressed()),this,SLOT(cClick()));
    QObject::connect(ui->doubleButton,SIGNAL(pressed()),this,SLOT(dClick()));
    QObject::connect(ui->floatButton,SIGNAL(pressed()),this,SLOT(fClick()));
    QObject::connect(ui->intButton,SIGNAL(pressed()),this,SLOT(iClick()));
    QObject::connect(ui->voidButton,SIGNAL(pressed()),this,SLOT(vClick()));

}

FunctionBox::~FunctionBox()
{
    delete ui;
}
QString type="";
void FunctionBox::determine(){

    if(ui->charButton->isChecked())
        type="char";
    else if(ui->doubleButton->isChecked())
        type="double";
    else if(ui->floatButton->isChecked())
        type="float";
    else if(ui->intButton->isChecked())
        type="int";
    else if(ui->voidButton->isChecked())
        type="void";
}

/**
  *Writes the function to the editor
  */
void FunctionBox::writeFun(){
    stringstream buff;
    determine();

    buff << "/**\n*"<<ui->nameLine->text().toStdString()<<"\n*";

    if(ui->paramLine->text().length()>1)
        buff << "@param "<<ui->paramLine->text().toStdString()<<"\n";
    buff <<"**/\n";
    buff <<type.toStdString()<<" "<<ui->nameLine->text().toStdString()<<"("<<ui->paramLine->text().toStdString()<<"){\n\n}\n";
    editor->textCursor().insertText(QString::fromStdString(buff.str()));
    this->close();
}

void FunctionBox::vClick(){
    ui->charButton->setChecked(false);
    ui->doubleButton->setChecked(false);
    ui->floatButton->setChecked(false);
    ui->intButton->setChecked(false);
}

void FunctionBox::cClick(){
    ui->voidButton->setChecked(false);
    ui->doubleButton->setChecked(false);
    ui->floatButton->setChecked(false);
    ui->intButton->setChecked(false);
}

void FunctionBox::dClick(){
    ui->voidButton->setChecked(false);
    ui->charButton->setChecked(false);
    ui->floatButton->setChecked(false);
    ui->intButton->setChecked(false);
}

void FunctionBox::iClick(){
    ui->voidButton->setChecked(false);
    ui->charButton->setChecked(false);
    ui->floatButton->setChecked(false);
    ui->doubleButton->setChecked(false);
}

void FunctionBox::fClick(){
    ui->voidButton->setChecked(false);
    ui->charButton->setChecked(false);
    ui->intButton->setChecked(false);
    ui->doubleButton->setChecked(false);
}
