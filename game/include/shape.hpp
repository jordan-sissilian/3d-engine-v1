#ifndef SHAPE_H
#define SHAPE_H

#include "./texture.hpp"
#include "./loadObjFile/loadObjFile.hpp"

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

private:
	void configureVbo();
	std::vector<triangle> loadShapeFromFile(const char*, const char*);

public:
	const char* name;
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	GLuint matrixLocation;
	glm::mat4 matrix4x4 = glm::mat4(1.f);

	std::vector<triangle> Mesh;

private:
	unsigned int mVao;
	unsigned int mVbo;
	unsigned int mDrawType;

	shader* mShader;
	texture* mTexture;
	std::string nameTexture;
};

#endif