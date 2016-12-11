#include "ScadMainWindow.h"

using namespace Scad;

void activate(GtkApplication* app, gpointer data) {
    ScadMainWindow* ptr = (ScadMainWindow*) data;

    ptr->build_main_window();
}

ScadMainWindow::ScadMainWindow() {
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK (activate), (gpointer) this);
}

ScadMainWindow::~ScadMainWindow() {
    delete drawing_area;
    delete schematic_gui;
    g_object_unref(app);
}

void ScadMainWindow::build_main_window() {
    schematic_gui = new SchematicGui();
    drawing_area = new DrawingArea();
    schematic_gui->set_drawing_area(drawing_area);
    main_window = gtk_application_window_new(app);
    gtk_window_set_title (GTK_WINDOW(main_window), "SCAD");
    gtk_window_set_default_size (GTK_WINDOW (main_window), 800, 600);

    gtk_container_add(GTK_CONTAINER(main_window), schematic_gui->get_widget());

    gtk_widget_show_all(main_window);
}

void ScadMainWindow::run(int argc, char* argv[]) {
    g_application_run (G_APPLICATION (app), argc, argv);
}
