#include "GameSketch.h"

using namespace se;

GameSketch::GameSketch() {
    // Create a circle shape
    circle_shape_ = new CircleShape;
    circle_shape_->setRadius(20);
    circle_shape_->setPosition(100, 100);
    circle_shape_->setFillColor(Color(255, 0, 0));
    circle_shape_->setOutlineColor(Color(0, 255, 0));
    circle_shape_->setOutlineThickness(3);

    std::cout << "GameSketch created!" << std::endl;
}

GameSketch::~GameSketch() {
    delete circle_shape_;
    std::cout << "GameSketch destroyed!" << std::endl;
}

void GameSketch::update() {
    // For example, move circle to the right
    // circle->moveSomehow(..);
}

void GameSketch::draw() {
    GraphicalAssistant::draw(circle_shape_);
}