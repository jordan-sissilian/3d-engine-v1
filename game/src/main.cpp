#include "../include/window.hpp"
#include "../include/mobjet.hpp"
#include "../include/camera.hpp"

#include "../include/shape/cube.hpp"
#include "../include/shape/map.hpp"

std::vector<std::string> mfileLoader(char *name);

int main(void)
{
    Window* window = new Window(hauteurJeu, largeurJeu);
    shader* shaderProgram = new shader(1);
    camera* mcamera = new camera(shaderProgram);

    cube* mcube = new cube(mfileLoader("cube"), shaderProgram, GL_STATIC_DRAW);
    cube* mcubse = new cube(mfileLoader("cube"), shaderProgram, GL_STATIC_DRAW);
    map* mmap = new map(mfileLoader("map"), shaderProgram, GL_STATIC_DRAW);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // debug mode filaire
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window->window)) {
        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mcamera->control(window);

        if (glfwGetKey(window->window, GLFW_KEY_5) == GLFW_PRESS)
            mcube->setPosition(0, 0.005, 0, 0);
        if (glfwGetKey(window->window, GLFW_KEY_6) == GLFW_PRESS)
            mcube->setPosition(1, 0, 0.005, 0);
        if (glfwGetKey(window->window, GLFW_KEY_7) == GLFW_PRESS)
            mcube->setPosition(2, 0, 0, 0.005);
        if (glfwGetKey(window->window, GLFW_KEY_1) == GLFW_PRESS)
            mcube->setRotation(0, 3, 0.9f);
        if (glfwGetKey(window->window, GLFW_KEY_2) == GLFW_PRESS)
            mcube->setRotation(1, 1, 0.9f);
        if (glfwGetKey(window->window, GLFW_KEY_3) == GLFW_PRESS)
            mcube->setRotation(2, 2, 0.9f);
        if (glfwGetKey(window->window, GLFW_KEY_4) == GLFW_PRESS)
            mcube->setScale(0, 1.004f);

        mmap->draw();
        mcube->draw();

        mcubse->setRotation(1, 3, 0.9f);
        mcubse->setRotation(2, 2, 0.4f);
        mcubse->setPosition(1, 0, 0.001, 0);
        mcubse->draw();

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

    delete window;
    return (0);
}