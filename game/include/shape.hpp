#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

#include "./shader.hpp"

enum shapeChoise {
	_triangle,
	_ligne,
	_reactangle,
	_rond,
	_formeCustom
};

struct vec3d
{
	float x, y, z;
};

struct triangle
{
	vec3d p[3];
};

struct mesh
{
	std::vector<triangle> tris;
};

class shape
{
private:
	unsigned int VAO; // encapsule tout les vbo
	unsigned int VBO; // vertex couleur, position, normal, texture...
	mesh Mesh;
	triangle triangleSommet;
	shader* Shader;
	unsigned int DrawType;

public:
	shape(shader *shader, unsigned int DrawType,
	float x1, float x2, float x3,
	float y1, float y2, float y3,
	float z1, float z2, float z3);
	~shape(void);

	void draw(void);

private:
	void createTriangle(triangle tri);
	void configureVBO(void);

};

#endif