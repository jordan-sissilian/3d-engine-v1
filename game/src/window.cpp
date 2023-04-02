#include "../include/window.hpp"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::loadGLFW(void)
{
	if (!glfwInit()) {
        std::cerr << "Erreur : " << "Glfw non charger" << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, this->majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, this->minorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    this->window = glfwCreateWindow(this->width, this->height, this->name, NULL, NULL);
    if (!this->window) {
        std::cerr << "Erreur : " << "window na pas pu etre cree" << std::endl;
    }
    glfwMakeContextCurrent(this->window);
	glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
}

void Window::loadGlad(void)
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        std::cerr << "Erreur : " << "Glad non charger" << std::endl;
}

Window::Window(uint height, uint width)
{
	this->name = nameGame;
	this->height = height;
	this->width = width;
	this->majorVersion = major;
	this->minorVersion = minor;

	this->loadGLFW();
	this->loadGlad();
    glfwSwapInterval(1);
}

Window::~Window()
{
	glfwDestroyWindow(this->window);
    glfwTerminate();
}