#pragma once

#include "SketchDriver/Sketch.h"
#include "GraphicalDriver/Shapes/CircleShape.h"

using namespace se;

class GameSketch : public Sketch {
    CircleShape* circle_shape_;
public:  
    GameSketch();

    void update() override;
    void draw() override;

    virtual ~GameSketch();
};
