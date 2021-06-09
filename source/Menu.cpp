#include <iostream>
#include <..\include\PTree.h>
#include "..\include\Menu.h"

Menu::Menu(float w, float h) : mWindow(sf::VideoMode(w, h), "SFML window")
{
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }

    Menu::width = w;
    Menu::height = h;

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Draw Tree");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MENU_LINES + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MENU_LINES + 1) * 1.5));

    selectedItemIndex = 0;
}

void Menu::display()
{
    while (mWindow.isOpen())
    {
        processEvents();
    }
}

void Menu::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) 
        {
            mWindow.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            mWindow.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
        {
            moveUp();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
        {
            moveDown();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && selectedItemIndex == 0)
        {
            bool displayTree = 1;
            mWindow.clear();
            sf::Text text;
            text.setFont(font);
            text.setString("Specify the lenght, depth and angle of your tree in console");
            text.setFillColor(sf::Color::White);
            text.setPosition(sf::Vector2f(width / 2, height / (MENU_LINES + 1) * 1));
            mWindow.draw(text);
            mWindow.display();
            std::cin >> L >> D >> A;
            PTree ptree(L, D, A);
            while (displayTree)
            {
                while (mWindow.pollEvent(event))
                {
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace)
                    {
                        displayTree = 0;
                    }
                    if (event.type == sf::Event::Closed)
                    {
                        mWindow.close();
                    }
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                        mWindow.close();
                    }
                    mWindow.clear();
                    mWindow.draw(ptree);
                    mWindow.display();
                }
            }  
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && selectedItemIndex == 1)
        {
            mWindow.close();
        }

        mWindow.clear();

        for (int i = 0; i < MENU_LINES; i++)
        {
            mWindow.draw(menu[i]);
        }
        mWindow.display();
          
    }
}

void Menu::moveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (selectedItemIndex + 1 < MENU_LINES)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
