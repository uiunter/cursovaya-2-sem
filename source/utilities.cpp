#include "../include/utilities.h"

std::vector<sf::Vector2f> PNode::points() const
{
    return { baseP1, baseP2, topP1, topP2, triangleP };
}

float magnitude(const sf::Vector2f& vec) {
    return float(std::sqrt(std::pow(vec.x, 2.f) + std::pow(vec.y, 2.f)));
}

sf::Vector2f orthogonal(const sf::Vector2f& vec) {
    return sf::Vector2f(-vec.y, vec.x);
}

sf::Vector2f normalize(const sf::Vector2f& vec) {
    return vec / magnitude(vec);
}

float dot(const sf::Vector2f& lhs, const sf::Vector2f& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

sf::Vector2f projection(const sf::Vector2f& vec, const sf::Vector2f& base) {
    return dot(vec, base) / dot(base, base) * base;
}

sf::Vector2f rotateVector(const sf::Vector2f& vec, float angle) {
    sf::Transform rotation;
    rotation.rotate(angle);
    return rotation.transformPoint(vec);
}

PNode generateNode(const sf::Vector2f& baseP1,
    const sf::Vector2f& baseP2, float angle) {
    //get versors storing the directions of the base and height of the square
    auto baseV = normalize(baseP2 - baseP1);
    auto heightV = orthogonal(baseV);

    //get side length and versor
    auto sideLength = magnitude(baseP2 - baseP1);

    //calculate top base points
    auto topP1 = baseP1 + sideLength * heightV;
    auto topP2 = baseP2 + sideLength * heightV;

    //get versor poiting to tip of triangle (from the first top base point)
    auto angleV = rotateVector(baseV, -angle);

    //calculate tip of triangle by projecting the top base onto the triangle versor
    //	NB: this works because the triangle is right-angled
    auto triangleP = topP1 + projection(sideLength * baseV, angleV);

    //return obtained points as node
    return PNode{ baseP1, baseP2, topP1, topP2, triangleP };
}

//std::vector<sf::Vector2f>
//generateTree(const sf::Vector2f& baseP1,
//    const sf::Vector2f& baseP2,
//    float angle, unsigned int depth) {
//    //base case - done generating the tree
//    if (!depth)
//        return {};
//
//    //result of function
//    std::vector<sf::Vector2f> treePoints;
//
//    //generate the node
//    auto node = generateNode(baseP1, baseP2, angle);
//
//    //recurse left
//    auto leftTreePoints = generateTree(node.topP1, node.triangleP, angle, depth - 1);
//
//    //recurse right
//    auto rightTreePoints = generateTree(node.triangleP, node.topP2, angle, depth - 1);
//
//    //join outputs
//    auto nodePoints = node.points();
//    treePoints.insert(treePoints.end(), nodePoints.begin(), nodePoints.end());
//    treePoints.insert(treePoints.end(), leftTreePoints.begin(), leftTreePoints.end());
//    treePoints.insert(treePoints.end(), rightTreePoints.begin(), rightTreePoints.end());
//
//    //return
//    return treePoints;
//}

