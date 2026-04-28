#pragma once

#include "bsml/shared/BSML/FloatingScreen/FloatingScreen.hpp"
#include "UnityEngine/Vector2.hpp"

namespace CustomMenu::Banners {
    static BSML::FloatingScreen* leftBanner = nullptr;
    static BSML::FloatingScreen* rightBanner = nullptr;

    static UnityEngine::Vector2 defaultScale = { 120, 240 };
    static UnityEngine::Vector2 defaultImageScale = { 200.0f, 400.0f };

    void LoadBanners();
    void ReloadBanners();
}