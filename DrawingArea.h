#ifndef DRAWING_AREA_H
#define DRAWING_AREA_H

namespace Scad {
    class DrawingArea {
        private:
            GtkWidget* box1;
            GtkWidget* box2;
            GtkWidget* hbar;
            GtkWidget* vbar;
            GtkWidget* glarea;

        public:
            void build();
            GtkWidget* get_widget();

    };
}

#endif
