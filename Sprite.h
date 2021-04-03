#pragma once

#include "GraphicalDriver/GraphicalObject.h"
#include "GraphicalDriver/GraphicalDriver.h"

namespace se {
	// Sprite class that allows to draw any image loaded into the program
	class Sprite : public GraphicalObject {
		sf::Sprite* sprite_;
	public:
		Sprite();

		// Assosiates the texture to this sprite
		void setTexture(unsigned int ID);

		virtual ~Sprite();
	};
}