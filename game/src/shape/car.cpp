#include "../../include/shape/car.hpp"

void car::drawcar()
{
	this->couleurcarLoc = glGetUniformLocation(this->mShader->getShaderProgram(), "couleur");
	glUniform4f(this->couleurcarLoc, this->couleurcar[0], this->couleurcar[1], this->couleurcar[2], 1.0f);
	this->draw();
}

car::car(std::vector<std::string> obj, shader *mShader, unsigned int drawtype, glm::vec3 couleur) : mObjet(obj, mShader, drawtype)
{
	this->mShader = mShader;
	this->couleurcar = couleur;
}

car::~car() {}