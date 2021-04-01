#include "TimeDriver.h"

using namespace se;

void TimeDriver::restartClock() {
	clock_.restart();
}

unsigned long TimeDriver::getElapsedTime(timeFormat format) {
	switch (format) {
	case S:
		return clock_.getElapsedTime().asSeconds();
	case MS:
		return clock_.getElapsedTime().asMilliseconds();
	case US:
		return clock_.getElapsedTime().asMicroseconds();
	default:
		throw std::runtime_error("Unknown time format!");
	}
}

unsigned long TimeDriver::getFrameTime(timeFormat format) {
	switch (format) {
	case S:
		return frame_time_ * 10e-6;
	case MS:
		return frame_time_ * 10e-3;
	case US:
		return frame_time_;
	default:
		throw std::runtime_error("Unknown time format!");
	}
}

void TimeDriver::setFrameTime(unsigned long frame_time, timeFormat format) {
	switch (format) {
	case MS:
		frame_time_ = frame_time * 10e3;
		break;
	case US:
		frame_time_ = frame_time;
		break;
	case S:
	default:
		throw std::runtime_error("Wrong time format for frame time!");
		break;
	}
}

// Initialize static pointer to TimeDriver
TimeDriver* TimeAssistant::time_driver_ = nullptr;

unsigned long TimeAssistant::getFrameTime(timeFormat format) {
	return time_driver_->getFrameTime(format);
}