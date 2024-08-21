#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <StingToolClass.h>
#include <CheckBoxClass.h>
#include <BaseConversionClass.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TextEditProessPage_1 = new StingToolClass(ui->input_page_1, ui->output_page_1);
    Check_box_add_prefix = new CheckBoxClass(ui->add_0x_prefix);
    Check_box_add_space = new CheckBoxClass(ui->add_space);
    TextEditProessPage_2 = new BaseConversionClass(ui->hex_textedit,ui->dec_textedit,ui->bin_textedit,ui->oct_textedit,ui->bit_reversal_textedit,ui->opposite_num_textedit);
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

void MainWindow::on_clear_all_page1_clicked()
{
     TextEditProessPage_1->ClearAllTextEdit();
}
