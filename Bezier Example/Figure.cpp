#include "Figure.h"

#pragma region Constructors, Copy Constructor, Assignment Operator, Destructor

Figure::Figure()
{
	m_NumVertices = 3;

	m_Force = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Color = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Size = 0.1;

	SetOrigin(0, 0, 0, 0);
}

Figure::Figure(glm::vec4 color, int verts, float size, float x, float y, float z)
{
	if(verts < 3)
		m_NumVertices = 3;
	else
		m_NumVertices = verts;

	m_Force = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Color = color;
	m_Size = size;

	SetOrigin(x, y, z, 1.0f);
}

Figure::Figure(glm::vec4 color, int verts, float size, glm::vec3 location)
{
	if(verts < 3)
		m_NumVertices = 3;
	else
		m_NumVertices = verts;

	m_Force = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
	m_Color = color;
	m_Size = size;

	SetOrigin(location);
}

Figure::Figure(const Figure& other)
{
	m_NumVertices = other.m_NumVertices;

	m_vao = other.m_vao;
	m_Buffer = other.m_Buffer;

	m_Force = other.m_Force;
	m_Point = other.m_Point;
	m_VertexColor = other.m_VertexColor;
	m_Origin = other.m_Origin;
	m_Size = other.m_Size;

	m_Origin = other.m_Origin;
	m_Model = other.m_Model;
	m_Color = other.m_Color;
}

Figure& Figure::operator = (const Figure& other)
{
	Figure temp(other);
	Swap(temp);

	return *this;
}

Figure::~Figure()
{
	Release();
}

#pragma endregion

#pragma region Get/Set Size

void Figure::SetSize(float size)
{
	m_Size = size;
}

float& Figure::GetSize()
{
	return m_Size;
}

#pragma endregion

#pragma region Get/Set Origin

void Figure::SetOrigin(float x, float y, float z, float w)
{
	m_Origin.x = x;
	m_Origin.y = y;
	m_Origin.z = z;
	m_Origin.w = w;

	SetModel();
}

void Figure::SetOrigin(glm::vec3 location)
{
	m_Origin.x = location.x;
	m_Origin.y = location.y;
	m_Origin.z = location.z;
	m_Origin.w = 1.0f;

	SetModel();
}

glm::vec4& Figure::GetOrigin()
{
	return m_Origin;
}

#pragma endregion

#pragma region Get/Set Specified Vertex

void Figure::SetPoint(int index, float x, float y, float z, float w)
{
	if(index < 0 || index >= m_NumVertices || m_Point == nullptr)
		return;

	m_Point[index].x = x;
	m_Point[index].y = y;
	m_Point[index].z = z;
	m_Point[index].w = w;
}

void Figure::SetPoint(int index, glm::vec4 point)
{
	if(index < 0 || index >= m_NumVertices || m_Point == nullptr)
		return;

	m_Point[index] = point;
}

glm::vec4& Figure::GetPoint(unsigned int index)
{
	if(index < 0 || index >= m_NumVertices || m_Point == nullptr)
		return glm::vec4();

	else
		return m_Point[index];
}

void Figure::operator () (int index, float x, float y, float z, float w)
{
	if(index < 0 || index >= m_NumVertices || m_Point == nullptr)
		return;

	m_Point[index].x = x;
	m_Point[index].y = y;
	m_Point[index].z = z;
	m_Point[index].w = w;
}

void Figure::operator () (int index, glm::vec4 point)
{
	if(index < 0 || index >= m_NumVertices || m_Point == nullptr)
		return;

	m_Point[index] = point;
}

#pragma endregion

#pragma region Compile, Render, and Inherited Shape Methods

void Figure::CompileFigure()
{
	for(int i = 0; i < m_NumVertices; ++i)
		TranslateVertex(m_Point[i], m_Origin);

	InitBuffer();
}

void Figure::Render()
{
	glBindBuffer( GL_ARRAY_BUFFER, m_Buffer );

	// set up vertex arrays
    GLuint vPosition = glGetAttribLocation( programID, "vPosition" );
	GLuint vColor = glGetAttribLocation( programID, "vColor" ); 
	GLuint model = glGetUniformLocation( programID, "model" );

	glUniformMatrix4fv( model, 1, GL_TRUE, &m_Model[0][0] );

    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

	glEnableVertexAttribArray( vColor );
	/*glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(glm::vec4) * m_NumVertices) );*/

	glUniform4f(vPosition, m_Color.x, m_Color.y, m_Color.z, m_Color.w);
	glDrawArrays(GL_TRIANGLES, 0, m_NumVertices);
	glUniform4f(vPosition, 0.0f, 0.0f, 0.0f, 0.0f);
	glDrawArrays(GL_LINES, 0, m_NumVertices);
}

void Figure::GenerateShape()
{
	return;
}

#pragma endregion

#pragma region Private Methods

void Figure::InitBuffer()
{
	// Bind the Vertex Array Object
	glGenVertexArrays( 1, &m_vao );
	glBindVertexArray( m_vao );

	glGenBuffers( 1, &m_Buffer);
	glBindBuffer( GL_ARRAY_BUFFER, m_Buffer);
	glBufferData( GL_ARRAY_BUFFER, m_NumVertices * sizeof(glm::vec4), m_Point, GL_DYNAMIC_DRAW );
}

void Figure::Swap(Figure& other)
{
	std::swap(this->m_NumVertices, other.m_NumVertices);
	std::swap(this->m_Force, other.m_Force);
	std::swap(this->m_Point, other.m_Point);
	std::swap(this->m_VertexColor, other.m_VertexColor);
	std::swap(this->m_Origin, other.m_Origin);
	std::swap(this->m_Size, other.m_Size);
	std::swap(this->m_Buffer, other.m_Buffer);
	std::swap(this->m_vao, other.m_vao);
	std::swap(this->m_Model, other.m_Model);
	std::swap(this->m_Color, other.m_Color);
}

void Figure::Release()
{
	m_NumVertices = 0;
	if(m_Point != nullptr)
	{
		delete[] m_Point;
		m_Point = nullptr;
	}

	if(m_VertexColor != nullptr)
	{
		delete[] m_VertexColor;
		m_VertexColor = nullptr;
	}

	glDeleteBuffers(1, &m_Buffer);
	glDeleteVertexArrays(1, &m_vao);
}

void Figure::TranslateVertex(glm::vec4& point, glm::vec4& translation)
{
	point.x += translation.x;
	point.y += translation.y;
	point.z += translation.z;
	point.w += translation.w;
}

void Figure::SetModel()
{
	m_Model = glm::mat4(m_Size,	0,		0,		m_Origin.x,
						0,		m_Size,	0,		m_Origin.y,
						0,		0,		m_Size,	m_Origin.z,
						0,		0,		0,		1);
}

#pragma endregion