#ifndef WINDOW_H
#define WINDOW_H

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glad/include/glad/glad.h"
#include <iostream>

#define nameGame "3d"
#define major 3
#define minor 3
#define hauteurJeu 768 
#define largeurJeu 1366

class Window
{
private:
	const char* name = nameGame;
	unsigned int height;
	unsigned int width;

	int majorVersion;
	int minorVersion;

public:
	GLFWwindow* window;

public:
	Window(uint height, uint width);
	~Window();

private:
	void loadGLFW(void);
	void loadGlad(void);
};


#endif