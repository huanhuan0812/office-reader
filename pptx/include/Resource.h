#pragma once
// pptx/Resource.h
#include "type.h"
#include <vector>
#include <string>

class pptx::Resource {
public:
    // 获取资源类型，如图片、图表等
    const std::string& getType() const;
    // 获取资源数据，如图片的二进制数据
    const std::vector<uint8_t>& getData() const;
private:
    std::string m_type;  // "image", "chart", etc.
    int m_id;  // 资源ID，供幻灯片等引用
    int m_size;  // 资源大小
    int m_offset;  // 资源在PPTX文件中的偏移位置
};