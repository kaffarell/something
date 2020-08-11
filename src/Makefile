libs = $(wildcard ./*/*.cpp)
main = $(wildcard ./*.cpp)

debug: $(libs) $(main)
	g++ $(libs) $(main) -o debug `pkg-config --cflags --libs sdl2`
