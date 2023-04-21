#include "../include/camera.hpp"

void camera::mouseControl(Window* window)
{
	double xpos, ypos;
	float xoffset, yoffset;
	static bool f = true;

	glfwGetCursorPos(window->window, &xpos, &ypos);
	f && (this->lastX = xpos, this->lastY = ypos, f = false);
  
    xoffset = xpos - this->lastX;
    yoffset = this->lastY - ypos; 
    this->lastX = xpos;
    this->lastY = ypos;
    xoffset *= 0.1f;
    yoffset *= 0.1f;
    this->yaw += xoffset;
    this->pitch += yoffset;
    this->pitch > 89.0f && (this->pitch = 89.0f);
    this->pitch < -89.0f && (this->pitch = -89.0f);
    this->direction.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->direction.y = sin(glm::radians(this->pitch));
    this->direction.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->cameraFront = glm::normalize(direction);
}

void camera::control(Window *window)
{
	if (glfwGetKey(window->window, GLFW_KEY_SPACE) == GLFW_PRESS)
		this->cameraPosition += glm::vec3(0.0f, 0.1f, 0.0f);
	if (glfwGetKey(window->window, GLFW_KEY_W) == GLFW_PRESS)
		this->cameraPosition += 0.3f * this->cameraFront;
	if (glfwGetKey(window->window, GLFW_KEY_S) == GLFW_PRESS)
		this->cameraPosition -= 0.3f * this->cameraFront;
	if (glfwGetKey(window->window, GLFW_KEY_A) == GLFW_PRESS)
		this->cameraPosition -= glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * 0.1f;
	if (glfwGetKey(window->window, GLFW_KEY_D) == GLFW_PRESS)
		this->cameraPosition += glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * 0.1f;
	this->mouseControl(window);
	this->matrixView = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
	this->load();
}
 
void camera::load()
{
	glUniformMatrix4fv(this->matrixViewLocation, 1, GL_FALSE, glm::value_ptr(this->matrixView));
    glUniformMatrix4fv(this->matrixProjectionLocation, 1, GL_FALSE, glm::value_ptr(this->matrixProjection));
}

camera::camera(shader *shader)
{
	this->mshader = shader;

	this->cameraPosition = glm::vec3(0.0f, 1.0f, 3.0f);
    this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->matrixViewLocation = glGetUniformLocation(mshader->getShaderProgram(), "matrixView");

	this->matrixProjection = glm::perspective(glm::radians(45.0f), (float)1366/(float)768, 0.1f, 1000.0f);
    this->matrixProjectionLocation = glGetUniformLocation(mshader->getShaderProgram(), "matrixProjection");

	this->yaw = -90.0f;
	this->pitch = 0.0f;
	this->lastX = 1366.0f / 2.0;
	this->lastY = 768.0 / 2.0;
	this->fov = 45.0f;
}

camera::~camera()
{
}