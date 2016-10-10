#include <gtkmm.h>

#include "ScadMainWindow.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.scad");

    Scad::ScadMainWindow scad_main_window;
    return app->run(scad_main_window);
}
