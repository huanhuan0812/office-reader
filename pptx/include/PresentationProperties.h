#pragma once
// pptx/presentation.h
#include "type.h"

class pptx::PresentationProperties {
public:
    // 获取演示文稿标题
    const std::string& getTitle() const;
    // 获取演示文稿作者
    const std::string& getAuthor() const;
    // 获取演示文稿创建时间
    const std::string& getCreatedTime() const;
    // 获取演示文稿修改时间
    const std::string& getModifiedTime() const;
private:
    std::string m_title;
    std::string m_author;
    std::string m_createdTime;
    std::string m_modifiedTime;
};