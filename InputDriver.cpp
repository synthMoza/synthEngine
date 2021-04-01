#include "InputDriver.h"

using namespace se;

InputDriver::InputDriver() {
	// Reserve place for each key
	keys_info.reserve(keys_number);
	mkeys_info.reserve(mkeys_number);

	for (int i = 0; i < keys_number; ++i) {
		keys_info.at(i).code = static_cast<keys>(i);
	}

	for (int i = 0; i < mkeys_number; ++i) {
		mkeys_info.at(i).code = static_cast<mkeys>(i);
	}
}

void InputDriver::handleEvent(sf::Event& event) {
	switch (event.type) {
	case sf::Event::EventType::KeyPressed:
		// Some key was pressed
		keys_info.at(event.key.code).pressed = true;
		break;
	case sf::Event::EventType::KeyReleased:
		// Some key was released
		keys_info.at(event.key.code).released = true;
		keys_info.at(event.key.code).pressed = false; // no longer pressed
		break;
	case sf::Event::EventType::MouseButtonPressed:
		// Mosue button was pressed
		mkeys_info.at(event.mouseButton.button).pressed = true;
		break;
	case sf::Event::EventType::MouseButtonReleased:
		// Mouse button was released
		mkeys_info.at(event.mouseButton.button).released = true;
		mkeys_info.at(event.mouseButton.button).pressed = false; // no longer pressed
		break;
	}
}