#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class PTree : public sf::Drawable {

public:

    PTree(double L, unsigned int D, double A);
    void generateTree(sf::RenderTarget& target, sf::ConvexShape c, double length, unsigned int depth, double a, double b) const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    double L;
    unsigned int D;
    double A;

    sf::ConvexShape root;
    sf::Vector2f origin = {960, 980};
    std::vector<sf::Color> rainbow = { sf::Color(139, 0, 255), sf::Color(75, 0, 130),
        sf::Color(0, 0, 255), sf::Color(0, 255, 0), 
            sf::Color(255, 255, 0), sf::Color(255, 127, 0), sf::Color(255, 0, 0) };
  
};