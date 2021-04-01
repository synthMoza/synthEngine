#include "GameSketch.h"

using namespace se;

GameSketch::GameSketch() {
    // Create a circle shape
    circle_shape_ = new CircleShape;
    circle_shape_->setRadius(20);
    circle_shape_->setPosition({100, 100});
    circle_shape_->setFillColor(Color(255, 0, 0));
    circle_shape_->setOutlineColor(Color(0, 255, 0));
    circle_shape_->setOutlineThickness(3);
    circle_shape_->setScale({5, 5});

    std::cout << "GameSketch created!" << std::endl;
}

GameSketch::~GameSketch() {
    delete circle_shape_;
    std::cout << "GameSketch destroyed!" << std::endl;
}

void GameSketch::update() {
    // For example, move circle horizontally
    float velocity = 0.01;
    unsigned long delta_time = TimeAssistant::getFrameTime() * 10e-3;

    Vector2f tmp_pos = circle_shape_->getPosition();
    if (tmp_pos.x_ <= 1200) {
        // The circle must stop moving
        circle_shape_->move({velocity * delta_time, 0});
    }
}

void GameSketch::draw() {
    GraphicalAssistant::draw(circle_shape_);
}