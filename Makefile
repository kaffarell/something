files = $(wildcard ./*.cpp)

debug: $(files) 
	g++ $(files) -o debug `pkg-config --cflags --libs sdl2`