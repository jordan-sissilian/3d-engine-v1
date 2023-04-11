#include "../../include/shape/map.hpp"

map::map(std::vector<std::string> obj, shader* mShader, unsigned int drawtype) : mObjet(obj, mShader, drawtype)
{

}

map::~map()
{ }