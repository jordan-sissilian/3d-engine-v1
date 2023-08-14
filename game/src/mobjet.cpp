#include "../include/mobjet.hpp"

// nbShape: 0=AllShape, 1=Shape1, 2=Shape2...
void mObjet::setPosition(int nbShape, float x, float y, float z)
{
	this->position = glm::mat4(1.0f);
	this->pos[0] = x;
	this->pos[1] = y;
	this->pos[2] = z;
	this->position = glm::translate(this->position, glm::vec3(x, y, z));
	!nbShape ? this->mModel *= this->position : this->objet[nbShape - 1]->matrix4x4 *= this->position;
}

// nbShape: 0=AllShape, 1=Shape1, 2=Shape2...
// v=multiplicateur
void mObjet::setScale(int nbShape, float v)
{
	glm::mat4 mscale = glm::mat4(1.0f);

	this->scale = v;
	mscale = glm::scale(mscale, glm::vec3(v));
	!nbShape ? this->mModel *= mscale : this->objet[nbShape - 1]->matrix4x4 *= mscale;
}

// nbShape: 0=AllShape, 1=Shape1, 2=Shape2...
// Set Rotation: Axe: X=1, Y=2, Z=3
void mObjet::setRotation(int nbShape, int Axe, float angle)
{
	this->rotation = glm::mat4(1.0f);
	this->rot = angle;
	switch (Axe)
	{
	case 1:
		this->rotation = glm::rotate(this->rotation, (float)glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
		break;
	case 2:
		this->rotation = glm::rotate(this->rotation, (float)glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
		break;
	case 3:
		this->rotation = glm::rotate(this->rotation, (float)glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
		break;
	}
	!nbShape ? this->mModel *= this->rotation : this->objet[nbShape - 1]->matrix4x4 *= this->rotation;
}

void mObjet::draw()
{
	for (int i = 0; i < this->nbPart; i++)
		this->objet[i]->draw(this->mModel);
}

void mObjet::drawIndex(int i)
{
	if (this->objet.size() >= i)
		this->objet[i]->draw(this->mModel);
}

mObjet::mObjet(std::vector<std::string> obj, shader *mShader, unsigned int drawtype)
{
	this->nameObjet = obj[0];
	this->nbPart = -1;

	for (int i = 0; i < obj.size(); i++, this->nbPart++)
		;
	for (int i = 0, j = 1; i < this->nbPart; i++, j++)
	{
		char parts[obj[j].length() + 1];
		parts[obj[j].length()] = '\0';
		std::strcpy(parts, obj[j].c_str());
		this->namePart.push_back(parts);
		shape *mshape = new shape(this->nameObjet.c_str(), this->nameObjet.c_str(), obj[j].c_str(), mShader, drawtype);
		this->objet.push_back(mshape);
	}

	int nb = 0;
	glm::vec3 center(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < this->nbPart; i++)
	{
		for (int j = 0; j < this->objet[i]->Mesh.size(); j++)
		{
			for (int k = 0; k < 3; k++)
			{
				center[0] += this->objet[i]->Mesh[j].sommet[k].x;
				center[1] += this->objet[i]->Mesh[j].sommet[k].y;
				center[2] += this->objet[i]->Mesh[j].sommet[k].z;
				nb += 1;
			}
		}
	}
	this->mModel *= glm::translate(this->mModel, -(center /= nb));
}

mObjet::~mObjet()
{
}