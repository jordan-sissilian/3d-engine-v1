#ifndef LOADOBJFILE_H_
#define LOADOBJFILE_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "../shape.hpp"

struct sommetTriangle;
struct coordTexture;
struct triangle;

struct v
{
	double x, y, z;
};

struct vt
{
	double u, v;
};

struct vn
{
	double x, y, z;
};

struct f
{
	unsigned int v[3];
	unsigned int vt[3];
	unsigned int vn[3];
};


class loadObjFile
{
private:
	int version = 0;
	std::string name;

	std::vector<f> vecFTmp;
	std::vector<v> vecVtmp;
	std::vector<vt> vecVtTmp;
	std::vector<vn> vecVnTmp;

public:
	loadObjFile(std::string, std::string);
	~loadObjFile();

	std::vector<triangle> getMesh();

private:
	v getV(std::string line);
	vt getVt(std::string line);
	vn getVn(std::string line);
	f mgetF(std::string line);
	void getF();

	void transformToTriangle();
};

#endif
