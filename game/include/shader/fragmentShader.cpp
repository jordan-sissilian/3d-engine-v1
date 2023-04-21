const char *fragmentShaderSource = 
    "#version 330 core \n"
    "out vec4 FragColor; \n"
    "in vec2 fragTextureCoord; \n"
    ""
    "uniform sampler2D textureSampler; \n"
    ""
    "void main() \n"
    "{ \n"
    ""
    "    FragColor = texture(textureSampler, fragTextureCoord); \n"
    "} \n";
