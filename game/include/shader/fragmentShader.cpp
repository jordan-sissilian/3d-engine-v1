const char *fragmentShaderSource = 
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec4 vertexColor;\n"
    "void main()\n"
        "{\n"
        "   FragColor = vertexColor;\n"
        "}\n\0";
