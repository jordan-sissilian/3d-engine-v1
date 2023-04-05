
const char *vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "out vec4 vertexColor;\n"
    "uniform mat4 matrix;"
    "void main()\n"
        "{\n"
        "   gl_Position = matrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "   vertexColor = vec4(0.0f, 0.5f, 0.5f, 1.0f);"
        "}\0";

const char *vertexShaderSource1 = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "out vec4 vertexColor;\n"    
    "uniform mat4 matrix;"
    "void main()\n"
        "{\n"
        "   gl_Position = matrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "   vertexColor = vec4(0.5f, 0.f, 0.5f, 1.0f);"
        "}\0";
