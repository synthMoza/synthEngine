#include "SketchDriver.h"
#include "BasicSketch.h"
#include "Sketch.h"

using namespace se;

// Declare static pointer to the driver with nullptr at the start
SketchDriver* SketchAssistant::sketch_driver_ = nullptr;

// Default constructor for the sketch driver, creates the first empty scetch
SketchDriver::SketchDriver(Sketch* start_sketch) {
    if (start_sketch == nullptr)
        throw std::runtime_error("Nullptr to the start sketch!");

    addSketch(start_sketch);
}

size_t SketchDriver::getSketches() {
    return sketches_.size();
}

void SketchDriver::collectObjects() {
    for (auto&& sketch : sketches_) {
        sketch->draw();
    }
}

// Add the sketch to the driver
void SketchDriver::addSketch(Sketch* sketch) {
    sketches_.push_back(sketch);

    // std::cout << "Sketch added!" << std::endl;
    // std::cout << "Size: " << sketches_.size() << std::endl;
}

// Remove sketch from the driver
void SketchDriver::removeSketch(Sketch* sketch) {
    to_delete_.push_back(sketch);
}

void SketchDriver::deleteSketches() {
    // If there are any sketches to be deleted
    if (!to_delete_.empty()) {
        for (auto& sketch : to_delete_) {
            // Delete this element from the vector
            for (auto it = sketches_.begin(); it != sketches_.end(); ++it) {
                if (*it == sketch) {
                    sketches_.erase(it);
                    break;
                }
            }

            // Clear all objects from this sketch
            delete sketch;
        }

        to_delete_.clear();
    }
}

// Updates all active sketches
void SketchDriver::updateSketches() {
    for (auto && sketch : sketches_) {
        if (sketch != nullptr)
            sketch->update();
    }
}

SketchDriver::~SketchDriver() {
    for (auto && sketch : sketches_) {
        if (sketch != nullptr)
            delete sketch;
    }
};

// ========================

void SketchAssistant::addSketch(Sketch* sketch) {
    if (sketch_driver_ != nullptr)
        sketch_driver_->addSketch(sketch);
}

void SketchAssistant::removeSketch(Sketch* sketch) {
    if (sketch_driver_ != nullptr)
        sketch_driver_->removeSketch(sketch);
}