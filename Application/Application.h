#pragma once

#include "../Utilities/Vector2.h"
#include "../SketchDriver/Sketch.h"
#include "../GraphicalLibrary.h"

#include "../GraphicalDriver/GraphicalDriver.h"
#include "../TimeDriver/TimeDriver.h"
#include "../InputDriver/InputDriver.h"
#include "../SketchDriver/SketchDriver.h"

namespace se {
    // Defines the style of the opened window
    enum Mode {
        None        = 0,
        Titlebar    = 1 << 0,
        Resize      = 1 << 1,
        Close       = 1 << 2,
        Fullscreen  = 1 << 3,

        Default = Titlebar | Resize | Close
    };

    // The main class for launching the app
    class Application {
        // The pointer to the main window 
        sf::RenderWindow* window_;
        // Title of the application window
        std::string title_;
        // Current mode of this application window
        int mode_;
        // The resolution of the window
        static Vector2u resolution_;

        // Drivers
        SketchDriver sketch_driver_;
        GraphicalDriver graphical_driver_;
        TimeDriver time_driver_;
        InputDriver input_driver_;
    public:
        Application(unsigned int resolution_width, unsigned int resolution_height, const std::string& title);
        
        // Returns the current resolution of the opened window
        static Vector2u getResolution() {
            return resolution_;
        }
        // Change the mode of the application window
        void changeMode(int mode);
        // Change the title of the application window
        void changeTitle(const std::string& string);
        // Launch the application - the main loop of the application with the given sketch
        void launch();

        ~Application();
    };
}