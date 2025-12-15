#include "SFML.hpp"

using namespace NS_COMP;
using namespace NS_SVC;
using namespace std;

namespace NS_IHC{
    SFML::SFML(){
        this->game = Game();
    }

    SFML::~SFML(){}

    void SFML::loop(){

        // TODO : RESTUCTURER LA CLASSE POUR CONTENIR TOUS LES GRAPHSIMES UNE SEULE ET UNIQUE FOIS !
        // TODO : APPLIQUER CELA ICI
        // TODO : AFFICHER LA FLECHE DE VICTOIRE SI VICTOIRE
        // TODO : BOUTON RESTART

        sf::RenderWindow window(sf::VideoMode(950,950), "Tic Tac Toe"); // Création de base de la fenetre

        sf::Font font;
        if (!font.loadFromFile("font/OpenSans.ttf"))
        {
            cout << "Problème d'affichage de la police !" << endl; 
        }

        this->draw(window);
        window.display();

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                    
                else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Right){
                        if (!this->game.isWin() && !this->game.isDraw()) {
                            this->game.play(event.mouseButton.x/(950.f/3.f),event.mouseButton.y/(950.f/3.f));
                            this->draw(window);
                        }
                    
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                    else if (text.getGlobalBounds().contains(mousePos)){
                            sf::Text text;
                            text.setFont(font);

                            text.setCharacterSize(50);
                            text.setFillColor(sf::Color::Black);
                            
                            sf::FloatRect bounds = text.getLocalBounds();
                            text.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
                            text.setPosition(950.f/2.f,950.f/2.f);

                            window.draw(text);
                        }
                    }
                }
            }

            if (this->game.isWin()) {
                sf::Text text;
                text.setFont(font);
                TokenType winner = game.getWinner();

                if (winner == CROSS) {
                    text.setString("Victoire du joueur X");
                }
                else if (winner == CIRCLE) {
                    text.setString("Victoire du joueur O");
                }
                
                text.setCharacterSize(50);
                text.setFillColor(sf::Color::Black);
                
                sf::FloatRect bounds = text.getLocalBounds();
                text.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
                text.setPosition(950.f/2.f,950.f/2.f);

                window.draw(text);
            }
            else if (this->game.isDraw()) {
                sf::Text text;
                text.setFont(font);
                text.setString("Draw");

                text.setCharacterSize(50);
                text.setFillColor(sf::Color::Black);

                sf::FloatRect bounds = text.getLocalBounds();
                text.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);

                text.setPosition(950.f/2.f,950.f/2.f);
                window.draw(text);
            }

            window.display();

        }
    }

    Game SFML::getGame(){
        return this->game;
    }

    void SFML::draw(sf::RenderWindow& window){ 
        window.clear(sf::Color::White);

        sf::RectangleShape vBar(sf::Vector2f(10,950));
        vBar.setFillColor(sf::Color::Black);

        // Affichage des barres verticales
        for (int i = 1; i < 3 ;i++) {
            vBar.setPosition(950.f* (i / 3.f),0.f); 
            window.draw(vBar);
        }

        vBar.setRotation(vBar.getRotation() - 90.f);
        for (int i = 1; i < 3 ;i++) {
            vBar.setPosition(0.f,950.f*(i / 3.f)); 
            window.draw(vBar);
        }

        // --------------------

        float cellSize = 950.f / 3.f;
        Grid currentGrid = this->game.getGrid();

        for (int i = 0; i < 9 ;i++){
            int x = i % 3;
            int y = i / 3;

            float centerX = x * cellSize + cellSize/2; 
            float centerY = y * cellSize + cellSize/2;

            if (currentGrid.getCase(x,y) == CIRCLE){
                sf::CircleShape circle(100);
                circle.setOrigin(100, 100);  // Définit l'origine au centre du cercle
                circle.setOutlineThickness(10);
                circle.setOutlineColor(sf::Color::Red);
                circle.setPosition(centerX,centerY);

                window.draw(circle);
            }

            else if (currentGrid.getCase(x,y) == CROSS) {
                sf::RectangleShape bar(sf::Vector2f(10,250)); // Création du coté de la croix
                bar.setOrigin(5, 125); // Milieu de la forme
                bar.setFillColor(sf::Color::Blue);
                bar.setPosition(centerX, centerY);
                bar.setRotation(bar.getRotation() - 45);

                window.draw(bar);

                bar.setRotation(bar.getRotation() - 90);

                window.draw(bar);
            }
        }
    }
}



