
#include "../include/shader.hpp"
#include "../include/window.hpp"

int main(void)
{
    Window *window = new Window(hauteurJeu, largeurJeu);

    GLuint VAO;                   // informations de sommet stockées dans un ou plusieurs VBO sont interprétées par le pipeline de rendu
    glGenVertexArrays(1, &VAO);   // génère un VAO en réservant un emplacement de mémoire pour stocker ses données.
    glBindVertexArray(VAO);       // lie le VAO pour spécifier la configuration des sommets stockés dans le VBO.
    glEnableVertexAttribArray(0); // active l'attribut de sommet pour l'index 0 

    float vertices[] = {
        0.5f,  0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f,  // top left
        0.0f,  1.0f, 0.0f,   
        -0.5f,  0.5f, 0.0f,
    };
    GLuint VBO;                                                                      
    glGenBuffers(1, &VBO);                                                         
    glBindBuffer(GL_ARRAY_BUFFER, VBO);                                            
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);  
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);    

    GLushort indices [] = {
        0, 1, 3,   // first triangle
        1, 2, 3,   // second triangle
        0, 4, 5,
    };
    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    shader* shaderProgram = new shader();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // debug mode filaire

    while (!glfwWindowShouldClose(window->window)) {

        if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window->window, true);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glBindVertexArray(VAO); // lie le VAO pour dessiner les sommets stockés.
        glUseProgram(shaderProgram->getShaderProgram());
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_SHORT, 0);

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    delete window;
    delete shaderProgram;
    return (0);
}