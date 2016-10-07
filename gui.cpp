#define GLEW_STATIC
#include <GL/glew.h>

#include <gtk/gtk.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <gdk/gdk.h>
#include <iostream>
#include <stdio.h>
using namespace std;

static gboolean
render (GtkGLArea *area, GdkGLContext *context) {
    // inside this function it's safe to use GL; the given
    // #GdkGLContext has been made current to the drawable
    // surface used by the #GtkGLArea and the viewport has
    // already been set to be the size of the allocation

    glewExperimental = GL_TRUE;
    glewInit();

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    printf("%u\n", vertexBuffer);

    float vertices[] = {
         0.0f,  0.5f, // Vertex 1 (X, Y)
         0.5f, -0.5f, // Vertex 2 (X, Y)
        -0.5f, -0.5f  // Vertex 3 (X, Y)
    };

    char* vertexSource = 
        "#version 150\n"
        "\n"
        "in vec2 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    gl_Position = vec4(position, 0.0, 1.0);\n"
        "}\n";

    char* fragmentSource =
        "#version 150\n"
        "\n"
        "out vec4 outColor;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    outColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
        "}\n";

    GLuint vbo;
    glGenBuffers(1, &vbo); // Generate 1 buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    GLint status;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    printf("vshader: %i\n", status == GL_TRUE);
    char buffer[512];
    glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
    printf("vshader log: %s\n", buffer);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);

    glClearColor (0, 1, 0, 0);
    glClear (GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    return TRUE;
}

void close_window() {
    gtk_main_quit();
}

GtkWidget* create_main_window(GtkApplication* app) {
    GtkWidget* window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "SCAD");

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
