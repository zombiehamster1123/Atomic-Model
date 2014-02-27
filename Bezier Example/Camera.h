#ifndef CAMERA_H
#define CAMERA_H

#include <GL\glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Constants.h"
#include "Globals.h"
#include "Window.h"

struct Camera
{

public:
	Camera();
	~Camera();
	
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

	glm::vec3 Getdirection();
	glm::vec3 GetPosition();

	void ComputeMatrices();
	static Camera* GetInstance();

private:
	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;

	glm::vec3 position;
	float horizontalAngle;
	float verticalAngle;
	float initalFoV;

	float speed;
	float mouseSpeed;

	static Camera* instance;
};

#endif

