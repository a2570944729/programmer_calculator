#include "CheckBoxClass.h"

CheckBoxClass::CheckBoxClass(QWidget *parent, int CheckBoxId) :QCheckBox(parent),CheckBoxId(CheckBoxId)
{
}

CheckBoxClass::~CheckBoxClass()
{
}

// 获取是否应该添加十六进制前缀
bool CheckBoxClass::GetAddFlag() const
{
    return this->isChecked();
}
