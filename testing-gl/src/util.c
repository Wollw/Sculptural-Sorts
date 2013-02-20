#include "util.h"
#include <stdlib.h>
GLchar *read_shader_file(char *path) {
    GLchar *buffer = NULL;
    long length;
    FILE *fp = fopen(path, "r");
    if (fp) {
        fseek(fp, 0, SEEK_END);
        length = ftell(fp) - 1;
        fseek(fp, 0, SEEK_SET);
        buffer = calloc(length+1,1);
        if (buffer) {
            fread(buffer, 1, length, fp);
        }
        fclose(fp);
    }
    return buffer;
}
