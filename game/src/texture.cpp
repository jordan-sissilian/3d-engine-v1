#include "../include/texture.hpp"

void texture::bind(shader* mshader)
{
    
    glGetAttribLocation(mshader->getShaderProgram(), "positionTexture");
    glUniform1i(glGetUniformLocation(mshader->getShaderProgram(), "textureSampler"), 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(sommetTriangle), (void*)offsetof(sommetTriangle, u));
    glEnableVertexAttribArray(1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->idTexture);
}

texture::texture(std::string name, int height, int width)
{
    this->width = width;
    this->height = height;
    this->data = SOIL_load_image(name.c_str(), &this->width, &this->height, &this->channels, SOIL_LOAD_RGB);

    glGenTextures(1, &this->idTexture);
    glBindTexture(GL_TEXTURE_2D, this->idTexture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}


texture::~texture()
{
    SOIL_free_image_data(this->data);
}
