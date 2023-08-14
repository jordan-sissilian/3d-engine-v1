#include "../include/shape.hpp"

void shape::draw(glm::mat4 mModel)
{
    glBindVertexArray(this->mVao);
    glBindBuffer(GL_ARRAY_BUFFER, this->mVbo);

    glUniformMatrix4fv(this->matrixLocation, 1, GL_FALSE, glm::value_ptr((mModel * this->matrix4x4)));
    glUseProgram(this->mShader->getShaderProgram());
    this->mTexture->bind(this->mShader);
    glDrawArrays(GL_TRIANGLES, 0, this->Mesh.size() * 3);
}

void shape::configureVbo()
{
    glGenBuffers(1, &this->mVbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->mVbo);
    glBufferData(GL_ARRAY_BUFFER, this->Mesh.size() * sizeof(triangle), this->Mesh.data(), this->mDrawType);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sommetTriangle), (void *)0);

    glBindVertexArray(0);
}

std::vector<triangle> shape::loadShapeFromFile(const char *nameCase, const char *nameFile)
{
    loadObjFile obj = loadObjFile(nameCase, nameFile);
    this->nameTexture = obj.getTextureName();
    return (obj.getMesh());
}

shape::shape(const char *name, const char *caseToLoad, const char *fileToLoad, shader *mShader, unsigned int drawtype)
    : name(name),
      mDrawType(drawtype),
      mShader(mShader)
{
    this->Mesh = this->loadShapeFromFile(caseToLoad, fileToLoad);

    glGenVertexArrays(1, &this->mVao);
    glBindVertexArray(this->mVao);
    this->configureVbo();
    this->matrixLocation = glGetUniformLocation(this->mShader->getShaderProgram(), "matrixModel");

    this->mTexture = new texture("./res/shape3d/" + (!std::strcmp(this->nameTexture.c_str(), "error.jpg") ? std::string("default") : std::string(name)) + "/texture/" + std::string(this->nameTexture));
}

shape::~shape() {}