#include "DrawingArea.h"

using namespace Scad;

/* The drawing area consists of a GtkGlArea plus the 
 * scrollbars
 */
void DrawingArea::build() {
    box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    
    gtk_box_pack_start(GTK_BOX(box2), glarea, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(box2), vbar, TRUE, TRUE, 5);

    gtk_box_pack_start(GTK_BOX(box1), box2, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(box1), hbar, FALSE, FALSE, 5);
}

GtkWidget* DrawingArea::get_widget() {
    return box1;
}

