CXX = g++
CXXFLAGS = -Wall -g -MD
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
BUILDDIR = build

VPATH := $(BUILDDIR)

all: game

game: main.o Application.o SketchDriver.o Sketch.o GameSketch.o BasicSketch.o GraphicalDriver.o GraphicalObject.o CircleShape.o
	$(CXX) -o $@ $^ $(SFMLFLAGS)

# Targets for all components of this engine
SketchDriver.o: SketchDriver/SketchDriver.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

BasicSketch.o: SketchDriver/BasicSketch.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

Sketch.o: SketchDriver/Sketch.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

Application.o: Application/Application.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

GraphicalDriver.o: GraphicalDriver/GraphicalDriver.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

GraphicalObject.o: GraphicalDriver/GraphicalObject.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

# Targets to compile code to test this engine

GameSketch.o: GameSketch.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

CircleShape.o: GraphicalDriver/Shapes/CircleShape.cpp
	$(CXX) -c -o $(BUILDDIR)/$@ $< $(CXXFLAGS)

# Delete all object files, executable file and *.d (include files)
clean:
	rm -rf game $(BUILDDIR)/*.o $(BUILDDIR)/*.d

-include *.d