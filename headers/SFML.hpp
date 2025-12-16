#pragma once

#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <string>
#include "GroupShape.hpp"


namespace NS_IHC{

    class SFML{
        private : 
            NS_SVC::Game game; 
            void draw(sf::RenderWindow& window);
            sf::Text text;
            sf::Font font;
            sf::RectangleShape vBar; // Grid
            sf::RectangleShape cBar; // Cross
            sf::RectangleShape wBar; // Win 
            sf::CircleShape circle;
            
        public : 
            SFML();
            ~SFML();
            void loop();
            NS_SVC::Game getGame();
            
    };
}