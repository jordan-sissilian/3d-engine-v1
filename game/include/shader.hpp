#ifndef SHADER_H
#define SHADER_H

#include <iostream>

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glad/include/glad/glad.h"
#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/matrix_transform.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

extern const char *vertexShaderSource;
extern const char *fragmentShaderSource;

class shader
{
private:
	unsigned int shaderProgram;
	unsigned int vertexShader;
	unsigned int fragmentShader;

public:
	int success;
	char infoLog[512];

public:
	shader(int);
	~shader();

	unsigned int getShaderProgram(void) const;

private:
	void loadVertexShader(void);
	void loadFragmentShader(void);
};

#endif