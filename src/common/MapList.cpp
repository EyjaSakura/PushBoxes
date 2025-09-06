#include "common/MapList.h"
#include<iostream>

MapList::MapList(const std::string& folderPath) {
    namespace fs = std::filesystem;
    try {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                //测试用，长度为27是因为文件数量少于10，并且需要注意是绝对路径
                if (entry.path().string().length() > 27) { continue; }

                maps_.push_back(entry.path().string());
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "文件系统错误: " << e.what() << std::endl;
    }
}