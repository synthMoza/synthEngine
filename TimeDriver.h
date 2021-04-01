#pragma once

#include "GraphicalLibrary.h"

namespace se {
	// The format to return time from TimeDriver class
	enum timeFormat {S, MS, US };

	// The class that works with the time in the application.
	class TimeDriver {
		// The format of the output time
		sf::Clock clock_;
		// Time since the last frame
		unsigned long frame_time_;
	public:
		TimeDriver() : frame_time_ (0) {}
		// Restarts the clock
		void restartClock();
		// Return the time in the given format that has passed since the last restart
		unsigned long getElapsedTime(timeFormat format = US);
		// Get time since the last frame
		unsigned long getFrameTime(timeFormat format = US);
		// Set time since the last frame
		void setFrameTime(unsigned long frame_time, timeFormat format = US);
	};

	// The assistant class to get frame time from TimeDriver
	class TimeAssistant {
		static TimeDriver* time_driver_;
	public:
		// Assistant method for getting frame time
		static unsigned long getFrameTime(timeFormat format = US);

		friend class Application;
	};
}