#ifndef map_H
#define map_H

#include "../mobjet.hpp"

class map : public mObjet
{
private:
	GLuint couleurmapLoc;
	glm::vec3 couleurmap;

	shader *mShader;

public:
	map(std::vector<std::string> obj, shader *, unsigned int, glm::vec3);
	~map();

	void drawmap();
};

#endif