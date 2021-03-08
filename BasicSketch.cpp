#include "BasicSketch.h"
#include "GameSketch.h"
#include "SketchDriver.h"

using namespace se;

BasicSketch::BasicSketch() {
    std::cout << "BasicSketch created!" << std::endl;
}

BasicSketch::~BasicSketch() {
    std::cout << "BasicSketch destroyed!" << std::endl;
}

void BasicSketch::update() {
    SketchAssistant::addSketch(new GameSketch);
    SketchAssistant::removeSketch(this);
    //std::cout << "BasicSketch updated!" << std::endl;
}

void BasicSketch::draw() {
    //std::cout << "BasicSketch drawn!" << std::endl;
}