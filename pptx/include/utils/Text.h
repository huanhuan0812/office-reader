#pragma once

#include "type.h"
#include <string>
#include <vector>

// 文本运行属性
class pptx::RunProperties {
    // 字体
    std::string m_typeface;             // 字体名称
    std::string m_panose;               // 字体分类
    
    // 尺寸 - 使用变体类型
    std::variant<int, double> m_fontSize;  // 半磅值 或 百分比
    
    // 颜色 - 支持多种颜色系统
    Color m_color;
    
    // 布尔属性（存储是否有显式设置）
    std::optional<bool> m_bold;
    std::optional<bool> m_italic;
    std::optional<bool> m_underline;
    
    // 高级排版
    double m_spacing;                    // 字符间距
    double m_baseline;                   // 上标/下标偏移
};

// 文本主体属性 整体边距、对齐方式等
class pptx::TextBodyProperties {
    double m_leftInset; // 左边距
    double m_rightInset; // 右边距
    double m_topInset; // 上边距
    double m_bottomInset; // 下边距
    TextAlign m_align; // 水平对齐方式
    VerticalAlign m_verticalAlign; // 垂直对齐方式
};

// 文本段落属性 对齐方式、行距等
class pptx::ParagraphProperties {
    TextAlign m_align; // 水平对齐方式
    VerticalAlign m_verticalAlign; // 垂直对齐方式
    double m_lineSpacing; // 行距
    double m_spaceBefore; // 段前距
    double m_spaceAfter; // 段后距
};



// 文本主体（对应 p:txBody）
class pptx::TextBody {
    std::vector<Paragraph> m_paragraphs; // 段落列表
    TextBodyProperties m_properties; // 文本属性
};

// 文本段落（对应 a:p）
class pptx::Paragraph {
    std::string m_text;                // 实际文本内容
    ParagraphProperties m_properties;         // 字体、大小、颜色、粗体等
};

// 文本运行（对应 a:r）
class pptx::Run {
    std::string m_text;                // 实际文本内容
    RunProperties m_properties;         // 字体、大小、颜色、粗体等
};

