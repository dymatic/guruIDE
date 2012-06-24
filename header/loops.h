#ifndef LOOPS_H
#define LOOPS_H

#include <QMainWindow>
#include <QTextEdit>
namespace Ui {
class Loops;
}

class Loops : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Loops(QWidget *parent = 0,QTextEdit *a=0);
    ~Loops();
public slots:
    void writeLoop();
    void dwbClick();
    void forClick();
    void whileClick();
private:
    Ui::Loops *ui;
};

#endif // LOOPS_H
