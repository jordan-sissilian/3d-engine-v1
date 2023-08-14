#ifndef CAMERA_H
#define CAMERA_H

#include "./shader.hpp"
#include "./window.hpp"

class camera
{
public:
	camera(shader *shader);
	~camera();

	void load();
	void mouseControl(Window *window);
	void control(Window *window);

private:
	shader *mshader;

	GLuint matrixViewLocation;
	glm::mat4 matrixView = glm::mat4(1.f);
	glm::vec3 cameraPosition;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	GLuint matrixProjectionLocation;
	glm::mat4 matrixProjection = glm::mat4(1.f);

private:
	glm::vec3 direction;
	float yaw = -90.0f;
	float pitch = 0.0f;
	float lastX = 1366.0f / 2.0;
	float lastY = 768.0 / 2.0;
	float fov = 45.0f;
};

#endif