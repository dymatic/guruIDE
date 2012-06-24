#include "datastructs.h"
#include "ui_datastructs.h"
#include <QTextEdit>
#include <iostream>
#include <sstream>
using namespace std;
QTextEdit *codeEdit0;
dataStructs::dataStructs(QWidget *parent,QTextEdit*a) :
    QMainWindow(parent),
    ui(new Ui::dataStructs)
{
    ui->setupUi(this);
    codeEdit0=a;
    this->setWindowTitle("Data - Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/dataStruct.png"));
    QObject::connect(ui->cancelButton,SIGNAL(pressed()),this,SLOT(hide()));

    QObject::connect(ui->intB,SIGNAL(pressed()),this,SLOT(handleButtons()));
    QObject::connect(ui->doubleB,SIGNAL(pressed()),this,SLOT(handleButtons()));
    QObject::connect(ui->floatB,SIGNAL(pressed()),this,SLOT(handleButtons()));
    QObject::connect(ui->charB,SIGNAL(pressed()),this,SLOT(handleButtons()));
    QObject::connect(ui->structB,SIGNAL(pressed()),this,SLOT(handleButtons()));
    QObject::connect(ui->unionB,SIGNAL(pressed()),this,SLOT(handleButtons()));
    QObject::connect(ui->classB,SIGNAL(pressed()),this,SLOT(handleButtons()));

    QObject::connect(ui->okayButton,SIGNAL(pressed()),this,SLOT(writedata()));
}

dataStructs::~dataStructs()
{
    delete ui;
}

void dataStructs::handleButtons(){
    if(ui->structB->isChecked()||ui->unionB->isChecked()||ui->classB->isChecked()){
        ui->arrayC->setEnabled(false);
        ui->arrayC->setChecked(false);
        ui->valueField->setText("");
        ui->valueField->setEnabled(false);
        ui->arrayMem->setEnabled(false);
    }else
    {
        ui->arrayC->setEnabled(true);
        ui->valueField->setEnabled(true);
        ui->arrayMem->setEnabled(true);
    }
    if(ui->arrayC->isChecked())
        ui->valueField->setEnabled(false);
    else
        ui->valueField->setEnabled(true);
}

void dataStructs::writedata(){
    stringstream buff;
    if(!ui->structB->isChecked()||!ui->unionB->isChecked()||!ui->classB->isChecked()){

    if(ui->intB->isChecked())
        buff<<"int ";
    if(ui->charB->isChecked())
        buff<<"char ";
    if(ui->doubleB->isChecked())
        buff<<"double ";
    if(ui->floatB->isChecked())
        buff<<"float ";
    if(ui->pointerB->isChecked())
        buff<<"*";
    buff<<ui->nameField->text().toStdString();

    if(ui->arrayC->isChecked())
        buff<<"["<<ui->arrayMem->value()<<"];";
    else
        buff<<"="<<ui->valueField->text().toStdString()<<";";
    }else
    {
        if(ui->structB->isChecked())
            buff<<"struct ";
        if(ui->unionB->isChecked())
            buff<<"union ";
        if(ui->classB->isChecked())
            buff<<"class ";

        buff<<ui->nameField->text().toStdString();
        buff<<"{\n\n"<<ui->nameField->text().toStdString()<<"(){\n\n}\n}";

        if(!ui->classB->isChecked())
            buff<<";";
    }//END struct else
    codeEdit0->textCursor().insertText(QString::fromStdString(buff.str()));
    this->close();
}
