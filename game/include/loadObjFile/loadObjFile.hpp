#ifndef LOADOBJFILE_H_
#define LOADOBJFILE_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include "../shape.hpp"

struct sommetTriangle;
struct triangle;

struct v
{
	double x, y, z;
};

struct vt
{
	double u, v, w;
}; 

struct vn
{
	double x, y, z;
};

struct f
{
	int v1 = 0;
	int v2 = 0;
	int v3 = 0;

	int vt1 = 0;
	int vt2 = 0;
	int vt3 = 0;

	int vn1 = 0;
	int vn2 = 0;
	int vn3 = 0;
};


class loadObjFile
{
private:
	int version = 0;
	std::string name;

	int nbFace;
	std::vector<f> vecFTmp;
	std::vector<v> vecVtmp;
	//std::vector<vt> vecVtTmp;
	//std::vector<vn> vecVnTmp;

public:
	loadObjFile(std::string, std::string);
	~loadObjFile();

	std::vector<triangle> getMesh();
	//getTexture();
	//getNormal();

private:
	v getV(std::string line);
	//void getVt();
	//void getVn();
	f mgetF(std::string line);
	void getF();

	void transformToTriangle();
};

#endif