set(HEADER_FILES
    include/slides/read.h
)

set(SOURCE_FILES
    src/slides/read.cpp
)

add_library(pptx SHARED 
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

# 在当前目录导出
export(TARGETS pptx
    FILE ${CMAKE_CURRENT_BINARY_DIR}/pptx_targets.cmake
    NAMESPACE office-reader::
)