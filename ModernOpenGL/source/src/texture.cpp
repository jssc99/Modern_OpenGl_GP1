#include "../include/texture.hpp"
#include "../include/debug.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace Resources;

void Texture::use()
{
	glActiveTexture(GL_TEXTURE0 + (ID - 1));
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::stopUse()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::loadResource(fs::path filePath)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	DEBUG_LOG("loading: %s", filePath.string().c_str());
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filePath.string().c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		if (nrChannels == 1)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
		else if (nrChannels == 2)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, data);
		else if (nrChannels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		else if (nrChannels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		else
			DEBUG_LOG("Failed to load texture because of nrChannels: %s", filePath.string().c_str());

		glGenerateMipmap(GL_TEXTURE_2D);

		path = filePath;
	}
	else
		DEBUG_LOG("Failed to load texture because of wrong filePath: %s", filePath.string().c_str());

	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
}