#include "../include/texture.hpp"

void texture::bind(shader* mshader)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->idTexture);

    GLint textureSamplerUniform = glGetUniformLocation(mshader->getShaderProgram(), "textureSampler");

    glUniform1i(textureSamplerUniform, 0);

    GLint posTextureAttrib = glGetAttribLocation(mshader->getShaderProgram(), "positionTexture");

    const GLvoid* offset = (const GLvoid*)offsetof(sommetTriangle, u);
    glVertexAttribPointer(posTextureAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(sommetTriangle), offset);
    glEnableVertexAttribArray(posTextureAttrib);
}


texture::texture(std::string name)
{
    this->width = 0;
    this->height = 0;
    this->idTexture = SOIL_load_OGL_texture(name.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);
}

texture::~texture()
{
    SOIL_free_image_data(this->data);
}
