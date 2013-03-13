#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

#include "util.h"
#include "shader.h"

#include "../../src/sorts/sorts.h"
#include "../../src/util.h"

/***********************/
/* Shared Declarations */
/***********************/
/** Yeah, this should be implemented with a mutex... I'm being bad here
 * because I want to use the same source as the AVR code for testing
 * purposes and don't want to litter those files with preprocessor code...
 */
volatile int position;         // current sort position.
volatile bool updated = false; // flag to trigger redraw
uint8_t a[8];         // sorting array

/*******************************/
/* Sorting Thread Declarations */
/*******************************/
void *sort_thread_fn(void *);
void sort_apply_fn(uint8_t *, uint8_t, uint8_t);

/*****************************/
/* OpenGL Thread Declaration */
/*****************************/
void draw(void);
void resize(int, int);
void idle(void);

GLint program;
GLint vertexBuffer;
GLint vPosition;
GLint uColor;
GLint uOffset;

static const GLfloat vertex_data[] = { 
    -0.5, -0.5, 0.0,
    -0.5,  0.5, 0.0,
     0.5, -0.5, 0.0,
     0.5,  0.5, 0.0
};

const GLfloat colors[3][4] = {
    {0.5, 1.0, 0.5, 0.0},   // Green
    {0.0, 1.0, 1.0, 0.0},   // Cyan
    {0.5, 0.5, 1.0, 0.0}    // Blue
};


int main(int argc, char **argv) {
    /* GLUT setup */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    int wd = glutCreateWindow("Sorting Test");
    glutDisplayFunc(draw);
    glutReshapeFunc(resize);
    glutIdleFunc(idle);

    /* GLSL program setup */
    program = create_shader_program_from_file("res/shader.vert", "res/shader.frag").prog;
    vPosition = glGetAttribLocation(program, "vPosition");
    uColor = glGetUniformLocation(program, "uColor");
    uOffset = glGetUniformLocation(program, "uOffset");
    glEnableVertexAttribArray(vPosition);
    CHECK_GL();

    /* Copy vertex data to GPU */
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CHECK_GL();


    /* Create sorting thread*/
    pthread_t pth;
    pthread_create(&pth, NULL, sort_thread_fn, NULL);

    /* Start OpenGL loop */
    glutMainLoop();

    pthread_join(pth, NULL);
    return 0;
}

/***********************/
/* Sorting Thread Code */
/***********************/

/* Main function for the sorting thread. */
void *sort_thread_fn(void *v) {
    srand(time(0));
    for(;;) {
        for (uint8_t i = 0; i < LENGTH(a); i++) {
            a[i] = rand() % 3;
        }
        SORT_APPLY(ALGORITHM, a, sort_apply_fn);
        updated = true;
        position = -1;
        sleep(3);
    }
}

/* Function executed for each step of the sorting algorithm.
 * Prints to stdout for testing.
 *      int a[]    -- The current state of the array being sorted.
 *      size_t len -- The length of the array.
 *      size_t pos -- The position of the sorting cursor in the array. */
void sort_apply_fn(uint8_t a[], uint8_t len, uint8_t pos) {
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
    updated = true;
    sleep(1);
}

/**********************/
/* OpenGL Thread Code */
/**********************/

void draw(void) {

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

    updated = false;
}

void resize(int w, int h) {
    if (w < h)
        glViewport(0, 0, w, w);
    else
        glViewport(0, 0, h, h);

}

void idle(void) {
    if (updated)
        glutPostRedisplay();
}

