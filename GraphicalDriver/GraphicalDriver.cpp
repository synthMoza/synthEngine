#include "GraphicalDriver.h"

using namespace se;

// Initialize static variable for the graphical assistant
GraphicalDriver* GraphicalAssistant::graphical_driver = nullptr;

GraphicalDriver::GraphicalDriver(sf::RenderWindow* window) : window_ (window) {}

GraphicalDriver::~GraphicalDriver() {
    // Delete all loaded textures
    for (auto& texture : textures_) {
        delete texture;
    }
}

void GraphicalDriver::draw(GraphicalObject* graphical_object) {
    window_->draw(*(graphical_object->object_));
}

unsigned int GraphicalDriver::loadTexture(std::string path) {
    Texture* texture = new Texture;
    texture->loadFromFile(path);
    textures_.push_back(texture);
    
    return textures_.size() - 1;
}

Texture* GraphicalDriver::getTexture(unsigned int ID) {
    return textures_.at(ID);
}

void GraphicalAssistant::draw(GraphicalObject* graphical_object) {
    graphical_driver->draw(graphical_object);
}

Vector2u GraphicalAssistant::getResolution() {
    return Application::getResolution();
}

unsigned int GraphicalAssistant::loadTexture(std::string path) {
    return graphical_driver->loadTexture(path);
}

Texture* GraphicalAssistant::getTexture(unsigned int ID) {
    return graphical_driver->getTexture(ID);
}