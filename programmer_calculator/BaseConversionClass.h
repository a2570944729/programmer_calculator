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
                                 QTextEdit *OppositeNumTextEdit);
    ~BaseConversionClass();
    void ClearAll();
    void UpdateHexText();
    void UpdateDecText();
    void UpdateBinText();
    void UpdateOctText();
    void UpdateBitReversalText();
    void UpdateOppositeNumText();
    void updateTextEditWithConvertedData(); // Slot to update the text edits with the data

private:
    QTextEdit *HexTextEdit;
    QTextEdit *DecTextEdit;
    QTextEdit *BinTextEdit;
    QTextEdit *OctTextEdit;
    QTextEdit *BitReversalTextEdit;
    QTextEdit *OppositeNumTextEdit;

    QMap<QString, QString> TextEditData;
};



#endif // BASECONVERSIONCLASS_H
