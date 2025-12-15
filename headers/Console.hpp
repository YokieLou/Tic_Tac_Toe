#pragma once

#include "Game.hpp"
#include <iostream>

namespace NS_IHC{

    class Console{
        private : 
            NS_SVC::Game game; 
            void draw();

        public : 
            Console();
            ~Console();
            void loop();
            NS_SVC::Game getGame();
            
    };
}