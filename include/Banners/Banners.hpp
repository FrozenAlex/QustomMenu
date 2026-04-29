#pragma once

#include "bsml/shared/BSML/FloatingScreen/FloatingScreen.hpp"
#include "UnityEngine/Vector2.hpp"

namespace CustomMenu::Banners {
    extern SafePtrUnity<BSML::FloatingScreen> leftBanner;
    extern SafePtrUnity<BSML::FloatingScreen> rightBanner;

    extern UnityEngine::Vector2 defaultScale;
    extern UnityEngine::Vector2 defaultImageScale;

    void LoadBanners();
    void ReloadBanners();
}
