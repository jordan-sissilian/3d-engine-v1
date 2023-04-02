
#include "../include/window.hpp"
#include "../include/shape.hpp"

int main(void)
{
    Window *window = new Window(hauteurJeu, largeurJeu);

    shader* shaderProgram = new shader();

    shape *forme = new shape(shaderProgram, GL_STATIC_DRAW,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f);
    
    shape *formes = new shape(shaderProgram, GL_STATIC_DRAW,
            0.0f, 0.1f, 0.0f,
            -0.5f, -0.1f, 0.0f,
            0.5f, -0.9f, 0.0f
            );

    shape *formess = new shape(shaderProgram, GL_STATIC_DRAW,
            0.0f, 0.1f, 0.0f,
            -0.9f, -0.1f, 0.0f,
            0.2f, -0.9f, 0.0f
            );

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // debug mode filaire

    while (!glfwWindowShouldClose(window->window)) {

        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        forme->draw();
        formes->draw();
        formess->draw();

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }


    delete window;
    return (0);
}