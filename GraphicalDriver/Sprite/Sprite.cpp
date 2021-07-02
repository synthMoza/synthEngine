#include "Sprite.h"

using namespace se;

Sprite::Sprite() :  sprite_(new sf::Sprite) {
	object_ = sprite_; // initialize sf::Drawable pointer
	size_object_ = sprite_; // initialize sf::Transformable pointer
}

void Sprite::setTexture(unsigned int ID) {
	sprite_->setTexture(*(GraphicalAssistant::getTexture(ID)->texture_));
}

void Sprite::setTextureRect(const IntRect& rect) {
	Vector2i left_up = rect.left_up_vertex_;
	sprite_->setTextureRect(sf::IntRect{left_up.x_, left_up.y_, rect.getWidth(), rect.getHeight()});
}

Sprite::~Sprite() {
	delete sprite_;
}