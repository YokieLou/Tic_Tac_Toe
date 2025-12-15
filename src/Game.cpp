#include "Game.hpp"

using namespace NS_COMP;

namespace NS_SVC {

Game::Game() : currentPlayer(CROSS) {}

Game::~Game() {}

bool Game::play(int x, int y) {
    if (!this->grid.setCase(x, y, currentPlayer)) {
        return false;
    }

    // changer de joueur
    this->currentPlayer = (currentPlayer == CROSS) ? CIRCLE : CROSS;
    return true;
}

bool Game::isWin() {
    // Colonnes
    for (int x = 0; x < 3; x++) {
        if (this->grid.getCase(x, 0) != EMPTY &&
            this->grid.getCase(x, 0) == this->grid.getCase(x, 1) &&
            this->grid.getCase(x, 1) == this->grid.getCase(x, 2)) {
            return true;
        }
    }

    // Lignes
    for (int y = 0; y < 3; y++) {
        if (this->grid.getCase(0, y) != EMPTY &&
            this->grid.getCase(0, y) == this->grid.getCase(1, y) &&
            this->grid.getCase(1, y) == this->grid.getCase(2, y)) {
            return true;
        }
    }

    // Diagonales
    if (this->grid.getCase(0,0) != EMPTY &&
        this->grid.getCase(0,0) == grid.getCase(1,1) &&
        this->grid.getCase(1,1) == grid.getCase(2,2))
        return true;

    if (this->grid.getCase(2,0) != EMPTY &&
        this->grid.getCase(2,0) == this->grid.getCase(1,1) &&
        this->grid.getCase(1,1) == this->grid.getCase(0,2))
        return true;

    return false;
}

bool Game::isDraw() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (this->grid.getCase(x, y) == EMPTY)
                return false;
        }
    }
    return !this->isWin();
}

Grid& Game::getGrid() {
    return grid;
}

TokenType Game::getWinner() {
    if (!isWin())
        return EMPTY;

    // Le gagnant est le joueur précédent
    return (currentPlayer == CROSS) ? CIRCLE : CROSS;
}

}
