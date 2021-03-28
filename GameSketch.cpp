#include "GameSketch.h"

using namespace se;

GameSketch::GameSketch() {
    // For example, create a circle of given options
    // Circle* circle = create_circle(...);
    // circle->setSomething(...);
    // save circle
    circle_shape_ = new CircleShape;
    circle_shape_->setRadius(20);
    circle_shape_->setPosition(100, 100);
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