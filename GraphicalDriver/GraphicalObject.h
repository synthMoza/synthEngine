#pragma once

#include "../GraphicalLibrary.h"

namespace se {
    // Base class for all objects in the game that can be drawn and updated. Determines
    // basic interface for such objects. All such objects should be inherited from this base class.

    // TODO
    class GraphicalObject {
    protected:
        sf::Drawable* object_; // the pointer to SFML drawable object for GraphicalDriver
    public:
        GraphicalObject();

        virtual ~GraphicalObject();

        friend class GraphicalDriver;
    };
}