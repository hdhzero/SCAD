all:
	g++ -g `pkg-config --cflags gtk+-3.0` -o scad gui.cpp `pkg-config --libs gtk+-3.0` -lGL
