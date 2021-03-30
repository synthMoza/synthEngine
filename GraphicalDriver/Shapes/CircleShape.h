#pragma once

#include "../GraphicalDriver.h"
#include "../GraphicalObject.h"
#include "../../GraphicalLibrary.h"
#include "../Color.h"

namespace se {

    // Class for drawing simple circle shapes. To construct this class,
    // CircleShapeData must be given.
    class CircleShape final : public GraphicalObject {
        sf::CircleShape* circle_shape_; // the pointer to SFML circlr shape object
    public:
        CircleShape();

        // Set position of the circle's origin
        void setPosition(float x, float y);
        // Set circle's origin
        void setOrigin(float x, float y);
        // Set circle's radius
        void setRadius(float radius);
        // Set circle's filling color
        void setFillColor(const Color& color);
        // Set circle's outline color
        void setOutlineColor(const Color& color);
        // Set circle's outline thickness
        void setOutlineThickness(float thickness);
        // Move the circle by the given offset
        void move(float offsetX, float offsetY);

        // TODO Getters

        ~CircleShape();
    };
}