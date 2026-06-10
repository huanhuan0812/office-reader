# pragma once
// pptx/types.h
#include <cstdint>
#include <string>
#include <variant>

namespace pptx {
    // 主要枚举
    enum class ShapeType { Unknown, AutoShape, TextBox, Picture, Table, Chart, Group };
    enum class TextAlign { Left, Center, Right, Justify, Distributed };
    enum class VerticalAlign { Top, Middle, Bottom, Justified };
    
    // 颜色系统
    class Color {
        struct RGB { u_int8_t r, g, b; };
        struct HSL { double h, s, l; };
        struct Scheme { std::string name; };  // "accent1", "dark1"
        
        std::variant<RGB, HSL, Scheme, std::monostate> m_value;
    };

    struct Geometry {
        double x, y, width, height;
    };

    struct Ract {
        double height, width;
    };
    
    // 主要模型类前向声明
    class Presentation;
    
    class Theme;
    class Resource;
    
    class Slide;
    class SlideMaster;
    class SlideLayout;
    class PresentationProperties;
    class NoteSlide;

    class Shape;
    class TextShape;

    class TextBody;
    class TextBodyProperties;
    class Paragraph;
    class ParagraphProperties;
    class Run;
    class RunProperties;
}