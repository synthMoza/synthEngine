#include "Engine.h"

#include "GameSketch.h"

using namespace se;

int main() {
    // Create application object
    Application app(600, 800, "Application");
    // Set window mode and start sketch
    app.changeMode(Mode::Close | Mode::Titlebar);
    SketchAssistant::addSketch(new GameSketch);
    // Launch the application
    app.launch();

    return 0;
}