#ifndef MAP_H
#define MAP_H

#include "../mobjet.hpp"

class map : public mObjet
{
private:
	

public:
	map(std::vector<std::string> obj, shader*, unsigned int);
	~map();
};

#endif