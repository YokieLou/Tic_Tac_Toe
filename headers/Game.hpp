#pragma once

#include "Grid.hpp"
#include <iostream>

namespace NS_SVC {
    class Game {
    private:
        NS_COMP::Grid grid;
        TokenType currentPlayer;

    public:
        Game();
        ~Game();
        bool play(int x, int y);
        bool isWin();
        bool isDraw();

        TokenType getCurrentPlayer();
        NS_COMP::Grid& getGrid();
        TokenType getWinner();
    };
}
