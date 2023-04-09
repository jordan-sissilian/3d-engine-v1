#ifndef MOBJET_H
#define MOBJET_H

#include "./shape.hpp"

class mObjet
{
public:
	mObjet(char*, shader*, unsigned int);
	~mObjet();

	void draw();

	void setRotation(int nbShape, int Axe, float angle);
	void setScale(int nbShape, float v);
	void setPosition(int nbShape, float x, float y, float z);

public:
	glm::mat4 mModel = glm::mat4(1.f);

private:
	char* nameObjet;
	int nbPart;
	std::vector<char *> namePart;
public:
	std::vector<shape *> objet;
};

#endif