#include "../../include/loadObjFile/loadObjFile.hpp"

v loadObjFile::getV(std::string line)
{
	std::cout << "		getV>" << line << std::endl;
	v tmp;
	line.erase(0, 2);
	std::istringstream iss(line);
	iss >> tmp.x >> tmp.y >> tmp.z;
	std::cout << "		tmp.x>" << tmp.x << "< tmp.y:>" << tmp.y << "< tmp.z: >" << tmp.z << "<" << std::endl;
	std::cout << std::endl;
	return (tmp);
}

//void loadObjFile::getVt() {}
//void loadObjFile::getVn() {}

f loadObjFile::mgetF(std::string line)
{
	int i = 0;
	this->version = 0;
	for (int j = 0; j < line.size(); j++) {
		line[j] == ' ' && i++;
		line[j] == '/' && this->version++;
	}
	if (this->version == 0)
		this->version = 1;
	else if (this->version == 3)
		this->version = 2;
	else
		this->version = 3;

	line.erase(0, 2);
	for (size_t pos = 0; (pos = line.find('/', pos)) != std::string::npos; pos++)
        line.replace(pos, 1, 1, ' ');
	std::istringstream iss = std::istringstream(line);
	f tmp;
	if (this->version == 1)
		iss >> i >> tmp.v1 >> tmp.v2 >> tmp.v3;
	else if (this->version == 2)
		iss >> tmp.v1 >> tmp.vt1 >> tmp.v2 >> tmp.vt2 >> tmp.v3 >> tmp.vt3;
	else if (this->version == 3)
		iss >> tmp.v1 >> tmp.vt1 >> tmp.vn1 >> tmp.v2 >> tmp.vt2 >> tmp.vn2 >> tmp.v3 >> tmp.vt3 >> tmp.vn3;
	return (tmp);
}

void loadObjFile::getF()
{
	std::fstream fileTmp = std::fstream(this->name, std::ios::in);
	for (std::string lineTmp; std::getline(fileTmp, lineTmp) ;) {
		for (int i = 0; i < lineTmp.length(); i++)
        	if (lineTmp[i] == ' ' && lineTmp[i+1] == ' ' && (i--))
            	lineTmp.erase(i+2, 1);
		if (lineTmp.size() > 2 && lineTmp[0] == 'v'  && lineTmp[1] == ' ')
			this->vecVtmp.push_back(this->getV(lineTmp));
		//if (lineTmp.size() > 2 && lineTmp[0] == 'v' && lineTmp[1] == 't') { }
		//if (lineTmp.size() > 2 && lineTmp[0] == 'v' && lineTmp[1] == 'n') { }
		if (lineTmp.size() > 2 && lineTmp[0] == 'f')
			this->vecFTmp.push_back(this->mgetF(lineTmp));
    }
    fileTmp.close();
	//this->transformToTriangle();
	this->nbFace = this->vecFTmp.size();
}

void loadObjFile::transformToTriangle()
{
	// si il y a des quad ou plus les transofrmer en plusieur petit triangle
	// et les stoker a la suite dans les vector
	// et incrementer le nombre de face
}

std::vector<triangle> loadObjFile::getMesh()
{
	std::vector<triangle> Mesh;

	for (int i = 0; i < this->vecFTmp.size(); i++) {
		triangle tri;
		tri.sommet[0].x = (this->vecVtmp[static_cast<int>(vecFTmp[i].v1) - 1].x);
		tri.sommet[0].y =	(this->vecVtmp[static_cast<int>(vecFTmp[i].v1) - 1].y);
		tri.sommet[0].z = (this->vecVtmp[static_cast<int>(vecFTmp[i].v1) - 1].z);

		tri.sommet[1].x = (this->vecVtmp[static_cast<int>(vecFTmp[i].v2) - 1].x);
		tri.sommet[1].y =	(this->vecVtmp[static_cast<int>(vecFTmp[i].v2) - 1].y);
		tri.sommet[1].z = (this->vecVtmp[static_cast<int>(vecFTmp[i].v2) - 1].z);

		tri.sommet[2].x = (this->vecVtmp[static_cast<int>(vecFTmp[i].v3) - 1].x);
		tri.sommet[2].y =	(this->vecVtmp[static_cast<int>(vecFTmp[i].v3) - 1].y);
		tri.sommet[2].z = (this->vecVtmp[static_cast<int>(vecFTmp[i].v3) - 1].z);
		Mesh.push_back(tri);
	}
	return (Mesh);
}


loadObjFile::loadObjFile(std::string caseToLoad, std::string fileToLoad)
{
	this->name = std::string("./res/shape3d/");
    this->name.append(caseToLoad);
	this->name.append("/");
	this->name.append(fileToLoad);
    this->getF();
}

loadObjFile::~loadObjFile()
{
}