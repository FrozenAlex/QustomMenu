#pragma once

#include <string>
#include <vector>

#include "UnityEngine/Sprite.hpp"

namespace CustomMenu::Banners {
    void EnsureFolder();
    void parseFiles();
    std::vector<std::string> getBannerFiles();
    UnityEngine::Sprite* readFileAsSprite(std::string filename);
}
