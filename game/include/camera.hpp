#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <vector>
#include <cmath>

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glfw-3.3.8/include/GLFW/glfw3native.h"
#include "../../libs/glad/include/glad/glad.h"
#include "../../libs/glm/glm.hpp"
#include "../../libs/glm/gtc/matrix_transform.hpp"
#include "../../libs/glm/gtc/type_ptr.hpp"

#include "./shader.hpp"
#include "./window.hpp"

class camera
{
public:
	camera(shader* shader);
	~camera();

	void load();
	void mouseControl(Window* window);
	void control(Window* window);

private:
	shader* mshader;

	GLuint matrixViewLocation;
	glm::mat4 matrixView = glm::mat4(1.f);
	glm::vec3 cameraPosition;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;

	GLuint matrixProjectionLocation;
	glm::mat4 matrixProjection = glm::mat4(1.f);

private:
	glm::vec3 direction;
	float yaw;
	float pitch;
	float lastX;
	float lastY;
	float fov;
};

#endif