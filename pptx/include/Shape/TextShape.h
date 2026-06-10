#pragma once
// pptx/include/TextShape.h
#include "Shape.h"
#include "type.h"
#include <string>
#include "utils/Text.h"

class pptx::TextShape : public Shape {
public:
private:
    std::string m_text; // 文本内容
    TextBody m_textBody; // 文本主体
    Geometry m_textPosition; // 文字位置
};