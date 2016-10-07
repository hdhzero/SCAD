#include <gtk/gtk.h>
#include <GL/glu.h>
#include <gdk/gdk.h>
#include <iostream>
using namespace std;

static gboolean
render (GtkGLArea *area, GdkGLContext *context)
{
  // inside this function it's safe to use GL; the given
  // #GdkGLContext has been made current to the drawable
  // surface used by the #GtkGLArea and the viewport has
  // already been set to be the size of the allocation

  // we can start by clearing the buffer
  //cout << gdk_gl_context_is_legacy(context) << endl;
  glClearColor (0, 0, 0, 0);
  glClear (GL_COLOR_BUFFER_BIT);

  // draw your object
//  draw_an_object ();

  // we completed our drawing; the draw commands will be
  // flushed at the end of the signal emission chain, and
  // the buffers will be drawn on the window
  return TRUE;
}

void close_window() {
    gtk_main_quit();
}

GtkWidget* create_main_window(GtkApplication* app) {
    GtkWidget* window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "VHDL Sim");

    g_signal_connect(window, "destroy", G_CALLBACK(close_window), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 4);

    return window;
}

void build_gui(GtkApplication* app, gpointer data) {
    GtkWidget* window;
    GtkWidget* gl_area;

    window = create_main_window(app);
    gl_area = gtk_gl_area_new();

    g_signal_connect (gl_area, "render", G_CALLBACK (render), NULL);

    gtk_container_add(GTK_CONTAINER(window), gl_area);
    gtk_widget_show_all(window);
}

void activate(GtkApplication* app, gpointer data) {
    build_gui(app, data);
}

int run_gui(int argc, char* argv[]) {
    GtkApplication* app;
    int status;

    app = gtk_application_new("org.gtk.scad.sim", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

int main(int argc, char* argv[]) {
    return run_gui(argc, argv);
}
