#include "InputDriver.h"

using namespace se;

InputDriver::InputDriver() {
	// Reserve place for each key
	keys_info.resize(keys_number);
	mkeys_info.resize(mkeys_number);

	for (int i = 0; i < keys_number; ++i) {
		keys_info.at(i).code = static_cast<keys>(i);
	}

	for (int i = 0; i < mkeys_number; ++i) {
		mkeys_info.at(i).code = static_cast<mkeys>(i);
	}
}

void InputDriver::updateKeys() {
	// Unpress and unrelease all keys from the previous frame
	for (auto& key : keys_unpress) {
		keys_info.at(key).pressed = false;
	}
	for (auto& key : keys_unrelease) {
		keys_info.at(key).released = false;
	}
	// Unpress and unrelease all mouse keys from the previous frame
	for (auto& mkey : mkeys_unpress) {
		mkeys_info.at(mkey).pressed = false;
	}
	for (auto& mkey : mkeys_unrelease) {
		mkeys_info.at(mkey).released = false;
	}
}

void InputDriver::handleEvent(sf::Event& event) {
	// Handle the given event by everything related to keyboard and mouse
	switch (event.type) {
	// Keyboard events
	case sf::Event::EventType::KeyPressed:
		// Some key was pressed
		keys_info.at(event.key.code).pressed = true; // pressed at this frame
		keys_info.at(event.key.code).held = true; // became held

		keys_unpress.push_back(static_cast<keys>(event.key.code)); // unpress in the next frame
		break;
	case sf::Event::EventType::KeyReleased:
		// Some key was released
		keys_info.at(event.key.code).released = true; // released in this frame
		keys_info.at(event.key.code).held = false; // no longer held

		keys_unrelease.push_back(static_cast<keys>(event.key.code)); // unrelease in the next frame
		break;
	// Mouse events (TO DO)
	case sf::Event::EventType::MouseButtonPressed:
		// Mosue button was pressed
		mkeys_info.at(event.mouseButton.button).pressed = true;
		mkeys_info.at(event.mouseButton.button).held = true;

		mkeys_unpress.push_back(static_cast<mkeys>(event.mouseButton.button));
		break;
	case sf::Event::EventType::MouseButtonReleased:
		// Mouse button was released
		mkeys_info.at(event.mouseButton.button).released = true;
		mkeys_info.at(event.mouseButton.button).held = false; // no longer pressed

		mkeys_unrelease.push_back(static_cast<mkeys>(event.mouseButton.button));
		break;
	}
}

bool InputDriver::isKeyHeld(keys key) {
	return keys_info.at(key).held;
}

bool InputDriver::isKeyPressed(keys key) {
	return keys_info.at(key).pressed;
}

bool InputDriver::isKeyReleased(keys key) {
	return keys_info.at(key).released;
}

bool InputDriver::isMKeyHeld(mkeys mkey) {
	return mkeys_info.at(mkey).held;
}
bool InputDriver::isMKeyPressed(mkeys mkey) {
	return mkeys_info.at(mkey).pressed;
}
bool InputDriver::isMKeyReleased(mkeys mkey) {
	return mkeys_info.at(mkey).released;
}

// Initialize static variable for input assistant
InputDriver* InputAssistant::input_driver = nullptr;

bool InputAssistant::isKeyHeld(keys key) {
	return input_driver->isKeyHeld(key);
}
bool InputAssistant::isKeyPressed(keys key) {
	return input_driver->isKeyPressed(key);
}
bool InputAssistant::isKeyReleased(keys key) {
	return input_driver->isKeyReleased(key);
}

bool InputAssistant::isMKeyHeld(mkeys mkey) {
	return input_driver->isMKeyHeld(mkey);
}
bool InputAssistant::isMKeyPressed(mkeys mkey) {
	return input_driver->isMKeyPressed(mkey);
}
bool InputAssistant::isMKeyReleased (mkeys mkey) {
	return input_driver->isMKeyReleased(mkey);
}