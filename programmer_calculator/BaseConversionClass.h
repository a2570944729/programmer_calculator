#ifndef BASECONVERSIONCLASS_H
#define BASECONVERSIONCLASS_H
#include <QString>
#include <QTextEdit>

class BaseConversionClass : public QObject {
public:
    explicit BaseConversionClass(QTextEdit *HexTextEdit,
                                 QTextEdit *DecTextEdit,
                                 QTextEdit *BinTextEdit,
                                 QTextEdit *OctTextEdit,
                                 QTextEdit *BitReversalTextEdit,
                                 QTextEdit *ComplementNumTextEdit);
    ~BaseConversionClass();
    void ClearAll();
    void UpdateHexText();
    void UpdateDecText();
    void UpdateBinText();
    void UpdateOctText();
    void UpdateBitReversalText();
    void UpdateComplementNumText();
    void updateTextEditWithConvertedData(); // Slot to update the text edits with the data

private:
    QTextEdit *HexTextEdit;
    QTextEdit *DecTextEdit;
    QTextEdit *BinTextEdit;
    QTextEdit *OctTextEdit;
    QTextEdit *BitReversalTextEdit;
    QTextEdit *ComplementNumTextEdit;

    QMap<QString, QString> TextEditData;
    void onTextChanged(const QString &text, const QString &baseType);
    void invertBits(long value);
    QString invertBits(const QString &binaryString);
    QString formatBinary(const QString &binaryString, bool isBinaryInput);
    QString ComplementNum(const QString &binaryString);
    QString formatBinaryString(const QString &binaryString);
};



#endif // BASECONVERSIONCLASS_H
