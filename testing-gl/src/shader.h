#ifndef SHADER_H
#define SHADER_H

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

typedef struct {
    GLuint vert;
    GLuint frag;
    GLuint prog;
} program_type;

program_type create_shader_program(const GLchar *vertsrc, const GLchar *fragsrc);
program_type create_shader_program_from_file(char *vspath, char *fspath);

#endif
