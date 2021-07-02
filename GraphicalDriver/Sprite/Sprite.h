#pragma once

#include "../GraphicalObject.h"
#include "../GraphicalDriver.h"

#include "../../Rect.h"

namespace se {
	// Sprite class that allows to draw any image loaded into the program
	class Sprite : public GraphicalObject {
		sf::Sprite* sprite_;
	public:
		Sprite();

		// Assosiates the texture to this sprite
		void setTexture(unsigned int ID);
		// Set the texture rectangle
		void setTextureRect(const IntRect& rect);

		virtual ~Sprite();

		friend GraphicalDriver;
	};
}