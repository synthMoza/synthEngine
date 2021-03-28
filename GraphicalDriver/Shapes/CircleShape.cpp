#include "CircleShape.h"

using namespace se;

CircleShape::CircleShape() : x_ (0.f), y_ (0.f),  radius_ (0.f) {
    object_ = new sf::CircleShape;
}

void CircleShape::setPosition(float x, float y) {
    x_ = x;
    y_ = y;
    sf::CircleShape* object = static_cast<sf::CircleShape*>(object_);
    object->setPosition({x_, x_});
}

void CircleShape::setRadius(float radius) {
    radius_ = radius;
    sf::CircleShape* object = static_cast<sf::CircleShape*>(object_);
    object->setRadius(radius_);
}

CircleShape::~CircleShape() {
    delete object_;
}