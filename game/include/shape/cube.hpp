#ifndef CUBE_H
#define CUBE_H

#include "../mobjet.hpp"

class cube : public mObjet
{
private:
	GLuint couleurCubeLoc;
	glm::vec3 couleurCube;

	shader* mShader;

public:
	cube(std::vector<std::string> obj, shader*, unsigned int, glm::vec3);
	~cube();

	void drawCube();
};

#endif