/*
  *Save the text to a file.
  *This will overwrite any other file
  *without asking.
  */

#ifndef SAVE_H
#define SAVE_H

#include <QMainWindow>
#include <QTextEdit>
#include <fstream>
namespace Ui {
class save;
}

class save : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit save(QWidget *parent = 0,QTextEdit *a=0, QString *name=0);
    ~save();

public slots:
   void saveFile();
private:
    Ui::save *ui;
};

#endif // SAVE_H
