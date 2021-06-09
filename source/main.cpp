

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <../include/PTree.h>
#include <../include/Menu.h>



int main()
{
    // A in range (1,90); D,L > 0
    double A = 30;
    double L = 100;
    unsigned int D = 15;


    Menu menu(1920, 1080);
    menu.display();


    return 0;
}