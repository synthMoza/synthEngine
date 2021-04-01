#include "Application.h"

using namespace se;

// Static vector initializing (window resolution)
Vector2u Application::resolution_ = Vector2u{0, 0};

Application::Application(unsigned int resolution_width, unsigned int resolution_height, const std::string& title) :
        window_ (new sf::RenderWindow{sf::VideoMode{resolution_width, resolution_height}, title}) {
    resolution_ = Vector2u{resolution_width, resolution_height};
}

void Application::launch() {
    // Create sketch driver and initialize sketch assistant
    SketchDriver sketch_driver;
    SketchAssistant::sketch_driver_ = &sketch_driver;

    // Create graphical driver and initialize graphical assistant
    GraphicalDriver graphical_driver(window_);
    GraphicalAssistant::graphical_driver = &graphical_driver;
    
    // Create the TimeDriver
    TimeDriver time_driver;
    TimeAssistant::time_driver_ = &time_driver;

    unsigned long time = 0;
    unsigned long old_time = 0;
    unsigned long frames = 0;

    time_driver.restartClock();
    while (window_->isOpen()) {
        sf::Event event;

        while (window_->pollEvent(event)) {
            // Catch all events
            switch (event.type) {
                case sf::Event::EventType::Closed:
                    window_->close();
                    break;
            }
        }

        window_->clear();

        // Draw and update active sketches
        sketch_driver.updateSketches();
        sketch_driver.drawSketches();

        window_->display();

        // Count the passed time
        time = time_driver.getElapsedTime();
        time_driver.setFrameTime(time - old_time);
        old_time = time;

        if (old_time >= 10e6) {
            // One second passed
            std::cout << "FPS: " << frames << std::endl;
            frames = 0;
            old_time = 0;
            time = 0;
            time_driver.restartClock();
        } else
            frames++; // the frames ended
    }
}

Application::~Application() {
    delete window_;
}