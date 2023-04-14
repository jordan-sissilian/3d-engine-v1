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

    cube* mcube = new cube(mfileLoader("tree1"), shaderProgram, GL_STATIC_DRAW, glm::vec3(0.0f, 1.0f, 0.0f));

    glEnable(GL_DEPTH_TEST);
    
    while (!glfwWindowShouldClose(window->window)) {
        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mcamera->control(window);

        if (glfwGetKey(window->window, GLFW_KEY_9) == GLFW_PRESS)
            mcube->setRotation(0, 3, 0.5f);
        if (glfwGetKey(window->window, GLFW_KEY_0) == GLFW_PRESS)
            mcube->setRotation(0, 3, -0.5f);

//draw
        mcube->draw();

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

    delete window;
    return (0);
}