#pragma once

#include "TokenType.hpp"

namespace NS_COMP {
    class Grid {
        private : 
            TokenType grid[9];
        
        public :
            Grid();
            ~Grid();
            TokenType getCase(int X, int Y);
            bool setCase(int X, int Y, TokenType token);
    };
};
