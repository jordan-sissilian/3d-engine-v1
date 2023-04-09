
#include "../include/window.hpp"
#include "../include/shape.hpp"

int main(void)
{
    Window* window = new Window(hauteurJeu, largeurJeu);
    shader* shaderProgram = new shader(1);
    shader* shaderProgram1 = new shader(2);

    shape* forme = new shape("cube", "cube", "cube.3d", shaderProgram, GL_STATIC_DRAW);

   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // debug mode filairej
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window->window)) {
        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (glfwGetKey(window->window, GLFW_KEY_1) == GLFW_PRESS) {
            forme->setRotation(1, 0.005f);
        }
        if (glfwGetKey(window->window, GLFW_KEY_2) == GLFW_PRESS)  {
            forme->setRotation(2, 0.005f);
        }
        if (glfwGetKey(window->window, GLFW_KEY_3) == GLFW_PRESS) {
            forme->setRotation(3, 0.005f);
        }

        forme->draw();
        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

    delete window;
    return (0);
}