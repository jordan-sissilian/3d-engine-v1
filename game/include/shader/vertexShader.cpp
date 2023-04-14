
const char *vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "out vec4 vertexColor;\n"
    "uniform mat4 matrixModel;\n"
    "uniform mat4 matrixView;\n"
    "uniform mat4 matrixProjection;\n"
    "uniform vec4 couleur;\n"
    "void main()\n"
        "{\n"
        "   gl_Position = matrixProjection * matrixView * matrixModel * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "   vertexColor = couleur;\n"
        "}\n\0";