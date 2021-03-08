#pragma once

#include <cstddef>
#include <iostream>

namespace se {
    // Forward declaration of the skecth driver
    class SketchDriver;

    // The scetch class for designing the certain part of the application that
    // contains related objects and methods
    class Sketch {
        SketchDriver* sketch_driver;
        std::size_t id_;
    public:
        Sketch() : sketch_driver(nullptr), id_(0) {}

        void setID(std::size_t id) {
            id_ = id;
        }

        virtual void update() {}
        virtual void draw() {}

        virtual ~Sketch() {};
    };
}