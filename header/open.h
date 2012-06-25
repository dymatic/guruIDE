/*
  *Load a file into the text editor.
  */

#ifndef OPEN_H
#define OPEN_H

#include <QMainWindow>
#include <QTextEdit>
using namespace std;
namespace Ui {
class open;
}

class open : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit open(QWidget *parent = 0,QTextEdit *a=0,QString *oB=0);
    ~open();
public slots:
    void openFile();
    void setFile(std::string);
private:
    Ui::open *ui;
};

#endif // OPEN_H
