#include "GraphicalDriver.h"

using namespace se;

// Initialize static variable for the graphical assistant
GraphicalDriver* GraphicalAssistant::graphical_driver = nullptr;

GraphicalDriver::GraphicalDriver(sf::RenderWindow* window) : window_ (window) {}

GraphicalDriver::~GraphicalDriver() {}

void GraphicalDriver::draw(GraphicalObject* graphical_object) {
    window_->draw(*(graphical_object->object_));
}

void GraphicalAssistant::draw(GraphicalObject* graphical_object) {
    graphical_driver->draw(graphical_object);
}

Vector2u GraphicalAssistant::getResolution() {
    return Application::getResolution();
}