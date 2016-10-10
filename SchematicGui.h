#ifndef SCHEMATIC_GUI_H
#define SCHEMATIC_GUI_H

namespace Scad {
    class SchematicGui {
        private:
            GtkWidget* main_box;
            GtkWidget* side_box;
            GtkWidget* bottom_box;
            DrawingArea* drawing_area;

        private:
            GtkWidget* build_drawing_area();

        public:
            void build();
            GtkWidget* get_widget();
    };
}

#endif
