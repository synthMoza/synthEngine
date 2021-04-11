#include "Sketch.h"

using namespace se;

void Sketch::draw() {
	for (auto it_layer = graphical_objects_.begin(); it_layer != graphical_objects_.end(); ++it_layer) {
		// Iterate each layer
		if (!it_layer->empty()) {
			for (auto it = it_layer->begin(); it != it_layer->end(); ++it) {
				GraphicalAssistant::drawObject(**it);
			}
		}
	}
}

void Sketch::addObject(GraphicalObject* object, unsigned int layer) {
	graphical_objects_.at(layer).push_back(object);
}

Sketch::~Sketch() {
	for (auto it_layer = graphical_objects_.begin(); it_layer != graphical_objects_.end(); ++it_layer) {
		// Iterate each layer
		if (!it_layer->empty()) {
			for (auto it = it_layer->begin(); it != it_layer->end(); ++it) {
				delete *it;
			}
		}
	}
}