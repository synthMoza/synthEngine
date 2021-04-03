#pragma once

#include "../GraphicalLibrary.h"
#include "GraphicalObject.h"
#include "../Utilities/Vector2.h"
#include "../Application/Application.h"
#include "../Texture.h"

namespace se {
    class Application;

    class GraphicalDriver {
        sf::RenderWindow* window_; // the pointer to the opened window
        std::vector<Texture*> textures_; // the vector of all opened textures
    public:
        GraphicalDriver(sf::RenderWindow* window);

        // Draw the object in the window
        void draw(GraphicalObject* graphical_object);
        // Load the texture to the graphical driver
        // Returns the unique ID that will identify this texture
        unsigned int loadTexture(std::string path);
        // Returns the pointer to the given texture
        Texture* getTexture(unsigned int ID);

        ~GraphicalDriver();
    };

    class GraphicalAssistant {
        static GraphicalDriver* graphical_driver;
    public:
        // Draw the given object
        static void draw(GraphicalObject* graphical_object);
        // Get the current resolution of the opened window
        static Vector2u getResolution();
        // Load the texture to the graphical driver
        // Returns the unique ID that will identify this texture
        static unsigned int loadTexture(std::string path);
        // Returns the pointer to the given texture
        static Texture* getTexture(unsigned int ID);
        
        friend class Application;
    };
}