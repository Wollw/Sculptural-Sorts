#include <stdlib.h>
#include "shader.h"
#include "util.h"

program_type create_shader_program_from_file(char *vertpath, char *fragpath) {
    GLchar *vertsrc = read_shader_file(vertpath);
    GLchar *fragsrc = read_shader_file(fragpath);
    program_type shader = create_shader_program(vertsrc, fragsrc);
    free(vertsrc);
    free(fragsrc);
    return shader;
}

program_type create_shader_program(const GLchar *vertsrc, const GLchar *fragsrc) {
    program_type shader;

    /* Build the program */
    shader.vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader.vert, 1, &vertsrc, 0);
    glCompileShader(shader.vert);
    CHECK_GL();

    shader.frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader.frag, 1, &fragsrc, 0);
    glCompileShader(shader.frag);
    CHECK_GL();

    shader.prog = glCreateProgram();
    glAttachShader(shader.prog, shader.vert);
    glAttachShader(shader.prog, shader.frag);
    glLinkProgram(shader.prog);
    CHECK_GL();

    return shader;

}
