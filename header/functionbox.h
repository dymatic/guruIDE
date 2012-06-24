#ifndef FUNCTIONBOX_H
#define FUNCTIONBOX_H

#include <QMainWindow>
#include <QTextEdit>
namespace Ui {
class FunctionBox;
}

class FunctionBox : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FunctionBox(QWidget *parent = 0,QTextEdit *a=0);
    ~FunctionBox();
public slots:
    void writeFun();
    void cClick();
    void dClick();
    void fClick();
    void iClick();
    void vClick();
    void determine();
private:
    Ui::FunctionBox *ui;
};

#endif // FUNCTIONBOX_H
