all:
	g++ -g -I/home/hdhzero/app/mesa/mesa-12.0.0/binaries/include `pkg-config --cflags gtk+-3.0` -o scad gui.cpp `pkg-config --libs gtk+-3.0` -L/home/hdhzero/app/mesa/mesa-12.0.0/binaries/lib -lGL -lGLEW

cpp:
	g++ -I/home/hdhzero/app/mesa/mesa-12.0.0/binaries/include ngui.cpp ScadMainWindow.cpp -o simple `pkg-config gtkmm-3.0 --cflags --libs` -L/home/hdhzero/app/mesa/mesa-12.0.0/binaries/lib -lGL -lGLEW
