#include "../../include/shape/map.hpp"

void map::drawMap()
{
	this->couleurMapLoc = glGetUniformLocation(this->mShader->getShaderProgram(), "couleur");
	glUniform4f(this->couleurMapLoc, this->couleurMap[0], this->couleurMap[1], this->couleurMap[2], 1.0f);
	this->draw();
}

map::map(std::vector<std::string> obj, shader* mShader, unsigned int drawtype, glm::vec3 couleur) : mObjet(obj, mShader, drawtype)
{
	this->mShader = mShader;
	this->couleurMap = couleur;
}

map::~map()
{ }