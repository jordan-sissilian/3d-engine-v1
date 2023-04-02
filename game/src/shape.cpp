#include "../include/shape.hpp"

void shape::configureVBO(void)
{
    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->triangleSommet), &this->triangleSommet, this->DrawType);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
	glUseProgram(this->Shader->getShaderProgram());
    glBindVertexArray(0);
}

void shape::draw(void)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void shape::createTriangle(triangle tri)
{
	this->triangleSommet = tri;
}

shape::shape(shader *shader, unsigned int DrawType,
	float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3)
{
	triangle tri;
    tri.p[0].x = x1; tri.p[0].y = y1; tri.p[0].z = z1;
    tri.p[1].x = x2; tri.p[1].y = y2; tri.p[1].z = z2;
    tri.p[2].x = x3; tri.p[2].y = y3; tri.p[2].z = z3;
	this->createTriangle(tri);
	this->DrawType = DrawType;
	this->Shader = shader;

	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);
	this->configureVBO();
}

shape::~shape(void)
{ }