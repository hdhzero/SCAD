#include "ScadMainWindow.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdio>

using namespace Scad;

void ScadMainWindow::build_main_area() {
    box1.pack_start(main_area_box);

    glarea.signal_render().connect(sigc::mem_fun(*this, &ScadMainWindow::on_render));

    df.set_label("bt");
    main_area_box.pack_start(df);
    main_area_box.pack_start(glarea);
}

ScadMainWindow::ScadMainWindow() {
    set_title("SCAD");
    set_size_request(800, 600);
    set_border_width(10);

    build_main_area();
    add(box1);
    show_all_children();
}

bool ScadMainWindow::on_render(const Glib::RefPtr<Gdk::GLContext>& context) {
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

    return true;
}

ScadMainWindow::~ScadMainWindow() {
    /* Empty */
}
