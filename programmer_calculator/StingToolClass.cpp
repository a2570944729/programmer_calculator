#include <QTextEdit>
#include <QString>
#include <QByteArray>
#include <StingToolClass.h>

StingToolClass::StingToolClass(QTextEdit *inputTextEdit, QTextEdit *outputTextEdit) :  InputTextEdit(inputTextEdit),OutputTextEdit(outputTextEdit)
{
}

StingToolClass::~StingToolClass()
{
}
/*********************************************************************************************************
函数名称：GetStingLen
功能描述：获取字符串长度
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.08.18
备    注：
*********************************************************************************************************/
void StingToolClass::GetStingLen()const
{
    QString text = InputTextEdit->toPlainText();  // 获取输入QTextEdit中的文本
    int length = text.length();  // 获取字符串长度

    // 将长度转换为字符串并输出到输出QTextEdit
    OutputTextEdit->setText(QString::number(length));

}
/*********************************************************************************************************
函数名称：GetByteLen
功能描述：获取字节串长度，按空格区分每个字节
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.08.18
备    注：
*********************************************************************************************************/
void StingToolClass::GetByteLen()const
{
    QString text = InputTextEdit->toPlainText();  // 获取输入QTextEdit中的文本

    // 分割字符串，每个十六进制数以空格分隔
    QStringList hexNumbers = text.split(' ');

    // 计算十六进制数的数量，即字节数量
    int byteCount = hexNumbers.count();

    // 将字节数量转换为字符串并输出到输出QTextEdit
    OutputTextEdit->setText(QString::number(byteCount));
}
/*********************************************************************************************************
函数名称：StingToHexNoPrefix
功能描述：字符串转十六进制数
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.08.18
备    注：输出的十六进制数无前缀
*********************************************************************************************************/
void StingToolClass:: StingToHexNoPrefix() const
{
    QString text = InputTextEdit->toPlainText();  // 获取输入QTextEdit中的文本
    QByteArray byteArray = text.toUtf8();  // 将QString转换为QByteArray

    QString hexString;
    for (int i = 0; i < byteArray.size(); ++i)
    {
        if (i > 0)
            hexString += ' ';  // 每个字节之间添加空格
        hexString += QString("%1").arg(byteArray[i], 2, 16, QChar('0'));  // 转换为十六进制
    }
    OutputTextEdit->setText(hexString);
}
/*********************************************************************************************************
函数名称：StingToHexHavePrefix
功能描述：字符串转十六进制数
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.08.18
备    注：输出的十六进制数有前缀
*********************************************************************************************************/
void StingToolClass::StingToHexHavePrefix () const
{
    QString text = InputTextEdit->toPlainText();  // 获取输入QTextEdit中的文本
    QByteArray byteArray = text.toUtf8();  // 将QString转换为QByteArray

    QString hexString;
    for (int i = 0; i < byteArray.size(); ++i)
    {
        if (i > 0)
            hexString += ' ';  // 每个字节之间添加空格

        // 为每个十六进制数添加0x前缀
        hexString += "0x";
        hexString += QString("%1").arg(byteArray[i], 2, 16, QChar('0'));  // 转换为十六进制
    }
    OutputTextEdit->setText(hexString);  // 将十六进制字符串写入到输出QTextEdit
}
/*********************************************************************************************************
函数名称：ClearAllTextEdit
功能描述：清楚所有对话框的内容
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.08.18
备    注：无
*********************************************************************************************************/
void StingToolClass::ClearAllTextEdit() const
{
    InputTextEdit->clear();  // 清空输入QTextEdit
    OutputTextEdit->clear();  // 清空输出QTextEdit
}

/*********************************************************************************************************
函数名称：HexToStingNoSpace
功能描述：十六进制数转字符串（0x前缀可自动识别）
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.08.18
备    注：输出的字符串无间隔
*********************************************************************************************************/
void StingToolClass::HexToStingNoSpace() const
{
    // 获取输入文本
    QString inputText = InputTextEdit->toPlainText();
    // 按照空格分割字符串
    QStringList hexStrings = inputText.split(' ');
    // 处理每一个十六进制字符串，并将其转换为字符
    QString outputText;
    for (const QString &hexStr : hexStrings) {
        if (!hexStr.isEmpty()) {
            // 移除可能的 "0x" 前缀
            QString hex = hexStr.startsWith("0x") ? hexStr.mid(2) : hexStr;
            // 转换十六进制字符串为整数
            int value = hex.toInt(nullptr, 16);
            // 将整数转换为字符
            outputText += QChar(value);
        }
    }
    // 设置输出文本
    OutputTextEdit->setText(outputText);
}
/*********************************************************************************************************
函数名称：
功能描述：十六进制数转字符串（0x前缀可自动识别）
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.08.18
备    注：输出的字符串有间隔
*********************************************************************************************************/
void StingToolClass::HexToStingHaveSpace() const
{
    // 获取输入文本
    QString inputText = InputTextEdit->toPlainText();
    // 按照空格分割字符串
    QStringList hexStrings = inputText.split(' ');
    // 处理每一个十六进制字符串，并将其转换为字符
    QString outputText;
    for (const QString &hexStr : hexStrings)
    {
        if (!hexStr.isEmpty())
        {
            // 移除可能的 "0x" 前缀
            QString hex = hexStr.startsWith("0x") ? hexStr.mid(2) : hexStr;
            // 转换十六进制字符串为整数
            int value = hex.toInt(nullptr, 16);
            // 将整数转换为字符
            outputText += QChar(value);
            // 添加空格，但最后一个字符后面不加空格
            if (&hexStr != &hexStrings.last())//这里需要&才能正常进入，否则需要在输入时的最后加空格
            {
                outputText += ' ';
            }
        }
    }
    // 设置输出文本
    OutputTextEdit->setText(outputText);
}

/*********************************************************************************************************
函数名称：StingToUpper
功能描述：字符串转大写
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.09.07
备    注：将输入的英文字符串转换为全大写形式
*********************************************************************************************************/
void StingToolClass::StingToUpper() const
{
    QString text = InputTextEdit->toPlainText();  // 获取输入QTextEdit中的文本
    QString upperText = text.toUpper();  // 转换为大写

    OutputTextEdit->setText(upperText);  // 将大写字符串写入到输出QTextEdit
}

/*********************************************************************************************************
函数名称：StingToLower
功能描述：字符串转小写
输入参数：无
返 回 值：无
作    者：LinPeiFeng
日    期：2024.09.07
备    注：将输入的英文字符串转换为全小写形式
*********************************************************************************************************/
void StingToolClass::StingToLower() const
{
    QString text = InputTextEdit->toPlainText();  // 获取输入QTextEdit中的文本
    QString lowerText = text.toLower();  // 转换为小写

    OutputTextEdit->setText(lowerText);  // 将小写字符串写入到输出QTextEdit
}
