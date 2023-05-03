#include "../include/window.hpp"
#include "../include/mobjet.hpp"
#include "../include/camera.hpp"

#include "../include/shape/gun.hpp"

#include <soil2/SOIL2.h>
#include <random>

std::vector<std::string> mfileLoader(char *name);

int main(void)
{
    Window* window = new Window(hauteurJeu, largeurJeu);
    shader* shaderProgram = new shader(1);
    camera* mcamera = new camera(shaderProgram);

    std::vector<gun> piece;
    for (int i = 0; i < 10; i++)
        piece.push_back(gun(mfileLoader("arbre"), shaderProgram, GL_STATIC_DRAW, glm::vec3(0.0f, 0.0f, 0.0f)));
    
    std::vector<gun> sol;
    sol.push_back(gun(mfileLoader("map"), shaderProgram, GL_STATIC_DRAW, glm::vec3(0.0f, 0.0f, 0.0f)));

    glEnable(GL_DEPTH_TEST);

    for (int i = 0; i < 10; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> disx(-55, 55);
        std::uniform_int_distribution<> disz(-170, 30);
        int numx = disx(gen);
        int numz = disz(gen);

        piece[i].setPosition(0, numx, +0.0f, numz);
    }
        sol[0].setPosition(0, 0.0f, 0.0f, 0.0f);

    while (!glfwWindowShouldClose(window->window)) {
        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (glfwGetKey(window->window, GLFW_KEY_1) == GLFW_PRESS)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //debug mode filaire

        mcamera->control(window);

        for (int i = 0; i < 10; i++)
            piece[i].drawgun();

        sol[0].drawgun();

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }
    delete window;
    return (0);
}
