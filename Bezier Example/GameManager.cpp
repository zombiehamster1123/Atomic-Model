#include "GameManager.h"

#pragma region Constructor
GameManager::GameManager(void)
{
	m_Camera =  Camera::GetInstance();
	num = 1;
	typeOfElement = 0;
}
#pragma endregion

#pragma region Deconstructor
GameManager::~GameManager(void)
{
	delete m_Camera;
}
#pragma endregion

#pragma region Display
void GameManager::display()
{
	// Compute the MVP matrix from keyboard and mouse input
	m_Camera->ComputeMatrices();
	ProjectionMatrix = m_Camera->getProjectionMatrix();
	ViewMatrix = m_Camera->getViewMatrix();

	glUniformMatrix4fv(_viewID, 1, GL_FALSE, &ViewMatrix[0][0]);
	glUniformMatrix4fv(_projectionID, 1, GL_FALSE, &ProjectionMatrix[0][0]);

	atom->RenderAll();
}
#pragma endregion

#pragma region Initalize
void GameManager::initalize()
{
	// Get a handle for our "MVP" uniforms
	_viewID			= glGetUniformLocation(programID, "view");
	_projectionID	= glGetUniformLocation(programID, "projection");

	//atom = nullptr;
	atom = new Atom(120,120);
}
#pragma endregion

#pragma region Update
void GameManager::update()
{
	atom->Update();
}
#pragma endregion

void GameManager::ChangeAtom(int protons, int neutrons)
{
	delete atom;
	atom = new Atom(protons,neutrons);
}

void GameManager::CheckKeyboard()
{
	if(num <= 118)
	{
		if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS ){
			++num;
			ChangeAtom(num, num);
		}
		
		else if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS ){
			if(num >= 1)
			{
				ChangeAtom(num, num);
				--num;
			}
		}
	}

	if (glfwGetKey( window, GLFW_KEY_R ) == GLFW_PRESS  )
	{
		num = 1;
		ChangeAtom(num, 0);
	}
		
}