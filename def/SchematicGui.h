#ifndef SCHEMATIC_GUI_H
#define SCHEMATIC_GUI_H

#include "DrawingArea.h"

namespace Scad {
    class SchematicGui {
        private:
            DrawingArea* drawing_area;
            GtkWidget* side_toolbars;
            GtkWidget* main_box;

        public:
            SchematicGui();

        public:
            GtkWidget* get_widget();
            void set_drawing_area(DrawingArea* ptr);
    };
}

#endif
