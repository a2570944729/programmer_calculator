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
                     ComplementNumTextEdit(OppositeNumTextEdit),
                     TextEditData()
{
    BitReversalTextEdit->setReadOnly(true);
    OppositeNumTextEdit->setReadOnly(true);
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
void BaseConversionClass::UpdateHexText()
{
    TextEditData["hex"] = HexTextEdit->toPlainText();
    onTextChanged(TextEditData["hex"], "hex");
}

void BaseConversionClass::UpdateDecText()
{
    TextEditData["dec"] = DecTextEdit->toPlainText();
    onTextChanged(TextEditData["dec"], "dec");
}

void BaseConversionClass::UpdateBinText()
{
    TextEditData["bin"] = BinTextEdit->toPlainText();
    onTextChanged(TextEditData["bin"], "bin");
}

void BaseConversionClass::UpdateOctText()
{
    TextEditData["oct"] = OctTextEdit->toPlainText();
    onTextChanged(TextEditData["oct"], "oct");
}

void BaseConversionClass::UpdateBitReversalText()
{
    TextEditData["bit_reversal"] = BitReversalTextEdit->toPlainText();
    onTextChanged(TextEditData["bit_reversal"], "bit_reversal"); // 这里可能不需要转换
}

void BaseConversionClass::UpdateComplementNumText()
{
    TextEditData["opposite_num"] = ComplementNumTextEdit->toPlainText();
    onTextChanged(TextEditData["opposite_num"], "opposite_num"); // 这里可能不需要转换
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
   ComplementNumTextEdit->clear();
}


void BaseConversionClass::updateTextEditWithConvertedData()
{
    HexTextEdit->setText(TextEditData["hex"]);
    HexTextEdit->moveCursor(QTextCursor::End);

    DecTextEdit->setText(TextEditData["dec"]);
    DecTextEdit->moveCursor(QTextCursor::End);

    BinTextEdit->setText(TextEditData["bin"]);
    BinTextEdit->moveCursor(QTextCursor::End);

    OctTextEdit->setText(TextEditData["oct"]);
    OctTextEdit->moveCursor(QTextCursor::End);

    BitReversalTextEdit->setText(TextEditData["bit_reversal"]);
    BitReversalTextEdit->moveCursor(QTextCursor::End);

    ComplementNumTextEdit->setText(TextEditData["opposite_num"]);
    ComplementNumTextEdit->moveCursor(QTextCursor::End);
}

void BaseConversionClass::onTextChanged(const QString &text, const QString &baseType)
{
    // 获取进制
    int base = 0;
    if (baseType == "hex") base = 16;
    else if (baseType == "dec") base = 10;
    else if (baseType == "bin") base = 2;
    else if (baseType == "oct") base = 8;

    // 尝试转换
    bool ok;
    long value = text.toLong(&ok, base);
    if (ok)
    {
        TextEditData[baseType] = text;
        // 更新其他进制
        TextEditData["hex"] = QString::number(value, 16).toUpper();
        TextEditData["dec"] = QString::number(value, 10);
        TextEditData["bin"] = QString::number(value, 2);
        TextEditData["oct"] = QString::number(value, 8);
        TextEditData["bit_reversal"] = invertBits(TextEditData["bin"]); // 按位取反
        TextEditData["opposite_num"] = invertBits(TextEditData["bin"])+0b1;

        // 更新UI
        updateTextEditWithConvertedData();
    } else {
        // 如果转换失败，清空所有文本框
        ClearAll();
    }
}

// 新增按位取反函数
QString BaseConversionClass::invertBits(const QString &binaryString)
{
    // 确定位宽
    int bitWidth = binaryString.length(); // 位宽等于输入二进制字符串的长度

    // 创建一个足够大的无符号整数来容纳位反转后的结果
    unsigned long result = 0;

    // 位反转
    for (int i = 0; i < bitWidth; ++i) {
        // 取出当前位
        bool bit = (binaryString[i] == '1');

        // 取反
        bool invertedBit = !bit;

        // 将取反后的位放入结果中
        result |= (invertedBit << (bitWidth - 1 - i));
    }

    // 将结果转换为字符串
    QString invertedBinary = QString::number(result, 2);

    // 保留位宽
    invertedBinary = invertedBinary.rightJustified(bitWidth, '0');

    return invertedBinary;
}

// 新增补码函数
QString BaseConversionClass::ComplementNum(const QString &binaryString)
{
    // 确定位宽
    int bitWidth = binaryString.length(); // 位宽等于输入二进制字符串的长度

    // 创建一个足够大的无符号整数来容纳位反转后的结果
    unsigned long result = 0;

    // 位反转
    for (int i = 0; i < bitWidth; ++i) {
        // 取出当前位
        bool bit = (binaryString[i] == '1');

        // 取反
        bool invertedBit = !bit;

        // 将取反后的位放入结果中
        result |= (invertedBit << (bitWidth - 1 - i));

    }

    // 将结果转换为字符串
    QString invertedBinary = QString::number(result, 2);

    // 保留位宽
    invertedBinary = invertedBinary.rightJustified(bitWidth, '0');

    return invertedBinary;
}
