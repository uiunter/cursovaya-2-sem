#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

struct PNode {
    sf::Vector2f baseP1, baseP2, topP1, topP2, triangleP;
    std::vector<sf::Vector2f> points() const;
};

float magnitude(const sf::Vector2f& vec);

sf::Vector2f orthogonal(const sf::Vector2f& vec);

sf::Vector2f normalize(const sf::Vector2f& vec);

float dot(const sf::Vector2f& lhs, const sf::Vector2f& rhs);

sf::Vector2f projection(const sf::Vector2f& vec, const sf::Vector2f& base);

sf::Vector2f rotateVector(const sf::Vector2f& vec, float angle);

PNode generateNode(const sf::Vector2f& baseP1,
    const sf::Vector2f& baseP2, float angle);


