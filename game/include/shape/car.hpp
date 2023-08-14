#ifndef car_H
#define car_H

#include "../mobjet.hpp"

class car : public mObjet
{
private:
	GLuint couleurcarLoc;
	glm::vec3 couleurcar;

	shader *mShader;

public:
	car(std::vector<std::string> obj, shader *, unsigned int, glm::vec3);
	~car();

	void drawcar();
};

#endif