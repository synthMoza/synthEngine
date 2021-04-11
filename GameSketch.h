#pragma once

#include "TimeDriver/TimeDriver.h"
#include "SketchDriver/Sketch.h"
#include "GraphicalDriver/Shapes/CircleShape.h"
#include "InputDriver/InputDriver.h"
#include "GraphicalDriver/Sprite/Sprite.h"

using namespace se;

class GameSketch : public Sketch {
    CircleShape* circle_shape_;
    Sprite* sprite_;
public:  
    GameSketch();

    void update() override;

    virtual ~GameSketch();
};
