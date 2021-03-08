#include "Application.h"

using namespace se;

Application::Application(unsigned int resolution_width, unsigned int resolution_height, const std::string& title) :
        resolution_height_ (resolution_height),
        resolution_width_ (resolution_width),
        window_ (new sf::RenderWindow{sf::VideoMode{resolution_width_, resolution_height_}, title}) {}

void Application::launch() {
    // Create sketch driver and initialize sketch assistant
    SketchDriver sketch_driver;
    SketchAssistant::sketch_driver_ = &sketch_driver;
    // Create the only one clock
    sf::Clock clock;
    unsigned long time = 0;
    unsigned long frames = 0;

    clock.restart();
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
        time = clock.getElapsedTime().asMilliseconds();
        if (time >= 1000) {
            // One second passed
            std::cout << "FPS: " << frames << std::endl;
            frames = 0;
            clock.restart();
        } else
            frames++; // the frames ended
    }
}

Application::~Application() {
    delete window_;
}