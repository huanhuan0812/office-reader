#pragma once
// pptx/include/Shape.h
#include "type.h"
#include <string>
#include <vector>

class pptx::Shape {
public:
    // 构造函数
    Shape(const std::string& name, ShapeType type, const Geometry& geometry, 
          double rotation = 0.0, int zOrder = 0)
        : m_name(name), m_type(type), m_geometry(geometry), 
          m_rotation(rotation), m_zOrder(zOrder) {}
    
    // 获取形状名称
    const std::string& getName() const { return m_name; }
    // 获取形状类型
    ShapeType getType() const { return m_type; }
    // 获取形状位置和大小
    const Geometry& getGeometry() const { return m_geometry; }
    // 获取旋转角度    
    double getRotation() const { return m_rotation; }
    // 获取堆叠顺序    
    int getZOrder() const { return m_zOrder; }
    // 获取父级形状（如果有）    
    std::shared_ptr<Shape> getParent() const { return m_parent.lock(); }
    // 获取子级形状列表    
    const std::vector<std::shared_ptr<Shape>>& getChildren() const { return m_children; }

private:
    std::string m_name; // 可选名称
    ShapeType m_type;   // 形状类型 emum ShapeType { Unknown, AutoShape, TextBox, Picture, Table, Chart, Group }
    Geometry m_geometry; // 位置和大小
    double m_rotation; // 旋转角度
    int m_zOrder; // 堆叠顺序
    std::weak_ptr<Shape> m_parent; // 父级（如果有）
    std::vector<std::shared_ptr<Shape>> m_children; // 子级形状列表
};