#include "Engine.h"

using namespace se;

int main() {
    Application app(600, 800, "Application");
    app.changeMode(Mode::Close | Mode::Titlebar);
    app.launch(new BasicSketch);

    return 0;
}

