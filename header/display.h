#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>

namespace Ui {
class display;
}

class display : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit display(QWidget *parent = 0);
    ~display();
public slots:
    void startBP();
    void startLP();
    void startFP();
    void startCP();
    void startDP();
    void startUP();

    void saveF();
    void openF();

    void cop();
    void pas();
private:
    Ui::display *ui;
};

#endif // DISPLAY_H
