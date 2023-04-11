#include "../include/window.hpp"
#include "../include/mobjet.hpp"
#include "../include/camera.hpp"

int main(void)
{
    Window* window = new Window(hauteurJeu, largeurJeu);
    shader* shaderProgram = new shader(1);
    camera* mcamera = new camera(shaderProgram);

    mObjet* cube = new mObjet("cube", shaderProgram, GL_STATIC_DRAW);

    mObjet* map = new mObjet("map", shaderProgram, GL_STATIC_DRAW);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // debug mode filaire
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window->window)) {
        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mcamera->control(window);

        if (glfwGetKey(window->window, GLFW_KEY_5) == GLFW_PRESS)
            cube->setPosition(0, 0.005, 0, 0);
        if (glfwGetKey(window->window, GLFW_KEY_6) == GLFW_PRESS)
            cube->setPosition(1, 0, 0.005, 0);
        if (glfwGetKey(window->window, GLFW_KEY_7) == GLFW_PRESS)
            cube->setPosition(2, 0, 0, 0.005);
        if (glfwGetKey(window->window, GLFW_KEY_1) == GLFW_PRESS)
            cube->setRotation(0, 3, 0.9f);
        if (glfwGetKey(window->window, GLFW_KEY_2) == GLFW_PRESS)
            cube->setRotation(1, 1, 0.9f);
        if (glfwGetKey(window->window, GLFW_KEY_3) == GLFW_PRESS)
            cube->setRotation(2, 2, 0.9f);
        if (glfwGetKey(window->window, GLFW_KEY_4) == GLFW_PRESS)
            cube->setScale(0, 1.004f);

        map->draw();
        cube->draw();

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

    delete window;
    return (0);
}