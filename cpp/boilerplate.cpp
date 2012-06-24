#include "header/boilerplate.h"
#include "ui_boilerplate.h"
#include <QTextEdit>
#include <iostream>
#include <cstdlib>
using namespace std;
QTextEdit *codeEditor;
boilerplate::boilerplate(QWidget *parent,QTextEdit *a) :
    QMainWindow(parent),
    ui(new Ui::boilerplate)
{
    ui->setupUi(this);
    this->setWindowTitle("Boilerplate - Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/guru/guruBoiler.png"));
    codeEditor=a;
    ui->bar->setValue(0);
    QObject::connect(ui->button,SIGNAL(pressed()),this,SLOT(writeBP()));
}
QString boilerCode="/**\n*Runs the Program\n*@param argc\n*@param argv\n*/\nint main(int argc, char**argv){\n//Code here\n\nreturn 0;\n}";
boilerplate::~boilerplate()
{
    delete ui;
}
/**
  *Writes the boilerplate code to the text browser.
  */
void boilerplate::writeBP(){
    ui->bar->setValue(0);
    for(int index=0; index<101; index++)
    {
        ui->bar->setValue(index);
        usleep(1000);
    }//Just for show
    codeEditor->setText(boilerCode);
    this->close();
}
/**
  *Set the boilerplate code. Default is for C++
  *@param message - The boilerplate to write.
  */
void setBPCode(QString message){
    boilerCode=message;
}
