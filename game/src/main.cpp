#include "../include/window.hpp"
#include "../include/mobjet.hpp"
#include "../include/camera.hpp"

#include "../include/shape/map.hpp"
#include "../include/shape/car.hpp"

#include <soil2/SOIL2.h>
#include <random>

std::vector<std::string> mfileLoader(char *name);

int main(void)
{
    Window* window = new Window(hauteurJeu, largeurJeu);
    shader* shaderProgram = new shader(1);
    camera* mcamera = new camera(shaderProgram);

    std::vector<map> maps;
    maps.push_back(map(mfileLoader("map"), shaderProgram, GL_STATIC_DRAW, glm::vec3(0.0f, 0.0f, 0.0f)));
    maps[0].setPosition(0, 0.f, 0.0f, 0.0f);
    maps[0].setScale(0, 20);


    car cars = car(mfileLoader("cars"), shaderProgram, GL_STATIC_DRAW, glm::vec3(0.0f, 0.0f, 0.0f));
    cars.setScale(0, 0.5);
    cars.setPosition(0, -13.f, 8.7f, 0.0f);
    cars.setPosition(1, 0.f, 1.0f, 0.0f);
    cars.setPosition(2, 0.f, 1.0f, 0.3f);
    cars.setRotation(0, 3, 50.f);


    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window->window)) {
        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
 
        mcamera->control(window);

        maps[0].drawmap();
    
        cars.drawcar();

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }
    delete (mcamera);
    delete (shaderProgram);
    delete (window);
    return (0);
}