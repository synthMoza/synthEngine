#include "CircleShape.h"

using namespace se;

CircleShape::CircleShape() {
    circle_shape_ = new sf::CircleShape;
    object_ = circle_shape_;
}

void CircleShape::setPosition(float x, float y) {
    circle_shape_->setPosition({x, y});
}

void CircleShape::setOrigin(float x, float y) {
    circle_shape_->setOrigin({x, y});
}

void CircleShape::setRadius(float radius) {
    circle_shape_->setRadius(radius);
}

void CircleShape::setFillColor(const Color& color) {
    circle_shape_->setFillColor(color.getColor());
}

void CircleShape::setOutlineColor(const Color& color) {
    circle_shape_->setOutlineColor(color.getColor());
}

void CircleShape::setOutlineThickness(float thickness) {
    circle_shape_->setOutlineThickness(thickness);
}

CircleShape::~CircleShape() {
    delete object_;
}