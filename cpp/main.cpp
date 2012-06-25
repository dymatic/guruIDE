#include <QtGui/QApplication>
#include "header/display.h"
#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    if(argc>1){
    if(!strcmp(argv[1],"-v"))
        cout << "1.5.0"<<endl;

    if(!strcmp(argv[1],"-a"))
        cout << "dymatic"<<endl;

    if(!strcmp(argv[1],"-o"))
        cout << "Noran Software"<<endl;
}
    QApplication a(argc, argv);
    display w;
    w.show();
    
    return a.exec();
}
