#include "Grid.hpp"

namespace NS_COMP{
    Grid::Grid(){
        for (int i = 0; i < 9 ;i++){
            this->grid[i] = EMPTY;
        }
    }

    Grid::~Grid(){}

    TokenType Grid::getCase(int X, int Y){
        return this->grid[3*Y + X];
    }

    bool Grid::setCase(int X, int Y, TokenType token){
        if (this->grid[3*Y + X] != EMPTY){
            return false;
        }

        this->grid[3*Y + X] = token;
        return true;
    }
}

