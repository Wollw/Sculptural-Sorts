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

/* Creates a shader program from the source strings at vertsrc and fragsrc. */
program_type create_shader_program(const GLchar *vertsrc, const GLchar *fragsrc);

/* Creates a shader program from the source in files at vspath and fspath. */
program_type create_shader_program_from_file(char *vspath, char *fspath);

#endif
