#include "SchematicGui.h"

using namespace Scad;

SchematicGui::SchematicGui() {
    side_toolbars = gtk_toolbar_new();
    main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    gtk_toolbar_insert(GTK_TOOLBAR(side_toolbars), gtk_tool_button_new(gtk_image_new_from_file("img/xor.png"), "t"), 0);

    gtk_box_pack_start(GTK_BOX(main_box), side_toolbars, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_box), drawing_area->get_widget(), TRUE, TRUE, 0);
}

GtkWidget* SchematicGui::get_widget() {
    return main_box;
}

void SchematicGui::set_drawing_area(DrawingArea* ptr) {
    drawing_area = ptr;
}
