#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void searchAndWriteLines(const std::filesystem::path& directory, const std::string& keyword, const std::filesystem::path& outputFile) {
    std::ofstream output(outputFile);

    if (!output) {
        std::cout << "Unable to open output file." << std::endl;
        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            std::ifstream file(entry.path());

            if (!file) {
                std::cout << "Unable to open file: " << entry.path() << std::endl;
                continue;
            }

            std::string line;
            while (std::getline(file, line)) {
                if (line.find(keyword) != std::string::npos) {
                    output << line << std::endl;
                }
            }

            file.close();
        }
    }

    output.close();
}

int main() {
    std::string directoryPath = "D:/STEAM/steamapps/common/Victoria 3/game/localization/simp_chinese";
    std::string keyword = "GetFullName";
    std::string outputFile = "C:/Users/66485/Documents/Paradox Interactive/Victoria 3/mod/汉字文化圈与匈牙利姓前名后/localization/simp_chinese/replace/file.txt";

    searchAndWriteLines(directoryPath, keyword, outputFile);

    return 0;
}