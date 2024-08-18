#ifndef CHECKBOXCLASS_H
#define CHECKBOXCLASS_H

#include <QCheckBox>

class CheckBoxClass : public QCheckBox
{
     Q_OBJECT
public:
    explicit CheckBoxClass(QWidget *parent = nullptr, int CheckBoxId = -1);
    ~CheckBoxClass() override;

    // 获取是否应该添加十六进制前缀
   bool GetAddFlag() const ;
private:
      int CheckBoxId;  // 用于标识此复选框的唯一整数值

};

#endif // CHECKBOXCLASS_H
