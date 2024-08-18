#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <TextEditClass.h>
#include <CheckBoxClass.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hex_to_string_clicked();

    void on_clear_all_clicked();

    void on_string_to_tab_clicked();

    void on_get_sting_len_clicked();

    void on_get_byte_len_clicked();

private:
    Ui::MainWindow *ui;
    /*********第一个功能页对象***********/
    TextEditClass *TextEditProessPage_1;  // 输入输出框的处理流程
    CheckBoxClass *Check_box_add_prefix;  //前缀标识符
    CheckBoxClass *Check_box_add_space;   //空格标识符

    /**********************************/

};
#endif // MAINWINDOW_H