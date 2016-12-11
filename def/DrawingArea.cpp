#include "DrawingArea.h"

using namespace Scad;

/* The drawing area consists of a GtkGlArea plus the 
 * scrollbars
 */

DrawingArea::DrawingArea() {
    glarea = gtk_gl_area_new();

    hbar = gtk_scrollbar_new(GTK_ORIENTATION_HORIZONTAL, NULL);
    vbar = gtk_scrollbar_new(GTK_ORIENTATION_VERTICAL, NULL);

    box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    
    gtk_box_pack_start(GTK_BOX(box2), glarea, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box2), vbar, FALSE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(box1), box2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box1), hbar, FALSE, FALSE, 0);
}

GtkWidget* DrawingArea::get_widget() {
    return box1;
}

DrawingArea::~DrawingArea() {

}

