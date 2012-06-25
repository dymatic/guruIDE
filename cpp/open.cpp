#include "header/open.h"
#include "ui_open.h"
#include "header/nsl.h"
#include <QTextEdit>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
QTextEdit *openEditor;
QString *buffName2;
open::open(QWidget *parent,QTextEdit *edit,QString *ob) :
    QMainWindow(parent),
    ui(new Ui::open)
{
    ui->setupUi(this);
    this->setWindowTitle("Open - Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/guru/guruOpen.png"));
    openEditor=edit;
    buffName2=ob;

    QObject::connect(ui->cancelButton,SIGNAL(pressed()),this,SLOT(hide()));
    QObject::connect(ui->saveButton,SIGNAL(pressed()),this,SLOT(openFile()));
}

open::~open()
{
    delete ui;
}

void open::openFile(){
    stringstream buff;
    string buffer;
    nsl fileWorker;

    ifstream reader(ui->fileName->text().toStdString().c_str());

    for(int index=0; index<fileWorker.linec(ui->fileName->text().toStdString()); index++){
        getline(reader,buffer);
        buff<<buffer<<endl;
    }
    openEditor->setText(QString::fromStdString(buff.str()));
    QString *toNameto=new QString(ui->fileName->text());
    cout << toNameto->toStdString();
    buffName2=toNameto;
    this->close();
}

void open::setFile(string name)
{
    ui->fileName->setText(QString::fromStdString(name));
}
