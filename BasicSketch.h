#pragma once

#include "Sketch.h"

namespace se {

    class BasicSketch : public Sketch {
    public:  
        BasicSketch();

        void update() override;
        void draw() override;

        virtual ~BasicSketch();
    };
}