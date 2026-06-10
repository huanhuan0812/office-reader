#pragma once
// pptx/reader.h
#include "type.h"
#include <new>
#include <string>
#include <vector>
#include <optional>
#include <functional>

struct ZipFileInfo {
    std::string name;      // 文件路径
    uint64_t size;         // 原始大小
    uint32_t crc32;        // CRC32校验
    uint16_t compression;  // 压缩方法：0=存储，8=deflate
    time_t modified;       // 修改时间
};

// 流式读取器接口
class IZipReader {
public:
    virtual ~IZipReader() = default;
    
    // 打开ZIP文件
    virtual bool open(const std::string& path) = 0;
    virtual bool open(const void* data, size_t size) = 0;  // 内存模式
    
    // 文件列表（轻量级，只读中央目录）
    virtual std::vector<ZipFileInfo> listFiles() const = 0;
    virtual bool hasFile(const std::string& name) const = 0;
    
    // 流式读取 - 返回文件大小，通过callback处理数据块
    virtual bool readFile(const std::string& name, 
                          std::function<bool(const uint8_t* data, size_t len)> callback) = 0;
    
    // 便捷方法：读取到内存（小文件专用）
    virtual std::vector<uint8_t> readAllBytes(const std::string& name) = 0;
    
    // 获取文件信息（不读取内容）
    virtual std::optional<ZipFileInfo> getInfo(const std::string& name) const = 0;
    
    // 关闭
    virtual void close() = 0;
};

class Reader {
public:
    Reader(const std::string& filePath);
    ~Reader();

    
    virtual bool open(const std::string& path) = 0;
    virtual bool open(const void* data, size_t size) = 0;  // 从内存打开
    virtual void close() = 0;
    virtual bool is_open() const = 0;

private:
    std::string m_filePath;
};