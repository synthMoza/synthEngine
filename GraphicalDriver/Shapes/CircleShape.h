#pragma once

#include "../GraphicalDriver.h"
#include "../GraphicalObject.h"
#include "../../GraphicalLibrary.h"
#include "../Color.h"
#include "../../Utilities/Vector2.h"

namespace se {

    // Class for drawing simple circle shapes. To construct this class,
    // CircleShapeData must be given.
    class CircleShape final : public GraphicalObject {
        sf::CircleShape* circle_shape_; // the pointer to SFML circlr shape object
    public:
        CircleShape();

        // Set position of the circle's origin
        void setPosition(Vector2f pos);
        // Set circle's origin
        void setOrigin(Vector2f origin);
        // Set circle's radius
        void setRadius(float radius);
        // Set circle's filling color
        void setFillColor(const Color& color);
        // Set circle's outline color
        void setOutlineColor(const Color& color);
        // Set circle's outline thickness
        void setOutlineThickness(float thickness);
        // Move the circle by the given offset
        void move(Vector2f offset);
        // Set the scale of the circle shape
        void setScale(Vector2f scale);

        // Getters for parameters of circle shape
        Vector2f getPosition();
        Vector2f getOrigin();
        float getRadius();
        Color getFillColor();
        Color getOutlineColor();
        float getOutlineThickness();
        Vector2f getScale();

        // TODO Getters

        ~CircleShape();
    };
}