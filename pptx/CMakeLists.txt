set(HEADER_FILES
    include/praser.h
    include/type.h
    include/presentation.h
    include/slide.h
    include/PresentationProperties.h
    include/Resource.h
    include/Shape.h
    include/Shape/TextShape.h
    include/utils/Text.h
)

set(SOURCE_FILES
    src/reader.h
    src/reader.cpp
    src/praser.cpp
)

# 设置 libzip 路径
set(libzip_DIR "/opt/homebrew/lib/cmake/libzip" CACHE PATH "Path to libzip")

# 查找 libzip
find_package(libzip REQUIRED)

add_library(pptx SHARED 
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

# 添加头文件包含路径
target_include_directories(pptx PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接 libzip（处理不同的目标名称）
if(TARGET libzip::libzip)
    target_link_libraries(pptx PRIVATE libzip::libzip)
else()
    # 如果 libzip::libzip 不存在，直接链接库
    find_library(LIBZIP_LIBRARY zip)
    target_link_libraries(pptx PRIVATE ${LIBZIP_LIBRARY})
    target_include_directories(pptx PRIVATE /opt/homebrew/include)
endif()

# 在当前目录导出
export(TARGETS pptx
    FILE ${CMAKE_CURRENT_BINARY_DIR}/pptx_targets.cmake
    NAMESPACE office-reader::
)

# 设置 C++ 标准
set_target_properties(pptx PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)