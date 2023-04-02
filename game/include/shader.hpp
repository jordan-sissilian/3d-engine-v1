#ifndef SHADER_H
#define SHADER_H

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glad/include/glad/glad.h"
#include <iostream>

extern const char *vertexShaderSource;

extern const char *fragmentShaderSource;

class shader
{
private:
	unsigned int shaderProgram = 0;
	unsigned int vertexShader[2];
	unsigned int fragmentShader;

public:
	int success;
    char infoLog[512];

public:
	shader(void);
	~shader();

	void loadVertexShader(void);
	void loadFragmentShader(void);

	unsigned int getShaderProgram(void);
};

#endif