#pragma once

#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <string>


namespace NS_IHC{

    class SFML{
        private : 
            NS_SVC::Game game; 
            void draw(sf::RenderWindow& window);

        public : 
            SFML();
            ~SFML();
            void loop();
            NS_SVC::Game getGame();
            
    };
}