#include "Banners/FileParser.hpp"

#include <algorithm>
#include <cctype>
#include <filesystem>

#include "bsml/shared/BSML-Lite/Creation/Image.hpp"
#include "constants.hpp"
#include "logging.hpp"

namespace CustomMenu::Banners {
    namespace {
        std::vector<std::string> bannerFiles;
    }

    void EnsureFolder() {
        std::string modPath = Constants::ModPath;
        if (!std::filesystem::exists(modPath)) {
            std::filesystem::create_directory(modPath);
        }

        std::string path = Constants::BannerFolder;
        if (!std::filesystem::exists(path)) {
            std::filesystem::create_directory(path);
        }
    }

    void parseFiles() {
        std::string path = Constants::BannerFolder;
        bannerFiles.clear();

        INFO("Parsing files in: {}", path.c_str());

        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            INFO("Found file: {}", entry.path().string().c_str());
            if (entry.is_regular_file()) {
                std::string extension = entry.path().extension().string();
                std::transform(extension.begin(), extension.end(), extension.begin(), [](unsigned char c) {
                    return static_cast<char>(std::tolower(c));
                });

                if (extension == ".png" || extension == ".jpg") {
                    std::string fileName = entry.path().filename().string();
                    bannerFiles.push_back(fileName);
                    INFO("Added file: {}", fileName.c_str());
                }
            }
        }
    }

    std::vector<std::string> getBannerFiles() {
        return bannerFiles;
    }

    UnityEngine::Sprite* readFileAsSprite(std::string filename) {
        std::string path = Constants::BannerFolder + "/" + filename;
        if (!std::filesystem::exists(path)) {
            return nullptr;
        }

        return BSML::Lite::FileToSprite(path);
    }
}
