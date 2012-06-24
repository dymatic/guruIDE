#include "loops.h"
#include "ui_loops.h"
#include <sstream>
#include <iostream>
#include <QTextCursor>
using namespace std;
QTextEdit *codeBrowser;
Loops::Loops(QWidget *parent,QTextEdit *a) :
    QMainWindow(parent),
    ui(new Ui::Loops)
{
    ui->setupUi(this);
    ui->forB->setChecked(true);
    codeBrowser=a;
    this->setWindowTitle("Loops - Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/guru/guruLoop.png"));
    QObject::connect(ui->accept,SIGNAL(pressed()),this,SLOT(writeLoop()));
    QObject::connect(ui->cancel,SIGNAL(pressed()),this,SLOT(hide()));

    QObject::connect(ui->forB,SIGNAL(pressed()),this,SLOT(forClick()));
    QObject::connect(ui->whileB,SIGNAL(pressed()),this,SLOT(whileClick()));
    QObject::connect(ui->dwB,SIGNAL(pressed()),this,SLOT(dwbClick()));
}


Loops::~Loops()
{
    delete ui;
}
/**
  *Writes the loop, condition, or counter.
  *Conditions override conditions.
  */
void Loops::writeLoop(){
    /*This needs some work. Add whether you want ++ and -- to fors. Also, determine if you want < > >= or <= with counters*/
    stringstream loopMsg;
    if(ui->condBox->text().length()>1)
    {
        if(ui->forB->isChecked())
        {
            loopMsg<<"for(int index=0;";
            loopMsg<<ui->condBox->text().toStdString()<<";";
            loopMsg<<"index++){\n\n}";
        }

        if(ui->dwB->isChecked())
        {
            loopMsg<<"do{\n\n}while(";
            loopMsg<<ui->condBox->text().toStdString();
            loopMsg<<");//END DO";
        }

        if(ui->whileB->isChecked())
        {
            loopMsg<<"while("<<ui->condBox->text().toStdString()<<"){\n\n}//END WHILE";
        }
    }//END non-counter box if
    else
    {
        if(ui->forB->isChecked())
        {
            loopMsg<<"for(int index=0; index<"<<ui->sBox->value()<<"; index++){\n\n}//END FOR";//ADD MORE POSSIBILITIES LATER, SUCH AS < > >=<= with enabled buttons
        }
    }//END non-counter box else
    QTextCursor *qtc=new QTextCursor(codeBrowser->textCursor());
    qtc->insertText(QString::fromStdString(loopMsg.str()));
    this->close();
}

void Loops::dwbClick(){
ui->forB->setChecked(false);
ui->whileB->setChecked(false);
ui->sBox->setEnabled(false);
}

void Loops::forClick(){
    ui->dwB->setChecked(false);
    ui->whileB->setChecked(false);
    ui->sBox->setEnabled(true);
}

void Loops::whileClick(){
    ui->dwB->setChecked(false);
    ui->forB->setChecked(false);
    ui->sBox->setEnabled(false);
}
