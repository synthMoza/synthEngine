#pragma once

#include "../GraphicalLibrary.h"
#include "GraphicalObject.h"

namespace se {

    class GraphicalDriver {
        sf::RenderWindow* window_;
    public:
        GraphicalDriver(sf::RenderWindow* window);

        void draw(GraphicalObject* graphical_object);

        ~GraphicalDriver();

        //friend class GraphicalObject;
    };

    class GraphicalAssistant {
        static GraphicalDriver* graphical_driver;
    public:
        static void draw(GraphicalObject* graphical_object);

        friend class Application;
    };
}