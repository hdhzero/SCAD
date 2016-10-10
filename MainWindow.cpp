#include "MainWindow.h"

using namespace Scad;

void activate(GtkApplication* app, gpointer data) {
    MainWindow* ptr = (MainWindow*) data;

    ptr->build();
}

void close_window() {
    gtk_main_quit();
}

void MainWindow::build() {
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "SCAD");

    g_signal_connect(window, "destroy", G_CALLBACK(close_window), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window, 4);

    schematic_gui->build();

    gtk_container_add(GTK_CONTAINER(window), schematic_gui->get_widget());
    gtk_widget_show_all(window);
}

void MainWindow::run(int argc, char* argv[]) {
    app = gtk_application_window_new("org.gtk.scad.sim", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), (gpointer) this);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
}

