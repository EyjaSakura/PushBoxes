#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"things/box/Box.h"
#include"things/player/player.h"
#include"map/Map.h"
#include"game/Game.h"
#include"common/Config.h"
#include<memory>
#include<iostream>

namespace Resources {
    const sf::Font& getMainFont();
    void loadAllTexture();
    void loadAllAudio();
}

