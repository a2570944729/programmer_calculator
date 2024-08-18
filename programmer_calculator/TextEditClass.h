#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>
#include <QString>

class TextEditClass
{
public:
    explicit TextEditClass(QTextEdit *inputTextEdit, QTextEdit *outputTextEdit);
    ~TextEditClass();
    void GetStingLen()const;
    void GetByteLen()const;
    void StingToHexNoPrefix() const;
    void StingToHexHavePrefix() const;
    void ClearAllTextEdit() const;
    void HexToStingNoSpace() const;
    void HexToStingHaveSpace() const;
private:
    QTextEdit *InputTextEdit;  // 指向输入QTextEdit的指针
    QTextEdit *OutputTextEdit;  // 指向输出QTextEdit的指针
};



#endif // TEXTEDIT_H
