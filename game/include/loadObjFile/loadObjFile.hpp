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

struct v { float x, y, z; };
struct vt { float u, v; };
struct vn { float x, y, z; };
struct f
{
	unsigned int v[3];
	unsigned int vt[3];
	unsigned int vn[3];
};


class loadObjFile
{
public:
	loadObjFile(std::string, std::string);
	~loadObjFile() {};

	std::vector<triangle> getMesh();
	std::string getTextureName();

private:
	v getV(std::string line);
	vt getVt(std::string line);
	vn getVn(std::string line);
	f mgetF(std::string line);
	void getF();

private:
	int version = 0;
	std::string name;
	std::string textureName = "error";

	std::string caseToLoad;
	std::string fileToLoad;

	std::vector<f> vecFTmp;
	std::vector<v> vecVtmp;
	std::vector<vt> vecVtTmp;
	std::vector<vn> vecVnTmp;
};

#endif
