all: run

build:
	g++ -std=c++11 vec2DDriver.cpp functions.cpp header.cpp pixel.cpp -o test

run: build
	./test pooh.ppm out.ppm
