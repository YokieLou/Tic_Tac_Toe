#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace NS_COMP{
    class GroupShape{
        private : 
            std::vector<sf::Shape*> group;

        public : 
            GroupShape(std::vector<sf::Shape*> group);
            GroupShape();
            ~GroupShape();

            void add(sf::Shape* shape);
            void del(sf::Shape* shape);
            sf::Shape* get(int index);

            void setPosition(float x, float y);
            void setOrigin(float x, float y);
            void drawAll(sf::RenderWindow &window);

            void move(float x, float y);
            void scale(float factorX, float factorY);
            void rotate(float angle);

            int size();
            void clear();
    };
}
