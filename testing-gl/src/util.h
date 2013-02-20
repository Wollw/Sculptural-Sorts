#ifndef TEST_UTIL_H
#define TEST_UTIL_H
#include <assert.h>
#include <stdio.h>
#include <GL/gl.h>

#define CHECK_GL() (assert(glGetError() == 0))

GLchar *read_shader_file(char *path);

#endif
