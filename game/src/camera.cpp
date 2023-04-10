#include "../include/camera.hpp"

void camera::load()
{
	glUniformMatrix4fv(this->matrixViewLocation, 1, GL_FALSE, glm::value_ptr(this->matrixView));
    glUniformMatrix4fv(this->matrixProjectionLocation, 1, GL_FALSE, glm::value_ptr(this->matrixProjection));
}

camera::camera(shader *shader)
{
	this->mshader = shader;

	this->cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    this->cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->matrixView = glm::lookAt(this->cameraPosition, this->cameraTarget, this->cameraUp);
    this->matrixViewLocation = glGetUniformLocation(mshader->getShaderProgram(), "matrixView");

	this->matrixProjection = glm::perspective(glm::radians(45.0f), (float)1366/(float)768, 0.1f, 100.0f);
    this->matrixProjectionLocation = glGetUniformLocation(mshader->getShaderProgram(), "matrixProjection");
}

camera::~camera()
{
}