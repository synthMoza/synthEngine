#pragma once

#include "../GraphicalDriver.h"
#include "../GraphicalObject.h"

#include "../../GraphicalLibrary.h"

namespace se {

    // Class for drawing simple circle shapes. To construct this class,
    // CircleShapeData must be given.
    class CircleShape final : public GraphicalObject {
        // The position of this circle on the screen
        float x_;
        float y_;
        // The radius of this circle
        float radius_;
    public:
        CircleShape();

        void setPosition(float x, float y);
        void setRadius(float radius);

        // TODO Getters, color

        ~CircleShape();
    };
}