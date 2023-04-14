#ifndef gun_H
#define gun_H

#include "../mobjet.hpp"

class gun : public mObjet
{
private:
	GLuint couleurgunLoc;
	glm::vec3 couleurgun;

	shader* mShader;

public:
	gun(std::vector<std::string> obj, shader*, unsigned int, glm::vec3);
	~gun();

	void drawgun();
};

#endif