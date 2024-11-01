#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <StingToolClass.h>
#include <CheckBoxClass.h>
#include <QClipboard>
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

void MainWindow::on_clear_all_page2_clicked()
{
    // 阻止其他文本框的信号
    ui->hex_textedit->blockSignals(true);
    ui->dec_textedit->blockSignals(true);
    ui->bin_textedit->blockSignals(true);
    ui->oct_textedit->blockSignals(true);
    ui->bit_reversal_textedit->blockSignals(true);
    ui->opposite_num_textedit->blockSignals(true);
    TextEditProessPage_2->ClearAll();
    // 恢复其他文本框的信号
    ui->hex_textedit->blockSignals(false);
    ui->dec_textedit->blockSignals(false);
    ui->bin_textedit->blockSignals(false);
    ui->oct_textedit->blockSignals(false);
    ui->bit_reversal_textedit->blockSignals(false);
    ui->opposite_num_textedit->blockSignals(false);
}

void MainWindow::on_hex_textedit_textChanged()
{
    ui->hex_textedit->blockSignals(true);
    ui->dec_textedit->blockSignals(true);
    ui->bin_textedit->blockSignals(true);
    ui->oct_textedit->blockSignals(true);
    ui->bit_reversal_textedit->blockSignals(true);
    ui->opposite_num_textedit->blockSignals(true);
    TextEditProessPage_2->UpdateHexText();
    TextEditProessPage_2->updateTextEditWithConvertedData();
    ui->hex_textedit->blockSignals(false);
    ui->dec_textedit->blockSignals(false);
    ui->bin_textedit->blockSignals(false);
    ui->oct_textedit->blockSignals(false);
    ui->bit_reversal_textedit->blockSignals(false);
    ui->opposite_num_textedit->blockSignals(false);
}
void MainWindow::on_dec_textedit_textChanged()
{
    ui->hex_textedit->blockSignals(true);
    ui->dec_textedit->blockSignals(true);
    ui->bin_textedit->blockSignals(true);
    ui->oct_textedit->blockSignals(true);
    ui->bit_reversal_textedit->blockSignals(true);
    ui->opposite_num_textedit->blockSignals(true);
    TextEditProessPage_2->UpdateDecText();
    TextEditProessPage_2->updateTextEditWithConvertedData();
    ui->hex_textedit->blockSignals(false);
    ui->dec_textedit->blockSignals(false);
    ui->bin_textedit->blockSignals(false);
    ui->oct_textedit->blockSignals(false);
    ui->bit_reversal_textedit->blockSignals(false);
    ui->opposite_num_textedit->blockSignals(false);

}

void MainWindow::on_bin_textedit_textChanged()
{
    ui->hex_textedit->blockSignals(true);
    ui->dec_textedit->blockSignals(true);
    ui->bin_textedit->blockSignals(true);
    ui->oct_textedit->blockSignals(true);
    ui->bit_reversal_textedit->blockSignals(true);
    ui->opposite_num_textedit->blockSignals(true);
    TextEditProessPage_2->UpdateBinText();
    TextEditProessPage_2->updateTextEditWithConvertedData();
    ui->hex_textedit->blockSignals(false);
    ui->dec_textedit->blockSignals(false);
    ui->bin_textedit->blockSignals(false);
    ui->oct_textedit->blockSignals(false);
    ui->bit_reversal_textedit->blockSignals(false);
    ui->opposite_num_textedit->blockSignals(false);
}

void MainWindow::on_oct_textedit_textChanged()
{
    ui->hex_textedit->blockSignals(true);
    ui->dec_textedit->blockSignals(true);
    ui->bin_textedit->blockSignals(true);
    ui->oct_textedit->blockSignals(true);
    ui->bit_reversal_textedit->blockSignals(true);
    ui->opposite_num_textedit->blockSignals(true);
    TextEditProessPage_2->UpdateOctText();
    TextEditProessPage_2->updateTextEditWithConvertedData();
    ui->hex_textedit->blockSignals(false);
    ui->dec_textedit->blockSignals(false);
    ui->bin_textedit->blockSignals(false);
    ui->oct_textedit->blockSignals(false);
    ui->bit_reversal_textedit->blockSignals(false);
    ui->opposite_num_textedit->blockSignals(false);

}

void MainWindow::on_set_uppercase_clicked()
{
    TextEditProessPage_1->StingToUpper();
}

void MainWindow::on_set_lowercase_clicked()
{
    TextEditProessPage_1->StingToLower();
}

void MainWindow::on_copy_all_page1_clicked()
{
    // 获取QTextBrowser中的文本
        QString text = ui->output_page_1->toPlainText(); // 如果你想要复制所有的文本

        // 获取系统剪贴板
        QClipboard *clipboard = QApplication::clipboard();

        // 将文本复制到剪贴板
        clipboard->setText(text);
}
