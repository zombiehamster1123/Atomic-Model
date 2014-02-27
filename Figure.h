#ifndef FIGURE_H
#define FIGURE_H

#pragma region Includes

#include <iostream>
#include <GL\glew.h>
#include "Globals.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "Colors.h"

#pragma endregion

// Polymorphed Base Figure Class
class Figure
{
public:

#pragma region Constructors, Copy Constructor, Assignment Operator, Destructor

	// Empty Constructor
	Figure();

	// Number of vertices, the size, and the location in floats
	Figure(glm::vec4 color, int verts, float size, float x, float y, float z);

	// Number of vertices, the size, and the lcoation in a 3 dimensional vector
	Figure(glm::vec4 color, int verts, float size, glm::vec3 location);

	// Copy Constructor
	Figure(const Figure&);

	// Copy Assignment Operator
	Figure& operator = (const Figure&);

	// Destructor
	~Figure();

#pragma endregion

#pragma region Get/Set Size

	// Set the size of the figure
	void SetSize(float size);

	// Get the size of the figure
	float& GetSize();

#pragma endregion

#pragma region Get/Set Origin

	// Set the origin based on four floats
	void SetOrigin(float x, float y, float w, float z);

	// Set the origin based on a 3D vector
	void SetOrigin(glm::vec3 location);

	glm::vec4& GetOrigin();

#pragma endregion

#pragma region Get/Set Specified Vertex

	// Specify which vertex you wish to replace with four floats
	void SetPoint(int index, float x, float y, float z, float w);

	// Specify which vertex to change with a 4 dimnesional vector
	void SetPoint(int index, glm::vec4 point);

	// Return specified point
	glm::vec4& GetPoint(unsigned int index);

	// Same as SetPoint but with the () operator
	void operator()(int index, float x, float y, float z, float w);

	// Same as SetPoint but with the () operator
	void operator()(int index, glm::vec4 point);

#pragma endregion

#pragma region Compile, Render, and Inherited Shape Methods

	// Adjust the points of the figure
	void CompileFigure();

	// Render the figure on screen
	void Render();

	// Inherited method meant to both construct shapes and generate their vertices
	virtual void GenerateShape();

#pragma endregion

protected:

#pragma region Attributes

	glm::vec4 m_Origin;			// Origin Point
	int m_NumVertices;			// Number of vertices
	glm::vec4* m_Point;			// Pointer to array of 4 dimensional vertices
	glm::vec4* m_VertexColor;	// Pointer to array of 4 dimensional vertices
	float m_Size;

	GLuint m_vao;				// Vertex Array Object
	GLuint m_Buffer;			// Buffer Object

	glm::mat4 m_Model;			// 4 dimensional model of figures location for camera
	glm::vec4 m_Force;			// A force enacted on an object
	glm::vec4 m_Color;			// The color of the object

#pragma endregion

#pragma region Private Methods

	// Initialize the buffer of the figure object for the graphics card
	void InitBuffer();

	// Swap the values from another figure object with this
	void Swap(Figure&);

	// Free all of the memory used by this project
	void Release();

	// Translate the specified 4 dimensional point by the specified amount
	void TranslateVertex(glm::vec4& point, glm::vec4& translation);

	// Set the 4 dimensional model matrix of the figure's location for the camera to use
	void SetModel();

#pragma endregion

};

#endif
