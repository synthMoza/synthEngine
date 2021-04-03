#pragma once

#include "TimeDriver.h"
#include "SketchDriver/Sketch.h"
#include "GraphicalDriver/Shapes/CircleShape.h"
#include "InputDriver.h"
#include "Sprite.h"

using namespace se;

class GameSketch : public Sketch {
    CircleShape* circle_shape_;
    Sprite* sprite_;
public:  
    GameSketch();

    void update() override;
    void draw() override;

    virtual ~GameSketch();
};
