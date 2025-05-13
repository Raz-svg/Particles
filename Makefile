CXX = g++
CXXFLAGS = -std=c++11 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lSDL2_gfx
SOURCES = main.c++ imageprocessing.c++ 
EXECUTABLE = my_game

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE)
