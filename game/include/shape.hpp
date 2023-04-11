#ifndef SHAPE_H
#define SHAPE_H

#include "./shader.hpp"
#include <fstream>

struct sommetTriangle
{
	float x, y, z;
};

struct triangle
{
	sommetTriangle sommet[3];
};

class shape
{
public:
	shape(const char* name,
		  const char* caseToLoad,
		  const char* fileToLoad,
		  shader* mShader,
		  unsigned int drawtype);
	~shape();

	void draw(glm::mat4 mModel);

	void configureVbo();
private:
	std::vector<triangle> loadShapeFromFile(const char* nameCase, const char* nameFile);

public:
	const char *name;
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;
	glm::mat4 matrix4x4 = glm::mat4(1.f);


private:
	unsigned int mVao;
	unsigned int mVbo;
	unsigned int mDrawType;

	shader* mShader;

	std::vector<triangle> Mesh;
};

#endif