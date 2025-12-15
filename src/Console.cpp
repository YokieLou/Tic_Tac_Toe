#include "Console.hpp"

using namespace NS_COMP;
using namespace NS_SVC;
using namespace std;

namespace NS_IHC{
    Console::Console(){
        this->game = Game();
    }

    Console::~Console(){}

    void Console::draw(){
        for (int i = 0; i < 9; i++){
            if (i % 3 == 0){
                cout << endl;
            } 

            if (this->game.getGrid().getCase(i%3, i/3) == TokenType::EMPTY){
                cout << "_";
            }
            else if (this->game.getGrid().getCase(i%3, i/3) == TokenType::CIRCLE){
                cout << "O";
            }
            else {
                cout << "X";
            }
        }
        cout << endl;
    }

    void Console::loop(){
        int x;
        cout << "Veuillez choisir la position de la case pour X : ";
        cin >> x;

        int y;
        cout << "Veuillez choisir la position de la case pour Y : ";
        cin >> y;

        this->game.play(x,y);
    }
    
    Game Console::getGame(){
        return this->game;
    }

    
}


