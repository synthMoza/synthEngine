#include "CircleShape.h"

using namespace se;

CircleShape::CircleShape() {
    circle_shape_ = new sf::CircleShape;
    object_ = circle_shape_;
}

void CircleShape::setPosition(Vector2f pos) {
    circle_shape_->setPosition({pos.x_, pos.y_});
}

void CircleShape::setOrigin(Vector2f origin) {
    circle_shape_->setOrigin({origin.x_, origin.y_});
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

void CircleShape::move(Vector2f offset) {
    circle_shape_->move({offset.x_, offset.y_});
}

void CircleShape::setScale(Vector2f scale) {
    circle_shape_->setScale({scale.x_, scale.y_});
}

// Getters

Vector2f CircleShape::getPosition() {
    sf::Vector2f tmp = circle_shape_->getPosition();
    return Vector2f{tmp.x, tmp.y};
}

Vector2f CircleShape::getOrigin() {
    sf::Vector2f tmp = circle_shape_->getOrigin();
    return Vector2f{tmp.x, tmp.y};
}

float CircleShape::getRadius() {
    return circle_shape_->getRadius();
}

Color CircleShape::getFillColor() {
    sf::Color tmp = circle_shape_->getFillColor();
    return Color(tmp.r, tmp.g, tmp.b);
}
        
Color CircleShape::getOutlineColor() {
    sf::Color tmp = circle_shape_->getOutlineColor();
    return Color(tmp.r, tmp.g, tmp.b);
}

float CircleShape::getOutlineThickness() {
    return circle_shape_->getOutlineThickness();
}

Vector2f CircleShape::getScale() {
    sf::Vector2f tmp = circle_shape_->getScale();
    return Vector2f{tmp.x, tmp.y};
}

CircleShape::~CircleShape() {
    delete object_;
}