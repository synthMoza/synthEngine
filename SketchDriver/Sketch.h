#pragma once

#include "../GraphicalDriver/GraphicalDriver.h"

#include <cstddef>
#include <iostream>
#include <vector>

namespace se {
    // Forward declaration of the skecth driver
    class SketchDriver;

    const int MAX_LAYERS = 128;

    // The scetch class for designing the certain part of the application that
    // contains related objects and methods
    class Sketch {
        // Vector of all graphical objects of this sketch
        std::vector<std::vector<GraphicalObject*>> graphical_objects_;
    public:
        Sketch() {
            graphical_objects_.resize(MAX_LAYERS);
        }

        virtual void update() {}
        void draw();
        void addObject(GraphicalObject* object, unsigned int layer = 0);

        virtual ~Sketch();
    };
}