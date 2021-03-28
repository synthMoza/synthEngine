#pragma once

#include "../SketchDriver/SketchDriver.h"
#include "../GraphicalDriver/GraphicalDriver.h"

#include "../GraphicalLibrary.h"

namespace se {
    // The main class for launching the app
    class Application {
        unsigned int resolution_height_; // the height of the window
        unsigned int resolution_width_; // the width of the window
        sf::RenderWindow* window_; // the pointer to the main window 
    public:
        Application(unsigned int resolution_width, unsigned int resolution_height, const std::string& title);

        // Launch the application - the main loop of the application
        void launch();

        ~Application();
    };
}