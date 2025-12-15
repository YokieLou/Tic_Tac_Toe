#pragma once

#include "Grid.hpp"

namespace NS_SVC{
    class Game {
        private : 
            Grid grid;
        
        public : 
            Game();
            ~Game();
            bool play(int X, int Y); // Logique de simulation
            const Grid& getGrid() const; // Avoir cette grille permettra l'affichage

    }
};