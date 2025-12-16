#include "SFML.hpp"

using namespace NS_COMP;
using namespace NS_SVC;
using namespace std;

namespace NS_IHC{
    SFML::SFML(){
        this->game = Game();
       
        if (!this->font.loadFromFile("font/OpenSans.ttf"))
        {
            cout << "Problème d'affichage de la police !" << endl; 
        }


        this->text.setFont(font);
        this->text.setCharacterSize(50);
        this->text.setFillColor(sf::Color::Black);
        sf::FloatRect bounds = text.getLocalBounds();
        this->text.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
        this->text.setPosition(950.f/2.f,950.f/2.f);


        this->circle.setRadius(100);
        this->circle.setOrigin(100, 100);  // Définit l'origine au centre du cercle
        this->circle.setOutlineThickness(10);
        this->circle.setOutlineColor(sf::Color::Red);

        // Test 
        sf::RectangleShape* vBar = new sf::RectangleShape(sf::Vector2f(10,950));
        GroupShape grid;
        grid.add(vBar);

        this->vBar = *vBar;
        this->vBar.setFillColor(sf::Color::Black);


        this->cBar.setSize(sf::Vector2f(10,250)); // Création du coté de la croix
        this->cBar.setOrigin(5, 125); // Milieu de la forme
        this->cBar.setFillColor(sf::Color::Blue);
    }

    SFML::~SFML(){}

    void SFML::loop(){

        // TODO : RESTUCTURER LA CLASSE POUR CONTENIR TOUS LES GRAPHSIMES UNE SEULE ET UNIQUE FOIS !
        // TODO : APPLIQUER CELA ICI
        // TODO : AFFICHER LA FLECHE DE VICTOIRE SI VICTOIRE
        // TODO : BOUTON RESTART
        // TODO : UNE CLASS GROUPSHAPE QUI PEUX CONTENIR TOUT ET N'IMPORTE EN TERME DE SHAPES (utile pour les formes plus complexes)

        sf::RenderWindow window(sf::VideoMode(950,950), "Tic Tac Toe"); // Création de base de la fenetre

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
                    if (event.mouseButton.button == sf::Mouse::Right || event.mouseButton.button == sf::Mouse::Left){
                        if (!this->game.isWin() && !this->game.isDraw()) {
                            this->game.play(event.mouseButton.x/(950.f/3.f),event.mouseButton.y/(950.f/3.f));
                            this->draw(window);
                        }
                    }
                }
            }

            if (this->game.isWin()) {
                TokenType winner = game.getWinner();

                if (winner == CROSS) {
                    this->text.setString("Victoire du joueur X");

                    sf::FloatRect bounds = this->text.getLocalBounds();
                    this->text.setOrigin(bounds.left + bounds.width / 2, bounds.top  + bounds.height / 2);
                    this->text.setPosition(950.f/2.f,950.f/2.f);
                }
                else if (winner == CIRCLE) {
                    this->text.setString("Victoire du joueur O");

                    sf::FloatRect bounds = this->text.getLocalBounds();
                    this->text.setOrigin(bounds.left + bounds.width / 2, bounds.top  + bounds.height / 2);
                    this->text.setPosition(950.f/2.f,950.f/2.f);
                }
                
                window.draw(this->text);
            }
            else if (this->game.isDraw()) {
                this->text.setString("Draw");

                sf::FloatRect bounds = this->text.getLocalBounds();
                this->text.setOrigin(bounds.left + bounds.width / 2, bounds.top  + bounds.height / 2);
                this->text.setPosition(950.f/2.f,950.f/2.f);

                window.draw(this->text);
            }

            window.display();

        }
    }

    Game SFML::getGame(){
        return this->game;
    }

    void SFML::draw(sf::RenderWindow& window){ 
        window.clear(sf::Color::White);

        // Affichage des barres verticales
        this->vBar.setRotation(0.f);
        for (int i = 1; i < 3 ;i++) {
            this->vBar.setPosition(950.f* (i / 3.f),0.f); 
            window.draw(this->vBar);
        }

        this->vBar.setRotation(-90.f);
        for (int i = 1; i < 3 ;i++) {
            this->vBar.setPosition(0.f,950.f*(i / 3.f)); 
            window.draw(this->vBar);
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
                this->circle.setPosition(centerX,centerY);
                window.draw(this->circle);
            }

            else if (currentGrid.getCase(x,y) == CROSS) {
                this->cBar.setPosition(centerX, centerY);

                this->cBar.setRotation(45);
                window.draw(this->cBar);

                this->cBar.setRotation(-45);
                window.draw(this->cBar);
            }
        }
    }
}



