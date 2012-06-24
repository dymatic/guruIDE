#include "save.h"
#include "ui_save.h"
#include <QTextEdit>
using namespace std;

QTextEdit *codeEditor2;
QString *buffName;

save::save(QWidget *parent,QTextEdit *toSave,QString *fileName) :
    QMainWindow(parent),
    ui(new Ui::save)
{
    ui->setupUi(this);
    this->setWindowTitle("Save - Guru");
    this->setWindowIcon(QIcon("/usr/share/pixmaps/guru/guruSave.png"));
    codeEditor2=toSave;
    buffName=fileName;

    if(fileName->length()>1){
        ui->fileName->setText(*fileName);
        ui->fileName->selectAll();
    }
    QObject::connect(ui->saveButton,SIGNAL(pressed()),this,SLOT(saveFile()));
    QObject::connect(ui->cancelButton,SIGNAL(pressed()),this,SLOT(hide()));
}

save::~save()
{
    delete ui;
}

void save::saveFile(){
    QString *toName=new QString(ui->fileName->text());
    ofstream writer(ui->fileName->text().toStdString().c_str());

    buffName=toName;
    writer << codeEditor2->toPlainText().toStdString();

    writer.close();
    this->close();
}
