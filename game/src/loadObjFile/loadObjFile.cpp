#include "../../include/loadObjFile/loadObjFile.hpp"

std::vector<triangle> loadObjFile::getMesh()
{
	std::vector<triangle> mMesh;
	triangle tri;

	for (const auto& fTmp : this->vecFTmp) {
    	triangle tri;
    	for (int j = 0; j < 3; j++) {
        	tri.sommet[j].x = this->vecVtmp[fTmp.v[j] - 1].x;
        	tri.sommet[j].y = this->vecVtmp[fTmp.v[j] - 1].y;
        	tri.sommet[j].z = this->vecVtmp[fTmp.v[j] - 1].z;

        	tri.sommet[j].u = this->vecVtTmp[fTmp.vt[j] - 1].u;
        	tri.sommet[j].v = this->vecVtTmp[fTmp.vt[j] - 1].v;
    	}
    	mMesh.push_back(tri);
	}
 	return (mMesh);
}

std::string loadObjFile::getTextureName()
{
	return (this->textureName == "error" ? (this->textureName = "error.jpg") : this->textureName);
}

static int getVersion(std::string line)
{
	int mversion = 0;

	for (int j = 0; j < line.size(); j++)
		line[j] == '/' && mversion++;
	if (mversion == 0)
		mversion = 1;
	else if (mversion == 3)
		mversion = 2;
	else
		mversion = 3;
	return (mversion);
}

v loadObjFile::getV(std::string line)
{
	v tmp;
	line.erase(0, 2);
	std::istringstream iss(line);
	iss >> tmp.x >> tmp.y >> tmp.z;
	return (tmp);
}

vt loadObjFile::getVt(std::string line)
{
	vt tmp;
	line.erase(0, 2);
	std::istringstream iss(line);
	iss >> tmp.u >> tmp.v;
	return (tmp);
}

vn loadObjFile::getVn(std::string line)
{
	vn tmp;
	line.erase(0, 2);
	std::istringstream iss(line);
	iss >> tmp.x >> tmp.y >> tmp.z;
	return (tmp);
}

static f takeinfo(std::string line, int v)
{
	f tmp;
	std::istringstream iss = std::istringstream(line);

	switch (v) {
	case 1:
		iss >> tmp.v[0] >> tmp.v[1] >> tmp.v[2];
		break;
	case 2:
		iss >> tmp.v[0] >> tmp.vt[0] >> tmp.v[1] >> tmp.vt[1] >> tmp.v[2] >> tmp.vt[2];
		break;
	case 3:
		iss >> tmp.v[0] >> tmp.vt[0] >> tmp.vn[0] >> tmp.v[1] >> tmp.vt[1] >> tmp.vn[1] >> tmp.v[2] >> tmp.vt[2] >> tmp.vn[2];
		break;
	}
	return (tmp);
}

f loadObjFile::mgetF(std::string line)
{
	this->version = getVersion(line);
	line.erase(0, 2);
	for (size_t pos = 0; (pos = line.find('/', pos)) != std::string::npos; pos++)
        line.replace(pos, 1, 1, ' ');
	return (takeinfo(line, this->version));
}

void loadObjFile::getF()
{
	std::fstream fileTmp = std::fstream(this->name, std::ios::in);

	for (std::string lineTmp; std::getline(fileTmp, lineTmp) ;) {
		const char *tmpStr = lineTmp.c_str();

		if (!std::strncmp(tmpStr, "textureName ", 12)) {
    		this->textureName = std::string(tmpStr + 12);
			std::cout << this->textureName << std::endl;
		}
		else if (!std::strncmp(tmpStr, "v ", 2))
			this->vecVtmp.push_back(this->getV(lineTmp));
		else if (!std::strncmp(tmpStr, "vt", 2))
			this->vecVtTmp.push_back(this->getVt(lineTmp));
		else if (!std::strncmp(tmpStr, "vn", 2))
			this->vecVnTmp.push_back(this->getVn(lineTmp));
		else if (!std::strncmp(tmpStr, "f ", 2))
			this->vecFTmp.push_back(this->mgetF(lineTmp));
	}
    fileTmp.close();
}

loadObjFile::loadObjFile(std::string caseToLoad, std::string fileToLoad)
	:	caseToLoad(caseToLoad),
		fileToLoad(fileToLoad)
{
	this->name = std::string("./res/shape3d/" + caseToLoad + "/" + fileToLoad);
    this->getF();
}