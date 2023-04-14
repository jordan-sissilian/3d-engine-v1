#include "../../include/shape/gun.hpp"

void gun::drawgun()
{
	this->couleurgunLoc = glGetUniformLocation(this->mShader->getShaderProgram(), "couleur");
	glUniform4f(this->couleurgunLoc, this->couleurgun[0], this->couleurgun[1], this->couleurgun[2], 1.0f);
	this->draw();
}

gun::gun(std::vector<std::string> obj, shader* mShader, unsigned int drawtype, glm::vec3 couleur) : mObjet(obj, mShader, drawtype)
{
	this->mShader = mShader;
	this->couleurgun = couleur;
}

gun::~gun()
{ }