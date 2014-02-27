#include "Sphere.h"

Sphere::Sphere(glm::vec4 color, float _size, float _originX, float _originY, float _originZ ) :
	Figure(color, 64, _size, _originX, _originY, _originZ)
{
	Index = 0;

	m_Point = new glm::vec4[m_NumVertices];

	MakePoints();
	CompileFigure();
}

Sphere::Sphere(glm::vec4 color, float _size, glm::vec3 location ) :
	Figure(color, 64, _size, location)
{
	Index = 0;

	m_Point = new glm::vec4[m_NumVertices];

	MakePoints();
	CompileFigure();
}

Sphere::Sphere(const Sphere& other) :
	Figure(other)
{
	Index = 0;

	m_Point = other.m_Point;

	MakePoints();
	CompileFigure();
}

Sphere& Sphere::operator = (const Sphere& other)
{
	Index = 0;

	Sphere temp(other);
	Swap(temp);

	return *this;
}

Sphere::~Sphere()
{
	Release();
}

void Sphere::GenerateVertices()
{
	float t = ((1.0 + sqrt(5.0)) / 2.0) * m_Size;
	float w = m_Size;

	vertices[0] = glm::vec4( -w, t, 0, 1.0 );
	vertices[1] = glm::vec4( w, t, 0, 1.0 );
	vertices[2] = glm::vec4( -w, -t, 0, 1.0 );
	vertices[3] = glm::vec4( w, -t, 0, 1.0 );

	vertices[4] = glm::vec4( 0, -w, t, 1.0 );
	vertices[5] = glm::vec4( 0, w, t, 1.0 );
	vertices[6] = glm::vec4( 0, -w, -t, 1.0 );
	vertices[7] = glm::vec4( 0, w, -t, 1.0 );

	vertices[8] = glm::vec4( t, 0, -w, 1.0 );
	vertices[9] = glm::vec4( t, 0, w, 1.0 );
	vertices[10] = glm::vec4( -t, 0, -w, 1.0 );
	vertices[11] = glm::vec4( -t, 0, w, 1.0 );
}

void Sphere::Triangle(int a, int b, int c)
{
	Color temp = Color();
	this->GetPoint(Index) = vertices[a]; ++Index;
	this->GetPoint(Index) = vertices[b]; ++Index;
	this->GetPoint(Index) = vertices[c]; ++Index;
}

void Sphere::MakePoints()
{
	GenerateVertices();

	Triangle(0, 11, 5);
	Triangle(0, 5, 1);
	Triangle(0, 1, 7);
	Triangle(0, 7, 10);
	Triangle(0, 10, 11);

	Triangle(1, 5, 9);
	Triangle(5, 11, 4);
	Triangle(11, 10, 2);
	Triangle(10, 7, 6);
	Triangle(7, 1, 8);

	Triangle(3, 9, 4);
	Triangle(3, 4, 2);
	Triangle(3, 2, 6);
	Triangle(3, 6, 8);
	Triangle(3, 8, 9);

	Triangle(4, 9, 5);
	Triangle(2, 4, 11);
	Triangle(6, 2, 10);
	Triangle(8, 6, 7);
	Triangle(9, 8, 1);

	Index = 0;
}

void Sphere::GenerateShape()
{
	MakePoints();
	CompileFigure();
}