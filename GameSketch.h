#pragma once

#include "Sketch.h"

namespace se {

    class GameSketch : public Sketch {
    public:  
        GameSketch();

        void update() override;
        void draw() override;

        virtual ~GameSketch();
    };
}