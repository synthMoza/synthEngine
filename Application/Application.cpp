#include "Application.h"

using namespace se;

// Static vector initializing (window resolution)
Vector2u Application::resolution_ = Vector2u{0, 0};

Application::Application(unsigned int resolution_width, unsigned int resolution_height, const std::string& title) :
        window_ (new sf::RenderWindow{sf::VideoMode{resolution_width, resolution_height}, title}),
        mode_ (0),
        title_ (title),
        sketch_driver_ {},
        graphical_driver_ {window_},
        time_driver_{},
        input_driver_{} {
    // Initialize assistants except sketch assistant
    SketchAssistant::sketch_driver_ = &sketch_driver_;
    GraphicalAssistant::graphical_driver = &graphical_driver_;
    TimeAssistant::time_driver_ = &time_driver_;
    InputAssistant::input_driver = &input_driver_;

    resolution_ = Vector2u{resolution_width, resolution_height};
}

void Application::changeMode(int mode) {
    mode_ = mode;
    window_->create(sf::VideoMode{resolution_.x_, resolution_.y_}, title_, mode_);
}

void Application::changeTitle(const std::string& string) {
    title_ = string;
    window_->setTitle(title_);
}

void Application::launch() {
    sf::Event event;

    unsigned long time = 0;
    unsigned long old_time = 0;
    unsigned long frames = 0;

    time_driver_.restartClock();
    while (window_->isOpen()) {
        if (sketch_driver_.getSketches() == 0) {
            window_->close();
        }

        while (window_->pollEvent(event)) {
            // Handle all events
            input_driver_.handleEvent(event);

            switch (event.type) {
                case sf::Event::EventType::Closed:
                    window_->close();
                    break;
            }
        }

        window_->clear();

        // Update active sketches
        sketch_driver_.updateSketches();
        // Collect all objects
        sketch_driver_.collectObjects();

        // Draw all objects on the screen
        graphical_driver_.drawObjects();

        // Display all objects on the screen
        window_->display();
        // Update state of keys
        input_driver_.updateKeys();

        // Delete skectes that are no longer needed
        sketch_driver_.deleteSketches();
        // Clear objects
        graphical_driver_.clearObjects();

        // Count the passed time
        time = time_driver_.getElapsedTime();
        //std::cout << "Time: " << time << std::endl;
        time_driver_.setFrameTime(time - old_time);
        old_time = time;

        if (old_time >= 1000000) {
            // One second passed
            // std::cout << "FPS: " << frames << std::endl;
            frames = 0;
            old_time = 0;
            time = 0;
            time_driver_.restartClock();
        } else
            frames++; // the frames ended
    }
}

Application::~Application() {
    delete window_;
}