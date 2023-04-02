#include "../include/shader.hpp"

void shader::loadVertexShader(void)
{
    this->vertexShader[0] = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vertexShader[0], 1, &vertexShaderSource, NULL);
    glCompileShader(this->vertexShader[0]);

    glGetShaderiv(this->vertexShader[0], GL_COMPILE_STATUS, &this->success);
    if (!this->success) {
        glGetShaderInfoLog(this->vertexShader[0], 512, NULL, this->infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << this->infoLog << std::endl;
    }
}

void shader::loadFragmentShader(void)
{
    this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(this->fragmentShader);

    glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &this->success);
    if (!this->success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, this->infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << this->infoLog << std::endl;
    }
}

unsigned int shader::getShaderProgram(void)
{
	return (this->shaderProgram);
}

shader::shader(void)
{
    this->shaderProgram = glCreateProgram();
	this->loadVertexShader();
	this->loadFragmentShader();
    glAttachShader(this->shaderProgram, this->vertexShader[0]);
    glAttachShader(this->shaderProgram, this->fragmentShader);
    glLinkProgram(this->shaderProgram);

    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &this->success);
    if (!this->success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, this->infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << this->infoLog << std::endl;
    }
}

shader::~shader(void)
{
    glDeleteShader(this->vertexShader[0]);
    glDeleteShader(this->fragmentShader);
	glDeleteProgram(this->shaderProgram);
}