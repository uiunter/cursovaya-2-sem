#define MENU_LINES 2
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Menu {
    public:
        Menu(float width, float height);
        void display();

    private:
        sf::RenderWindow mWindow;
        void processEvents();
        void moveUp();
        void moveDown();
        
        int selectedItemIndex;
        float width, height;
        sf::Font font;
        sf::Text menu[MENU_LINES];

        double A;
        double L;
        unsigned int D;

};