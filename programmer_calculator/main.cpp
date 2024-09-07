#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QPixmap>
#include <QFileInfo>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //QIcon icon("E:/Qt/project/programmer_calculator/programmer_calculator/picture/calculator.png");//绝对路径
    // 获取可执行文件的绝对路径
    QString exePath = QCoreApplication::applicationFilePath();
    QFileInfo exeInfo(exePath);
    // 构建图片文件的路径
    QString imagePath = exeInfo.absolutePath() + "/picture/calculator.png";
    // 检查文件是否存在
    /*
    if (!QFile::exists(imagePath)) {
        return -1;
    }*/
    // 创建一个QIcon对象并加载图片
    QIcon icon(imagePath);

    w.setWindowIcon(icon);
    w.show();
    return a.exec();

}
