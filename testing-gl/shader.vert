attribute vec4 vPosition;
uniform vec2 uOffset;

void main(void) {
    mat4 projMat = mat4(
        0.2, 0.0, 0.0,-0.75,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    );

    vec4 pos = vPosition;
    pos.x = (pos.x + uOffset.x);
    pos.y = (pos.y + uOffset.y);
    gl_Position = pos * projMat;
}

