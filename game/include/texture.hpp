#ifndef TEXTURE_H
#define TEXTURE_H

#include "./shader.hpp"

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glad/include/glad/glad.h"
#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/matrix_transform.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

#include <soil2/SOIL2.h>
#include <iostream>
#include <vector>
#include <cmath>

struct sommetTriangle
{
	float x;
    float y;
    float z;

    float u;
    float v;
};

struct triangle
{
	sommetTriangle sommet[3];
};

class texture {
public:
    texture(std::string name);
    ~texture();

    void bind(shader*);

private:
    GLuint idTexture;
    unsigned char* data;
    int width, height;
	int channels;

    GLuint texCoordAttrib;
};

#endif