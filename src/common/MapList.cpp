#include "common/MapList.h"
#include<iostream>

MapList::MapList(const std::string& folderPath) {
    namespace fs = std::filesystem;
    try {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                //�����ã�����Ϊ27����Ϊ�ļ���������10��������Ҫע���Ǿ���·��
                if (entry.path().string().length() > 27) { continue; }

                maps_.push_back(entry.path().string());
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "�ļ�ϵͳ����: " << e.what() << std::endl;
    }
}