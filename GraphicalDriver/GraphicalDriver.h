#pragma once

#include "../GraphicalLibrary.h"
#include "GraphicalObject.h"
#include "../Utilities/Vector2.h"
#include "../Application/Application.h"

namespace se {
    class Application;

    class GraphicalDriver {
        sf::RenderWindow* window_;
    public:
        GraphicalDriver(sf::RenderWindow* window);

        void draw(GraphicalObject* graphical_object);

        ~GraphicalDriver();
    };

    class GraphicalAssistant {
        static GraphicalDriver* graphical_driver;
    public:
        // Draw the given object
        static void draw(GraphicalObject* graphical_object);
        // Get the current resolution of the opened window
        static Vector2u getResolution();

        friend class Application;
    };
}