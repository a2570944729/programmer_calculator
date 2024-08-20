#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon("E:/Qt/project/programmer_calculator/programmer_calculator/picture/calculator.png");
    w.setWindowIcon(icon);
    w.show();
    return a.exec();
}
