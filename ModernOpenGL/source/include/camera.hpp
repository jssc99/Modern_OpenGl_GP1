#pragma once

#include "basicmath.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace LowRenderer
{
	class Camera
	{
	public:
		Camera(int width, int height);
		~Camera() {};

		void processInput(GLFWwindow* window, float deltaTime);
		void processMouse(float xoffset, float yoffset);
		void ProcessScroll(float yoffset);

		mat4 getView();
		mat4 getPerspective();

		float speed = 8.f;

		vec3 position = { 0.f,0.f,5.f };
		vec3 front = { 0.f,0.f,-1.f };

	private:
		vec3 up = { 0.f,1.f,0.f };
		vec3 right, worldUp = up;

		float pitch = 0.f, yaw = -90.f;
		float sensitivity = .1f, zoom = 45.f;
		float near_ = .1f, far_ = 100.f, aspect;

		void updateCameraVectors();
	};
}