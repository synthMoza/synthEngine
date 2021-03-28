#pragma once

#include "Sketch.h"

#include <vector>

namespace se {
    // The driver class used for controlling sketches
    class SketchDriver {
        // The vector had been chosen because usually there are no a lot of sketches in the game to use list for fast removal
        std::vector<Sketch*> sketches_; // the vector of all scathes in the game
        std::vector<Sketch*> to_delete_; // sketches to be deleted before updating sketches
    public:
        // Default constructor for the sketch driver, creates the first empty scetch
        SketchDriver();

        // Adds the sketch to the driver
        void addSketch(Sketch* sketch);

        // Updates all active sketches
        void updateSketches();
        // Draws all sketches
        void drawSketches();

        // Removes sketch from the driver
        void removeSketch(Sketch* sketch);

        ~SketchDriver();
    };

    // The class that allows to add new sketches to the driver
    class SketchAssistant {
        static SketchDriver* sketch_driver_; // the pointer to the driver
    public:
        static void addSketch(Sketch* sketch); // add sketch
        static void removeSketch(Sketch* sketch); // remove sketch

        friend class Application;
    };
}