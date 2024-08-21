#include <BaseConversionClass.h>
#include <QTextEdit>
#include <QString>

BaseConversionClass::BaseConversionClass(QTextEdit *HexTextEdit,
                             QTextEdit *DecTextEdit,
                             QTextEdit *BinTextEdit,
                             QTextEdit *OctTextEdit,
                             QTextEdit *BitReversalTextEdit,
                             QTextEdit *OppositeNumTextEdit)
                   : HexTextEdit(HexTextEdit),
                     DecTextEdit(DecTextEdit),
                     BinTextEdit(BinTextEdit),
                     OctTextEdit(OctTextEdit),
                     BitReversalTextEdit(BitReversalTextEdit),
                     OppositeNumTextEdit(OppositeNumTextEdit),
                     TextEditData()
{
    TextEditData.insert("hex", "");
    TextEditData.insert("dec", "");
    TextEditData.insert("bin", "");
    TextEditData.insert("oct", "");
    TextEditData.insert("bit_reversal", "");
    TextEditData.insert("opposite_num", "");

}
BaseConversionClass::~BaseConversionClass()
{
}
// Implement functions to update data in the internal map
void BaseConversionClass::UpdateHexText()
{
    TextEditData["hex"] = HexTextEdit->toPlainText();
}

void BaseConversionClass::UpdateDecText()
{
    TextEditData["dec"] = DecTextEdit->toPlainText();
}

void BaseConversionClass::UpdateBinText()
{
    TextEditData["bin"] = BinTextEdit->toPlainText();
}

void BaseConversionClass::UpdateOctText()
{
    TextEditData["oct"] = OctTextEdit->toPlainText();
}

void BaseConversionClass::UpdateBitReversalText()
{
    TextEditData["bit_reversal"] = BitReversalTextEdit->toPlainText();
}

void BaseConversionClass::UpdateOppositeNumText()
{
    TextEditData["opposite_num"] = OppositeNumTextEdit->toPlainText();
}
// 清空所有输入框
void BaseConversionClass::ClearAll()
{
    // Clear the data map
    TextEditData["hex"].clear();
    TextEditData["dec"].clear();
    TextEditData["bin"].clear();
    TextEditData["oct"].clear();
    TextEditData["bit_reversal"].clear();
    TextEditData["opposite_num"].clear();

    HexTextEdit->clear();
    DecTextEdit->clear();
    BinTextEdit->clear();
    OctTextEdit->clear();
    BitReversalTextEdit->clear();
    OppositeNumTextEdit->clear();
}


void BaseConversionClass::updateTextEditWithConvertedData()
{
    HexTextEdit->setText(TextEditData["hex"]);
    DecTextEdit->setText(TextEditData["dec"]);
    BinTextEdit->setText(TextEditData["bin"]);
    OctTextEdit->setText(TextEditData["oct"]);
    BitReversalTextEdit->setText(TextEditData["bit_reversal"]);
    OppositeNumTextEdit->setText(TextEditData["opposite_num"]);
}
