#ifndef TEXTURE_H
#define TEXTURE_H

#include "./shader.hpp"
#include <soil2/SOIL2.h>

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
};

#endif