#include "../include/camera.hpp"

void camera::control(Window *window)
{
	if (glfwGetKey(window->window, GLFW_KEY_W) == GLFW_PRESS)
		this->cameraPosition += 0.01f * this->cameraFront;
	if (glfwGetKey(window->window, GLFW_KEY_S) == GLFW_PRESS)
		this->cameraPosition -= 0.01f * this->cameraFront;
	if (glfwGetKey(window->window, GLFW_KEY_A) == GLFW_PRESS)
		this->cameraPosition -= glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * 0.005f;
	if (glfwGetKey(window->window, GLFW_KEY_D) == GLFW_PRESS)
		this->cameraPosition += glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * 0.005f;
	this->matrixView = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
	load();
}

void camera::load()
{
	glUniformMatrix4fv(this->matrixViewLocation, 1, GL_FALSE, glm::value_ptr(this->matrixView));
    glUniformMatrix4fv(this->matrixProjectionLocation, 1, GL_FALSE, glm::value_ptr(this->matrixProjection));
}

camera::camera(shader *shader)
{
	this->mshader = shader;

	this->cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->matrixViewLocation = glGetUniformLocation(mshader->getShaderProgram(), "matrixView");

	this->matrixProjection = glm::perspective(glm::radians(45.0f), (float)1366/(float)768, 0.1f, 100.0f);
    this->matrixProjectionLocation = glGetUniformLocation(mshader->getShaderProgram(), "matrixProjection");
}

camera::~camera()
{
}