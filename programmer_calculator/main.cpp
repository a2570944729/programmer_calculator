#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QPixmap>
#include <QFileInfo>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // 设置应用程序图标
    a.setWindowIcon(QIcon(":/icon/AppIcon/app.ico"));

    w.show();
    return a.exec();

}
