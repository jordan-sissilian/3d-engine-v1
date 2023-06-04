#ifndef WINDOW_H
#define WINDOW_H

#include "../../libs/glfw-3.3.8/include/GLFW/glfw3.h"
#include "../../libs/glad/include/glad/glad.h"
#include <iostream>

constexpr const char* nameGame = "3d";
constexpr int majorV = 3;
constexpr int minorV = 3;
constexpr uint32_t hauteurJeu = 768;
constexpr uint32_t largeurJeu = 1366;


class Window
{
public:
	GLFWwindow* window;

public:
	Window(uint height, uint width);
	virtual ~Window();

private:
	const char* name = nameGame;
	uint32_t height = hauteurJeu;
	uint32_t width = largeurJeu;

	int majorVersion = majorV;
	int minorVersion = minorV;

private:
	void loadGLFW(void);
	void loadGlad(void);
};

#endif