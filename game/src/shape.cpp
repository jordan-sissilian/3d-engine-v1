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
{ }

// Set Rotation: Axe: X=1, Y=2, Z=3
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
{ }

void shape::configureVbo()
{
    glGenBuffers(1, &this->mVbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->mVbo);
    glBufferData(GL_ARRAY_BUFFER, this->Mesh.size() * sizeof(triangle), this->Mesh.data(), this->mDrawType);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}
#include <unistd.h>

std::vector<triangle> shape::loadShapeFromFile(char* nameCase, char* nameFile)
{
    std::string name("./game/include/shape3d/");
    name.append(nameCase), name.append("/"), name.append(nameFile);
    std::fstream file(name, std::ios::in);
    std::vector<triangle> mMesh;
    std::string line;

    while (std::getline(file, line)) {
        triangle tri;
        for (int i = 0, j = 0; i < 3; i++) {
            tri.sommet[i].x = (float)std::stof(line.substr(j, 4));
            tri.sommet[i].y = (float)std::stof(line.substr((j += 5), 4));
            tri.sommet[i].z = (float)std::stof(line.substr((j += 5), 4));
            i < 2 && (j += 6);
        }
        mMesh.push_back(tri);
    }
    file.close();
    return (mMesh);  
}

shape::shape(char* name, char* caseToLoad, char* fileToLoad, shader* mShader, unsigned int drawtype)
{
    this->name = name;
    this->mDrawType = drawtype;
    this->mShader = mShader;

    this->Mesh = this->loadShapeFromFile(caseToLoad, fileToLoad);

    glGenVertexArrays(1, &this->mVao);
	glBindVertexArray(this->mVao);
	this->configureVbo();
}

shape::~shape() { }