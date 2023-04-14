#ifndef MAP_H
#define MAP_H

#include "../mobjet.hpp"

class map : public mObjet
{
private:
	GLuint couleurMapLoc;
	glm::vec3 couleurMap;

	shader* mShader;
	

public:
	map(std::vector<std::string> obj, shader*, unsigned int, glm::vec3);
	~map();

	void drawMap();
};

#endif