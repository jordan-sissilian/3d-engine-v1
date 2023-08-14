#include "../../include/shape/map.hpp"

void map::drawmap()
{
	this->couleurmapLoc = glGetUniformLocation(this->mShader->getShaderProgram(), "couleur");
	glUniform4f(this->couleurmapLoc, this->couleurmap[0], this->couleurmap[1], this->couleurmap[2], 1.0f);
	this->draw();
}

map::map(std::vector<std::string> obj, shader* mShader, unsigned int drawtype, glm::vec3 couleur) : mObjet(obj, mShader, drawtype)
{
	this->mShader = mShader;
	this->couleurmap = couleur;
}

map::~map() { }