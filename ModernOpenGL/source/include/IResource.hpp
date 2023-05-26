#pragma once

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <string>

#include "debug.hpp"

namespace Resources {
	class IResource
	{
	public:
		virtual void loadResource(fs::path filePath) = 0;
		void loadFromPath()
		{
			if (path != "") loadResource(path);
		};

		unsigned int ID = 0;
		fs::path path;
	};
}