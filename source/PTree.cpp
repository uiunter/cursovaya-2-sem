#define PI 3.14159265358979323846
#include "../include/PTree.h"

PTree::PTree(double length, unsigned int depth, double angle) {
    L = length;
    D = depth;
    A = angle;

    root.setPointCount(4);
    root.setPoint(0, sf::Vector2f(origin.x, origin.y - L));
    root.setPoint(1, sf::Vector2f(origin.x + L, origin.y - L));
    root.setPoint(2, sf::Vector2f(origin.x + L, origin.y));
    root.setPoint(3, sf::Vector2f(origin.x, origin.y));
    root.setFillColor(rainbow[depth % 7]);

}

void PTree::generateTree(sf::RenderTarget& target, sf::ConvexShape root, double L, unsigned int depth, double a, double b) const {

    if (!depth) {
        return;
    }

    double t = a / 180 * PI;
    double tc = b / 180 * PI;

    double lengthA = L * cos(A / 180 * PI);
    double lengthB = L * cos((90 - A) / 180 * PI);

    sf::ConvexShape left;
    left.setPointCount(4);
    left.setPoint(0, sf::Vector2f(root.getPoint(0).x - lengthA * cos(tc), root.getPoint(0).y - lengthA * sin(tc)));
    left.setPoint(1, sf::Vector2f(root.getPoint(0).x + lengthA * cos(t) - lengthA * sin(t), root.getPoint(0).y - lengthA * sin(t) - lengthA * cos(t)));
    left.setPoint(2, sf::Vector2f(root.getPoint(0).x + lengthA * cos(t), root.getPoint(0).y - lengthA * sin(t)));
    left.setPoint(3, root.getPoint(0));
    left.setFillColor(rainbow[depth % 7]);

    sf::ConvexShape right;
    right.setPointCount(4);
    right.setPoint(3, sf::Vector2f(root.getPoint(1).x - lengthB * cos(tc), root.getPoint(1).y - lengthB * sin(tc)));
    right.setPoint(2, root.getPoint(1));
    right.setPoint(1, sf::Vector2f(root.getPoint(1).x + lengthB * cos(t), right.getPoint(2).y - lengthB * sin(t)));
    right.setPoint(0, sf::Vector2f(right.getPoint(3).x + lengthB * sin(tc), right.getPoint(3).y - lengthB * cos(tc)));
    right.setFillColor(rainbow[depth % 7]);


    target.draw(root);
    target.draw(left);
    target.draw(right);

    generateTree(target, left, lengthA, depth - 1, a + A, b - A);
    generateTree(target, right, lengthB, depth - 1, A - b, b + (90 - A));
}

void PTree::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    generateTree(target, root, L, D, A, 90 - A);
}
