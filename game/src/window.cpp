#include "../include/window.hpp"

static void fcallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::loadGLFW(void)
{
    if (!glfwInit())
        std::cerr << "Erreur : Glfw non chargé" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, this->majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, this->minorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    this->window = glfwCreateWindow(this->width, this->height, this->name, nullptr, nullptr);
    if (!this->window)
        std::cerr << "Erreur : Création de la fenêtre GLFW" << std::endl;

    glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, fcallback);
}

void Window::loadGlad(void)
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        std::cerr << "Erreur : Chargement de Glad" << std::endl;
}

Window::Window(uint height, uint width)
    : name(nameGame),
      height(height),
      width(width),
      majorVersion(majorV),
      minorVersion(minorV),
      window(nullptr)
{
    this->loadGLFW();
    this->loadGlad();
    glfwSwapInterval(1);
}

Window::~Window()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}