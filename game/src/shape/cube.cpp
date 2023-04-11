#include "../../include/shape/cube.hpp"

cube::cube(std::vector<std::string> obj, shader* mShader, unsigned int drawtype) : mObjet(obj, mShader, drawtype)
{

}

cube::~cube()
{ }