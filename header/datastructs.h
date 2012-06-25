/*
  *Data structures are variables that hold
  *information. Structs, unions, and types
  *all go here.
  */


#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <QMainWindow>
#include <QTextEdit>
namespace Ui {
class dataStructs;
}

class dataStructs : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit dataStructs(QWidget *parent = 0,QTextEdit *a=0);
    ~dataStructs();
public slots:
    void handleButtons();
    void writedata();
private:
    Ui::dataStructs *ui;
};

#endif // DATASTRUCTS_H
