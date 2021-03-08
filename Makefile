CXX = g++
CXXFLAGS = -Wall -g -MD
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: test

test: main.o Application.o SketchDriver.o Sketch.o BasicSketch.o GameSketch.o
	$(CXX) -o $@ $^ $(SFMLFLAGS)

%.o: %.c
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -rf test *.o *.d

-include *.d