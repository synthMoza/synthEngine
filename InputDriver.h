#pragma once

#include <vector>
#include "GraphicalLibrary.h"

namespace se {
	const int keys_number = 59;
	const int mkeys_number = 3;

	// The list of all keys on the keyboard 
	enum keys {
		Unknown = -1, A = 0, B, C,
		D, E, F, G,
		H, I, J, K,
		L, M, N, O,
		P, Q, R, S,
		T, U, V, W,
		X, Y, Z, Num0,
		Num1, Num2, Num3, Num4,
		Num5, Num6, Num7, Num8,
		Num9, Escape, LControl, LShift,
		LAlt, LSystem, RControl, RShift,
		RAlt, RSystem, Menu, LBracket,
		RBracket, Semicolon, Comma, Period,
		Quote, Slash, Backslash, Tilde,
		Equal, Hyphen, Space, Enter,
		Backspace, Tab, PageUp, PageDown,
		End, Home, Insert, Delete,
		Add, Subtract, Multiply, Divide,
		Left, Right, Up, Down,
		Numpad0, Numpad1, Numpad2, Numpad3,
		Numpad4, Numpad5, Numpad6, Numpad7,
		Numpad8, Numpad9, F1, F2,
		F3, F4, F5, F6,
		F7, F8, F9, F10,
		F11, F12, F13, F14,
		F15, Pause, KeyCount, Dash = Hyphen,
		BackSpace = Backspace, BackSlash = Backslash, SemiColon = Semicolon, Return = Enter
	};

	// Structure that describes the state of the specific key
	struct keyInfo {
		keys code; // the code of the key
		bool released; // true if the key was released, otherwise false
		bool pressed; // true if the key is pressed, otherwise false

		// Default constroctor for keyInfo
		keyInfo() : code(Unknown), released(false), pressed(false) {}
	};

	// List of all mouse keys
	enum mkeys {Left, Right, Middle};

	struct mkeyInfo {
		mkeys code; // the code of the mouse key
		bool released; // true if the mouse key is released, otherwise false
		bool pressed; // true if the mouse key is pressed, otherwise false

		mkeyInfo() : code(Left), released(false), pressed(false) {}
	};

	// The class to control keyboard and mouse
	class InputDriver {
		// Information about each key in the vector
		std::vector<keyInfo> keys_info;
		// Information about each mouse key in the vector
		std::vector<mkeyInfo> mkeys_info;
	public:
		// Default constroctur for initializing all keys properly
		InputDriver();
		// Handle the given event to extract information about keys
		void handleEvent(sf::Event& event);
	};

	// The class for user interface to keyboard and mouse
	class InputAssistant {

	};
}