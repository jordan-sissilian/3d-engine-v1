#include "../include/shader.hpp"

void shader::loadVertexShader(void)
{
    if (this->v == 1) {
        this->vertexShader[0] = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(this->vertexShader[0], 1, &vertexShaderSource, NULL);
        glCompileShader(this->vertexShader[0]);
        glGetShaderiv(this->vertexShader[0], GL_COMPILE_STATUS, &this->success);
        if (!this->success) {
            glGetShaderInfoLog(this->vertexShader[0], 512, NULL, this->infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << this->infoLog << std::endl;
        }
    }
}

void shader::loadFragmentShader(void)
{
    this->fragmentShader[0] = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fragmentShader[0], 1, &fragmentShaderSource, NULL);
    glCompileShader(this->fragmentShader[0]);
    glGetShaderiv(this->fragmentShader[0], GL_COMPILE_STATUS, &this->success);
    if (!this->success) {
        glGetShaderInfoLog(fragmentShader[0], 512, NULL, this->infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << this->infoLog << std::endl;
    }
}

unsigned int shader::getShaderProgram(void)
{
	return (this->shaderProgram);
}

shader::shader(int v)
{
    this->v = v;
    this->shaderProgram = glCreateProgram();
	this->loadVertexShader();
	this->loadFragmentShader();
    glAttachShader(this->shaderProgram, this->vertexShader[0]);
    glAttachShader(this->shaderProgram, this->fragmentShader[0]);
    glLinkProgram(this->shaderProgram);

    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &this->success);
    if (!this->success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, this->infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << this->infoLog << std::endl;
    }
}

shader::~shader(void)
{
	glDeleteProgram(this->shaderProgram);
}