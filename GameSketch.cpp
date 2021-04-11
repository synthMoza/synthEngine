#include "GameSketch.h"

using namespace se;

GameSketch::GameSketch() {
    // Create a circle shape
    circle_shape_ = new CircleShape();
    circle_shape_->setRadius(20);
    circle_shape_->setPosition({100, 100});
    circle_shape_->setFillColor(Color(255, 0, 0));
    circle_shape_->setOutlineColor(Color(0, 255, 0));
    circle_shape_->setOutlineThickness(3);
    circle_shape_->setScale({5, 5});

    // Create a sprite
    sprite_ = new Sprite();
    unsigned int id = GraphicalAssistant::loadTexture("sprite.png");
    sprite_->setTexture(id);
    sprite_->setScale({0.5, 0.5});
    sprite_->setPosition({200, 200});

    // Add objects to GraphicalDriver
    addObject(sprite_, 1);
    addObject(circle_shape_, 0);

    std::cout << "GameSketch created!" << std::endl;
}

GameSketch::~GameSketch() {
    std::cout << "GameSketch destroyed!" << std::endl;
}

void GameSketch::update() {
    if (InputAssistant::isKeyPressed(Escape)) {
        SketchAssistant::removeSketch(this);
        return;
    }

    float velocity = 0.01;
    unsigned long delta_time = TimeAssistant::getFrameTime() * 10e-3;

    Vector2u resolution = GraphicalAssistant::getResolution();
    Vector2f tmp_pos = circle_shape_->getPosition();

    if (InputAssistant::isKeyHeld(Right)) {
        circle_shape_->move({ velocity * delta_time, 0 });
    }

    else if (InputAssistant::isKeyHeld(Left)) {
        circle_shape_->move({ -velocity * delta_time, 0 });
    }
    
    if (InputAssistant::isKeyHeld(Up)) {
        circle_shape_->move({0, -velocity * delta_time});
    }
    else if (InputAssistant::isKeyHeld(Down)) {
        circle_shape_->move({ 0, velocity * delta_time });
    }

    if (InputAssistant::isMKeyHeld(RMouse)) {
        uint8_t r = std::rand() % 256;
        uint8_t g = std::rand() % 256;
        uint8_t b = std::rand() % 256;

        circle_shape_->setFillColor(Color{r, g, b});
    }
}