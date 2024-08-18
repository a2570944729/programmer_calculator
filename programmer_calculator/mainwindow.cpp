#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <TextEditClass.h>
#include <CheckBoxClass.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TextEditProessPage_1 = new TextEditClass(ui->input_page_1, ui->output_page_1);
     Check_box_add_prefix = new CheckBoxClass(ui->add_0x_prefix);
     Check_box_add_space = new CheckBoxClass(ui->add_space);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete TextEditProessPage_1;  // 删除TextEditWork对象
}


void MainWindow::on_hex_to_string_clicked()
{
    if(Check_box_add_prefix->GetAddFlag())
    {
        // 获取输入框中的文本并转换为十六进制，打印到输出框
        TextEditProessPage_1->StingToHexHavePrefix();
    }
    else
    {
        TextEditProessPage_1->StingToHexNoPrefix();
    }

}

void MainWindow::on_clear_all_clicked()
{
    TextEditProessPage_1->ClearAllTextEdit();
}

void MainWindow::on_string_to_tab_clicked()
{
    if(Check_box_add_space->GetAddFlag())
    {
        TextEditProessPage_1->HexToStingHaveSpace();
    }
   else
    {
       TextEditProessPage_1->HexToStingNoSpace();
    }
}

void MainWindow::on_get_sting_len_clicked()
{
    TextEditProessPage_1->GetStingLen();
}

void MainWindow::on_get_byte_len_clicked()
{
    TextEditProessPage_1->GetByteLen();
}