#include "../../include/shape/cube.hpp"

void cube::drawCube()
{
	this->couleurCubeLoc = glGetUniformLocation(this->mShader->getShaderProgram(), "couleur");
	glUniform4f(this->couleurCubeLoc, this->couleurCube[0], this->couleurCube[1], this->couleurCube[2], 1.0f);
	this->draw();
}

cube::cube(std::vector<std::string> obj, shader* mShader, unsigned int drawtype, glm::vec3 couleur) : mObjet(obj, mShader, drawtype)
{
	this->mShader = mShader;
	this->couleurCube = couleur;
}

cube::~cube()
{ }