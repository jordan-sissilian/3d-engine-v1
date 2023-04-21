#include "../include/window.hpp"
#include "../include/mobjet.hpp"
#include "../include/camera.hpp"

#include "../include/shape/gun.hpp"

#include <soil2/SOIL2.h>

std::vector<std::string> mfileLoader(char *name);

int main(void)
{
    Window* window = new Window(hauteurJeu, largeurJeu);
    shader* shaderProgram = new shader(1);
    camera* mcamera = new camera(shaderProgram);

    gun* piece = new gun(mfileLoader("gun"), shaderProgram, GL_STATIC_DRAW, glm::vec3(0.0f, 0.0f, 0.0f));

    glEnable(GL_DEPTH_TEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //debug mode filaire

    piece->setPosition(0, +0.0f, +0.0f, -100.0f);


    while (!glfwWindowShouldClose(window->window)) {
        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mcamera->control(window);

        if (glfwGetKey(window->window, GLFW_KEY_1) == GLFW_PRESS)
            piece->setRotation(0, 1, 0.5f);
        if (glfwGetKey(window->window, GLFW_KEY_2) == GLFW_PRESS)
            piece->setRotation(0, 2, 0.1f);
        if (glfwGetKey(window->window, GLFW_KEY_3) == GLFW_PRESS)
            piece->setRotation(0, 3, 0.5f);

        if (glfwGetKey(window->window, GLFW_KEY_4) == GLFW_PRESS)
            piece->setPosition(0, 0.0, 0.1, 0.0f);
        if (glfwGetKey(window->window, GLFW_KEY_4) == GLFW_PRESS)
            piece->setPosition(0, 0.1, 0.0, 0.0f);

        piece->drawgun();

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }
    delete window;
    return (0);
}
