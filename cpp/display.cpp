#include <fstream>
#include <cstdlib>
#include <iostream>

#include "header/display.h"
#include "ui_display.h"
#include "header/boilerplate.h"
#include "header/loops.h"
#include "header/functionbox.h"
#include "header/conditions.h"
#include "header/comments.h"
#include "header/datastructs.h"
#include "header/save.h"
#include "header/open.h"
#include "header/about.h"
#include "header/sctw.h"
using namespace std;
QString *openBuff=new QString("New File");
display::display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);
    this->setWindowTitle("Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/guru/guruMain.png"));

    QObject::connect(ui->bpB,SIGNAL(pressed()),this,SLOT(startBP()));
    QObject::connect(ui->loopB,SIGNAL(pressed()),this,SLOT(startLP()));
    QObject::connect(ui->fB,SIGNAL(pressed()),this,SLOT(startFP()));
    QObject::connect(ui->conditionB,SIGNAL(pressed()),this,SLOT(startCP()));
    QObject::connect(ui->commentB,SIGNAL(pressed()),this,SLOT(startDP()));
    QObject::connect(ui->dataStructs,SIGNAL(pressed()),this,SLOT(startUP()));

    QObject::connect(ui->saveButton,SIGNAL(pressed()),this,SLOT(saveF()));
    QObject::connect(ui->openButton,SIGNAL(pressed()),this,SLOT(openF()));

    QObject::connect(ui->actionBoil,SIGNAL(triggered()),this,SLOT(startBP()));
    QObject::connect(ui->actionComments,SIGNAL(triggered()),this,SLOT(startDP()));
    QObject::connect(ui->actionCondition,SIGNAL(triggered()),this,SLOT(startCP()));
    QObject::connect(ui->actionData,SIGNAL(triggered()),this,SLOT(startUP()));
    QObject::connect(ui->actionFunctions,SIGNAL(triggered()),this,SLOT(startFP()));
    QObject::connect(ui->actionLoops,SIGNAL(triggered()),this,SLOT(startLP()));

    QObject::connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openF()));
    QObject::connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveF()));
    QObject::connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(close()));

    QObject::connect(ui->actionCopy,SIGNAL(triggered()),this,SLOT(cop()));
    QObject::connect(ui->actionPaste,SIGNAL(triggered()),this,SLOT(pas()));

    //1.5 additions
    QObject::connect(ui->actionGuru,SIGNAL(triggered()),this,SLOT(startAB()));
    QObject::connect(ui->actionSCT,SIGNAL(triggered()),this,SLOT(startST()));
}

display::~display()
{
    delete ui;
}

void display::startBP(){
    boilerplate *bp=new boilerplate(this,ui->code);
    bp->show();
}

void display::startLP(){
    Loops * loopsDialog= new Loops(this,ui->code);
    loopsDialog->show();
}

void display::startFP(){
    FunctionBox *fb = new FunctionBox(this,ui->code);
    fb->show();
}

void display::startCP(){
    Conditions *cd = new Conditions(this,ui->code);
    cd->show();
}

void display::startDP(){
    Comments *cm = new Comments(this,ui->code);
    cm->show();
}

void display::startUP(){
    dataStructs *dp = new dataStructs(this,ui->code);
    dp->show();
}

void display::openF(){
    open *openEner=new open(this,ui->code,openBuff);
    openEner->show();
}

void display::saveF(){
    save *saver = new save(this,ui->code,openBuff);
    saver->show();
}

void display::cop(){
    ui->code->copy();
}

void display::pas(){
    ui->code->paste();
}

void display::startAB(){
    About *abox = new About(this);
    abox->show();
}

void display::startST(){
    sctW *sPlug = new sctW(this,ui->code);
    sPlug->show();
}
