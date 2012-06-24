#-------------------------------------------------
#
# Project created by QtCreator 2012-06-18T19:35:20
#
#-------------------------------------------------

QT       += core gui

TARGET = ide
TEMPLATE = app


SOURCES += cpp/main.cpp\
        cpp/display.cpp \
    cpp/boilerplate.cpp \
    cpp/loops.cpp \
    cpp/functionbox.cpp \
    cpp/conditions.cpp \
    cpp/comments.cpp \
    cpp/datastructs.cpp \
    cpp/save.cpp \
    cpp/open.cpp

HEADERS  += header/display.h \
    header/boilerplate.h \
    header/loops.h \
    header/functionbox.h \
    header/conditions.h \
    header/comments.h \
    header/datastructs.h \
    header/save.h \
    header/open.h

FORMS    += form/display.ui \
   form/boilerplate.ui \
   form/loops.ui \
   form/functionbox.ui \
   form/conditions.ui \
   form/comments.ui \
   form/datastructs.ui \
   form/save.ui \
   form/open.ui
