#ifndef SHAPE_H
#define SHAPE_H

#include "./shader.hpp"

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
	shape(char* name,
		  char* fileToLoad,
		  shader* mShader,
		  unsigned int drawtype);
	~shape();

	void draw();

	void setRotation(int Axe, float angle);
	void setPosition(float x, float y, float z); // refaire
	void setScale(float v); // refaire

	void configureVbo();
private:
	std::vector<triangle> loadShapeFromFile(char* nameFile);

public:
	char *name;
private:
	unsigned int mVao;
	unsigned int mVbo;
	unsigned int mDrawType;

	shader* mShader;

	std::vector<triangle> Mesh;
	glm::mat4 matrix4x4 = glm::mat4(1.f);
};

#endif