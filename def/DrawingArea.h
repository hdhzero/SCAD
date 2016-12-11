#ifndef DRAWING_AREA_H
#define DRAWING_AREA_H

#include <gtk/gtk.h>

namespace Scad {
    class DrawingArea {
        private:
            GtkWidget* box1;
            GtkWidget* box2;
            GtkWidget* hbar;
            GtkWidget* vbar;
            GtkWidget* glarea;

        public:
            DrawingArea();
            ~DrawingArea();

        public:
            GtkWidget* get_widget();

    };
}

#endif
