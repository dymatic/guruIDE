#ifndef CONDITIONS_H
#define CONDITIONS_H

#include <QMainWindow>
#include <QTextEdit>
namespace Ui {
class Conditions;
}

class Conditions : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conditions(QWidget *parent = 0,QTextEdit *a=0);
    ~Conditions();
public slots:
    void ifRclick();
    void elseCBClick();

    void condClick();

    void switchClick();
    void addCase();

    void writeCond();
private:
    Ui::Conditions *ui;
};

#endif // CONDITIONS_H
