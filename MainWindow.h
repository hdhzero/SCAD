#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

namespace Scad {
    class MainWindow {
        private:
            GtkApplication* app;
            GtkWidget* window;
            SchematicGui* schematic_gui;

        public:
            void build();
            void run(int argc, char* argv[]);
    };
}

#endif
