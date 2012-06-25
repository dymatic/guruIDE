/*
  *Boilerplate is a ui that generates and writes
  *skeleton code.
  */


#ifndef BOILERPLATE_H
#define BOILERPLATE_H

#include <QMainWindow>
#include <QTextEdit>
namespace Ui {
class boilerplate;
}

class boilerplate : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit boilerplate(QWidget *parent = 0,QTextEdit *a=0);
    ~boilerplate();
public slots:
    void writeBP();//Write BP to text editor
private:
    Ui::boilerplate *ui;
};

#endif // BOILERPLATE_H
