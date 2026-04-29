#pragma once

#include "ModConfig.hpp"
#include "UnityEngine/GameObject.hpp"

namespace CustomMenu::Tweaks::Logo {
    extern SafePtrUnity<UnityEngine::GameObject> logo;

    void onLoad();
    void setState();
}
