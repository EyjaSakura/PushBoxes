#pragma once
#include <vector>
#include <string>
#include <filesystem>

class MapList {
private:
    std::vector<std::string> maps_;
public:
    // 扫描文件夹，填充 maps
    explicit MapList(const std::string& folder);

    // 只读访问
    [[nodiscard]] const std::vector<std::string>& files() const { return maps_; }
    [[nodiscard]] std::size_t count() const { return maps_.size(); }
    [[nodiscard]] const std::string& at(std::size_t idx) const { return maps_[idx]; }
};