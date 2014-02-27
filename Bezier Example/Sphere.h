#ifndef SPHERE_H
#define SPHERE_H

#include "Figure.h"

const glm::vec4 SPHERECOLOR = glm::vec4(0.0, 1.0, 0.0, 1.0);

class Sphere : public Figure
{
public:
	Sphere(glm::vec4 color, float _size, float _x, float _y, float _z);
	Sphere(glm::vec4 color, float _size, glm::vec3 location);
	Sphere(const Sphere&);
	Sphere& operator = (const Sphere&);
	~Sphere();

	void GenerateShape();

private:
	int Index;				// Index for making faces on the sphere
	glm::vec4 vertices[12];	// 

	void GenerateVertices();
	void Triangle(int, int, int );
	void MakePoints();
};

#endif