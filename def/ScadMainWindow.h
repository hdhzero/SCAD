#ifndef SCAD_MAIN_WINDOW_H
#define SCAD_MAIN_WINDOW_H

#include "SchematicGui.h"
#include "DrawingArea.h"

namespace Scad {
    class ScadMainWindow {
        private:
            SchematicGui* schematic_gui;
            DrawingArea* drawing_area;
            GtkApplication* app;
            GtkWidget* main_window;

        public:
            ScadMainWindow();
            ~ScadMainWindow();

        public:
            void run(int argc, char* argv[]);
            void set_schematic_view();

        public:
            void build_main_window();
    };
}

#endif
