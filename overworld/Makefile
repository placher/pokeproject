all: pokeproject

pokeproject: overworld.cpp
	g++ overworld.cpp -lSDL2 -lSDL2_image -o pokeproject

testingsound: testsound.cpp
	g++ testsound.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -o testingsound

clean:
	rm pokeproject testingsound
