#include "Rotation.h"

void ChangeSpeed(int newSpeed)
{
	SPEED = newSpeed;
}

void RotateX(const glm::vec3 anOrigin, Figure* aCube)
{
	glm::vec3 diff(aCube->GetOrigin().x - anOrigin.x, aCube->GetOrigin().y - anOrigin.y, aCube->GetOrigin().z - anOrigin.z); 
	float y, z, theta = 0;

	theta = static_cast<float>(2*PI/SPEED);
	y = static_cast<float>(diff.y * cos(theta) - diff.z * sin(theta) + anOrigin.y);
	z = static_cast<float>(diff.y * sin(theta) + diff.z * cos(theta) + anOrigin.z);

	aCube->SetOrigin(aCube->GetOrigin().x, y, z, 1.0);
}

void RotateY(const glm::vec3 anOrigin, Figure* aCube)
{
	glm::vec3 diff(aCube->GetOrigin().x - anOrigin.x, aCube->GetOrigin().y - anOrigin.y, aCube->GetOrigin().z - anOrigin.z); 
	float x, z, theta = 0;

	theta = static_cast<float>(2*PI/SPEED);
	x = static_cast<float>(diff.x * cos(theta) + diff.z * sin(theta) + anOrigin.x);
	z = static_cast<float>(-diff.x * sin(theta) + diff.z * cos(theta) + anOrigin.z);

	aCube->SetOrigin(x, aCube->GetOrigin().y, z, 1.0);
}

void RotateZ(const glm::vec3 anOrigin, Figure* aCube)
{
	glm::vec3 diff(aCube->GetOrigin().x - anOrigin.x, aCube->GetOrigin().y - anOrigin.y, aCube->GetOrigin().z - anOrigin.z); 
	float y, x, theta = 0;

	theta = static_cast<float>(2*PI/SPEED);
	x = static_cast<float>(diff.x * cos(theta) + diff.y * -sin(theta) + anOrigin.x);
	y = static_cast<float>(diff.x * sin(theta) + diff.y * cos(theta) + anOrigin.y);

	aCube->SetOrigin(x, y, aCube->GetOrigin().z, 1.0);
}

void RotateXYZ(const glm::vec3 anOrigin, Figure* aCube)
{
	glm::vec3 u = glm::normalize(anOrigin);
	glm::vec3 diff(aCube->GetOrigin().x - anOrigin.x, aCube->GetOrigin().y - anOrigin.y, aCube->GetOrigin().z - anOrigin.z); 
	float x, y, z, theta = 0;

	theta = static_cast<float>(2*PI/SPEED);
	x = static_cast<float>(diff.x * (cos(theta) + (u.x * u.x * (1-cos(theta)))) + diff.y * (u.x * u.y * (1 - cos(theta)) - u.z * sin(theta)) + diff.z * (u.x * u.z * (1 - cos(theta)) + u.y * sin(theta)) + anOrigin.x);
	y = static_cast<float>(diff.x * (u.y * u.x * (1 - cos(theta)) + u.z * sin(theta)) + diff.y * (cos(theta) + (u.y * u.y * (1 - cos(theta)))) + diff.z * (u.y * u.z * (1 - cos(theta)) - u.x * sin(theta)) + anOrigin.y);
	z = static_cast<float>(diff.x * (u.z * u.y * (1 - cos(theta)) - u.y * sin(theta)) + diff.y * (u.z * u.y * (1 - cos(theta)) + u.x * sin(theta)) + diff.z * (cos(theta) + u.z * u.z * (1 - cos(theta))) + anOrigin.z);

	aCube->SetOrigin(x, y, z, 1.0);
}