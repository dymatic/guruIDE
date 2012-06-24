#include "header/conditions.h"
#include "ui_conditions.h"
#include <QTextEdit>
#include <QWidgetItemV2>
#include <iostream>
#include <sstream>
#include <QStringList>
using namespace std;
QTextEdit *codeeditor;
QStringList switches;
Conditions::Conditions(QWidget *parent,QTextEdit *a) :
    QMainWindow(parent),
    ui(new Ui::Conditions)
{
    ui->setupUi(this);

    this->setWindowTitle("Conditions - Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/guru/guruCond.png"));
    codeeditor=a;

    this->ifRclick();
    ui->ifelseCondition->setVisible(false);
    QObject::connect(ui->cancelButton,SIGNAL(pressed()),this,SLOT(hide()));

    QObject::connect(ui->ifElseButton,SIGNAL(pressed()),this,SLOT(ifRclick()));
    QObject::connect(ui->elseCB,SIGNAL(pressed()),this,SLOT(elseCBClick()));
    QObject::connect(ui->conditionalButton,SIGNAL(pressed()),this,SLOT(condClick()));
    QObject::connect(ui->switchButton,SIGNAL(pressed()),this,SLOT(switchClick()));

    QObject::connect(ui->switchAddButton,SIGNAL(pressed()),this,SLOT(addCase()));
    QObject::connect(ui->okayButton,SIGNAL(pressed()),this,SLOT(writeCond()));
}

Conditions::~Conditions()
{
    delete ui;
}
void Conditions::ifRclick(){
    ui->ifCondition->setEnabled(true);
    ui->ifElseButton->setEnabled(true);
    ui->elseCB->setEnabled(true);
    ui->ifelseCondition->setEnabled(true);

    ui->conditionalButton->setChecked(false);
    ui->conditionalCond->setEnabled(false);
    ui->conditionalElse->setEnabled(false);
    ui->cond2->setEnabled(false);

    ui->switchButton->setChecked(false);
    ui->switchCase->setEnabled(false);
    ui->switchList->setEnabled(false);
    ui->switchAddButton->setEnabled(false);
    ui->switchName->setEnabled(false);
}

void Conditions::condClick(){

    ui->ifCondition->setEnabled(false);
    ui->elseCB->setEnabled(false);
    ui->ifelseCondition->setEnabled(false);

    ui->conditionalButton->setChecked(true);
    ui->conditionalCond->setEnabled(true);
    ui->conditionalElse->setEnabled(true);
    ui->cond2->setEnabled(true);

    ui->switchButton->setChecked(false);
    ui->switchCase->setEnabled(false);
    ui->switchList->setEnabled(false);
    ui->switchAddButton->setEnabled(false);
    ui->switchName->setEnabled(false);
}

void Conditions::switchClick(){
    ui->ifCondition->setEnabled(false);
    ui->elseCB->setEnabled(false);
    ui->ifelseCondition->setEnabled(false);

    ui->conditionalButton->setChecked(false);
    ui->conditionalCond->setEnabled(false);
    ui->conditionalElse->setEnabled(false);
    ui->cond2->setEnabled(false);

    ui->switchButton->setChecked(true);
    ui->switchCase->setEnabled(true);
    ui->switchList->setEnabled(true);
    ui->switchAddButton->setEnabled(true);
    ui->switchName->setEnabled(true);
}

void Conditions::elseCBClick(){
    if(ui->elseCB->isChecked())
        ui->ifelseCondition->setEnabled(true);
    else
        ui->ifelseCondition->setEnabled(false);
}

void Conditions::writeCond(){
stringstream buff;

if(ui->ifElseButton->isChecked())
{
    buff << "if("<<ui->ifCondition->text().toStdString()<<"{\n\n}";
    if(ui->elseCB->isChecked())
    {
        buff<<"else{\n\n}";
    }
}//END if

if(ui->conditionalButton->isChecked())
{
    buff<<"("<<ui->conditionalCond->text().toStdString()
       <<")?"<<ui->conditionalElse->text().toStdString()
      <<":"<<ui->cond2->text().toStdString()<<";\n\n";
}//END cond

if(ui->switchButton->isChecked())
{
    buff<<"switch("<<ui->switchName->text().toStdString()
    <<"{\n";
    for(int index=0; index<switches.length(); index++)
    {
        if(index!=0)
        buff<<"\ncase "<<switches.at(index).toStdString()
           <<":\n\nbreak;";
    }
    buff<<"}\n\n";
}//END switch
this->close();
codeeditor->textCursor().insertText(QString::fromStdString(buff.str()));
}

void Conditions::addCase(){
    ui->switchList->addItem(ui->switchCase->text());
    switches.append(ui->switchCase->text());
    ui->switchCase->setFocus();
    ui->switchCase->setText("");
}
