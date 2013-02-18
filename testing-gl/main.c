#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include <pthread.h>
#include <semaphore.h>

#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

#include "util.h"
#include "shader.h"

#include "../src/sorts/sorts.h"
#include "../src/util.h"

volatile int position;
volatile int updated = 0;

int program;
GLuint vertexBuffer;
GLuint vPosition;
GLuint uColor;
GLuint uOffset;

static const GLfloat vertex_data[] = {
    -0.5, -0.5, 0.0,
    -0.5,  0.5, 0.0,
     0.5, -0.5, 0.0,
     0.5,  0.5, 0.0
};

/* Function executed for each step of the sorting algorithm.
 * Prints to stdout for testing.
 *      int a[]    -- The current state of the array being sorted.
 *      size_t len -- The length of the array.
 *      size_t pos -- The position of the sorting cursor in the array. */
void display_sort_state(uint8_t a[], uint8_t len, uint8_t pos) {
    while (updated);
    uint8_t i;
    for (i = 0; i < len; i++)
        printf("%5s  ", i == pos ? "v" : " ");
    puts("");
    for (i = 0; i < len; i++) {
        printf(i == len - 1? "%5d" : "%5d, ", a[i]);
    }
    puts("");
    position = pos;
    updated = 1;
    sleep(1);
}

uint8_t a[] = {
    0, 1, 2, 1, 0, 2, 2, 0
};

const GLfloat colors[3][4] = {
    {0.0, 1.0, 0.0, 0.0},
    {0.0, 1.0, 1.0, 0.0},
    {0.0, 0.0, 1.0, 0.0}
};

void *sort_thread_fn(void *v) {
    SORT_APPLY(ALGORITHM, a, display_sort_state);
    puts("done");
}

void draw(void) {
    puts("");
    puts("REDRAWING");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // Draw sorting position.
    for (uint8_t i = 0; i < sizeof(a); i++) {
        float color = i == position ? 1 : 0.25;
        glUniform4f(uColor, color, color, color , 1.0);
        glUniform2f(uOffset, i * 1.1, +0.25);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    // Draw sorting array.
    for (uint8_t i = 0; i < sizeof(a); i++) {
        float r = colors[a[i]][0];
        float g = colors[a[i]][1];
        float b = colors[a[i]][2];
        glUniform4f(uColor, r, g, b, 1);
        glUniform2f(uOffset, i * 1.1, -0.25);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glFlush();

}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
}

void idle(void) {
    if (updated)
        glutPostRedisplay();
    updated = 0;
}

int main(int argc, char **argv) {
    int w = 720;
    int h = 480;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(w, h);
    int wd = glutCreateWindow("Sorting Test");
    glutDisplayFunc(draw);
    glutReshapeFunc(resize);
    glutIdleFunc(idle);

    program = create_shader_program_from_file("shader.vert", "shader.frag").prog;
    vPosition = glGetAttribLocation(program, "vPosition");
    uColor = glGetUniformLocation(program, "uColor");
    uOffset = glGetUniformLocation(program, "uOffset");
    glEnableVertexAttribArray(vPosition);
    CHECK_GL();

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CHECK_GL();

    pthread_t pth;
    pthread_create(&pth, NULL, sort_thread_fn, NULL);

    glutMainLoop();

    pthread_join(pth, NULL);

    return 0;
}
