#include "../include/mobjet.hpp"

// nbShape: 0=AllShape, 1=Shape1, 2=Shape2...
void mObjet::setPosition(int nbShape, float x, float y, float z)
{
	glm::mat4 position = glm::mat4(1.0f);

    position = glm::translate(position, glm::vec3(x, y, z));
	!nbShape ? this->mModel *= position : this->objet[nbShape - 1]->matrix4x4 *= position; 
}

// nbShape: 0=AllShape, 1=Shape1, 2=Shape2...
// v=multiplicateur
void mObjet::setScale(int nbShape, float v)
{
	glm::mat4 mscale = glm::mat4(1.0f);

	mscale = glm::scale(mscale, glm::vec3(v));
	!nbShape ? this->mModel *= mscale : this->objet[nbShape - 1]->matrix4x4 *= mscale;
}

// nbShape: 0=AllShape, 1=Shape1, 2=Shape2...
// Set Rotation: Axe: X=1, Y=2, Z=3
void mObjet::setRotation(int nbShape, int Axe, float angle)
{
	glm::mat4 rotation = glm::mat4(1.0f);

    switch (Axe) {
        case 1:
            rotation = glm::rotate(rotation, (float)glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
            break;
        case 2:
            rotation = glm::rotate(rotation, (float)glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
            break;
        case 3:
            rotation = glm::rotate(rotation, (float)glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
            break;
    }
	!nbShape ? this->mModel *= rotation : this->objet[nbShape - 1]->matrix4x4 *= rotation; 
}

void mObjet::draw()
{
	for (int i = 0; i < this->nbPart; i++) {
		this->objet[i]->draw(this->mModel);
	}
}

mObjet::mObjet(std::vector<std::string> obj, shader* mShader, unsigned int drawtype)
{
	this->nameObjet = obj[0];
	this->nbPart = 0;

	for (int i = 0; i <= obj.size() ; i++, this->nbPart++);
	for (int i = 0, j = 1; i < this->nbPart; i++, j++) {
		char parts[obj[j].length()];
		std::strcpy(parts, obj[j].c_str());
		this->namePart.push_back(parts);
		shape* mshape = new shape(this->nameObjet.c_str(), this->nameObjet.c_str(), obj[j].c_str(), mShader, drawtype);
		this->objet.push_back(mshape);
	}
}

mObjet::~mObjet()
{ }