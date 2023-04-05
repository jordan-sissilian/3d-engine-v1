#include "../include/shape.hpp"

void shape::draw()
{
    GLuint matrixLocation = glGetUniformLocation(this->mShader->getShaderProgram(), "matrix");

    glBindVertexArray(this->mVao);
    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, glm::value_ptr(this->matrix4x4));
    glUseProgram(this->mShader->getShaderProgram());
    glBindBuffer(GL_ARRAY_BUFFER, this->mVbo);
    glDrawArrays(GL_TRIANGLES, 0, this->Mesh.size() * 3);
}

void shape::setPosition(float x, float y, float z) // refaire
{
    glm::mat4 translation = glm::translate(this->matrix4x4, glm::vec3(x, y, z));
    this->matrix4x4 = translation * this->matrix4x4;
}

void shape::setRotation(int Axe, float angle)
{
    glm::mat4 rotation;

    switch (Axe) {
        case 1:
            rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f));
            break;
        case 2:
            rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, 1.0f));
            break;
        case 3:
            rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
            break;
    }
    this->matrix4x4 = rotation * this->matrix4x4;
}

void shape::setScale(float v) // refaire
{
    glm::mat4 scale = glm::scale(this->matrix4x4, glm::vec3(v));
    this->matrix4x4 = scale * this->matrix4x4;
}

void shape::configureVbo()
{
    glGenBuffers(1, &this->mVbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->mVbo);
    glBufferData(GL_ARRAY_BUFFER, this->Mesh.size() * sizeof(triangle), this->Mesh.data(), this->mDrawType);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

std::vector<triangle> shape::loadShapeFromFile(char* nameFile) // refaire
{
    std::vector<triangle> Mesh;
    triangle tri;

    if (nameFile == "1") {
    tri.sommet[0].x = -0.4f; tri.sommet[0].y = +0.4f; tri.sommet[0].z = +0.0f; // haut
    tri.sommet[1].x = -0.4f; tri.sommet[1].y = +0.0f; tri.sommet[1].z = +0.0f; // gauche
    tri.sommet[2].x = +0.0f; tri.sommet[2].y = +0.0f; tri.sommet[2].z = +0.0f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = -0.4f; tri.sommet[0].y = +0.4f; tri.sommet[0].z = +0.4f; // haut
    tri.sommet[1].x = -0.4f; tri.sommet[1].y = +0.0f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = +0.0f; tri.sommet[2].y = +0.0f; tri.sommet[2].z = +0.4f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = -0.4f; tri.sommet[0].y = +0.0f; tri.sommet[0].z = +0.0f; // haut
    tri.sommet[1].x = -0.4f; tri.sommet[1].y = +0.0f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = +0.0f; tri.sommet[2].y = +0.0f; tri.sommet[2].z = +0.0f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = -0.4f; tri.sommet[0].y = +0.4f; tri.sommet[0].z = +0.0f; // haut
    tri.sommet[1].x = -0.4f; tri.sommet[1].y = +0.4f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = +0.0f; tri.sommet[2].y = +0.4f; tri.sommet[2].z = +0.0f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = -0.4f; tri.sommet[0].y = +0.0f; tri.sommet[0].z = +0.0f; // haut
    tri.sommet[1].x = -0.4f; tri.sommet[1].y = +0.4f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = -0.4f; tri.sommet[2].y = +0.4f; tri.sommet[2].z = +0.0f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = +0.0f; tri.sommet[0].y = +0.0f; tri.sommet[0].z = +0.0f; // haut
    tri.sommet[1].x = +0.0f; tri.sommet[1].y = +0.4f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = +0.0f; tri.sommet[2].y = +0.4f; tri.sommet[2].z = +0.0f; // droite
	Mesh.push_back(tri);
    } else {
    tri.sommet[0].x = +0.0f; tri.sommet[0].y = +0.4f; tri.sommet[0].z = +0.0f; // haut
    tri.sommet[1].x = -0.4f; tri.sommet[1].y = +0.4f; tri.sommet[1].z = +0.0f; // gauche
    tri.sommet[2].x = +0.0f; tri.sommet[2].y = +0.0f; tri.sommet[2].z = +0.0f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = +0.0f; tri.sommet[0].y = +0.4f; tri.sommet[0].z = +0.4f; // haut
    tri.sommet[1].x = -0.4f; tri.sommet[1].y = +0.4f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = +0.0f; tri.sommet[2].y = +0.0f; tri.sommet[2].z = +0.4f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = +0.0f; tri.sommet[0].y = +0.0f; tri.sommet[0].z = +0.0f; // haut
    tri.sommet[1].x = +0.0f; tri.sommet[1].y = +0.0f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = -0.4f; tri.sommet[2].y = +0.0f; tri.sommet[2].z = +0.4f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = +0.0f; tri.sommet[0].y = +0.4f; tri.sommet[0].z = +0.0f; // haut
    tri.sommet[1].x = +0.0f; tri.sommet[1].y = +0.4f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = -0.4f; tri.sommet[2].y = +0.4f; tri.sommet[2].z = +0.4f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = -0.4f; tri.sommet[0].y = +0.4f; tri.sommet[0].z = +0.4f; // haut
    tri.sommet[1].x = -0.4f; tri.sommet[1].y = +0.0f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = -0.4f; tri.sommet[2].y = +0.0f; tri.sommet[2].z = +0.0f; // droite
	Mesh.push_back(tri);
    tri.sommet[0].x = +0.0f; tri.sommet[0].y = +0.4f; tri.sommet[0].z = +0.4f; // haut
    tri.sommet[1].x = +0.0f; tri.sommet[1].y = +0.0f; tri.sommet[1].z = +0.4f; // gauche
    tri.sommet[2].x = +0.0f; tri.sommet[2].y = +0.0f; tri.sommet[2].z = +0.0f; // droite
	Mesh.push_back(tri);
    }




    return (Mesh);  
}

shape::shape(char* name, char* fileToLoad, shader *Shader, unsigned int drawtype)
{
    this->name = name;
    this->mDrawType = drawtype;
    this->mShader = Shader;

    this->Mesh = this->loadShapeFromFile(fileToLoad);

    glGenVertexArrays(1, &this->mVao);
	glBindVertexArray(this->mVao);
	this->configureVbo();
}

shape::~shape() { }