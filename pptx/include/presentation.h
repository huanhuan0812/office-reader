#pragma once
// pptx/presentation.h
#include "type.h"
#include "PresentationProperties.h"
#include "../src/reader.h"
#include <memory>
#include <vector>

class pptx::Presentation {
public:
    // 解析PPTX文件，构建Presentation对象
    static Presentation parse(const std::string& filePath);
    
    // 获取幻灯片列表
    const std::vector<Slide>& getSlides() const;
    // 获取指定幻灯片
    const Slide& getSlide(size_t index) const;
    // 获取幻灯片总数
    size_t getSlideCount() const;

    // 获取主版列表
    const std::vector<SlideMaster>& getMasterSlides() const;

    // 获取版式列表
    const std::vector<SlideLayout>& getLayouts() const;

    // 获取主题信息
    const Theme& getTheme() const;

    // 获取资源列表
    const std::vector<Resource>& getResources() const;

    // 获取演示文稿属性
    const PresentationProperties& getProperties() const;

    // 获取备注幻灯片
    const std::vector<NoteSlide>& getNoteSlides() const;

    // 获取指定幻灯片的备注幻灯片
    const NoteSlide& getNoteSlide(size_t slideIndex) const;

private:
    std::vector<std::unique_ptr<Slide>> m_slides;
    std::vector<std::unique_ptr<SlideMaster>> m_masterSlides;
    std::vector<std::unique_ptr<SlideLayout>> m_layouts;
    std::unique_ptr<Theme> m_theme;
    std::vector<std::unique_ptr<Resource>> m_resources;  // 图片、图表等外部资源
    PresentationProperties m_properties;  // 演示文稿属性，如标题、作者等
    std::vector<std::unique_ptr<NoteSlide>> m_noteSlides;  // 备注幻灯片

    // 读取器
    Reader m_reader;
};