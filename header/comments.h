/*
  *Comments generates comments like the one you
  *are reading right now.
  */
#ifndef COMMENTS_H
#define COMMENTS_H

#include <QMainWindow>
#include <QTextEdit>
namespace Ui {
class Comments;
}

class Comments : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Comments(QWidget *parent = 0,QTextEdit *a=0);
    ~Comments();
    
private:
    Ui::Comments *ui;
public slots:
    void writeComment();//Write comment to text editor
    void writePmet();  //Write @param doc
    void writeMail(); //Write @return doc
};

#endif // COMMENTS_H
