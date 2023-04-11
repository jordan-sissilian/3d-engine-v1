#ifndef CUBE_H
#define CUBE_H

#include "../mobjet.hpp"

class cube : public mObjet
{
private:
	

public:
	cube(std::vector<std::string> obj, shader*, unsigned int);
	~cube();
};

#endif