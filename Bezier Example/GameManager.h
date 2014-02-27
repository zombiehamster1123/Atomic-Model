#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Rotation.h"
#include <GL/glew.h>
#include "Camera.h"

class GameManager sealed
{
public:
	GameManager(void);
	~GameManager(void);

	void initalize();
	void update();
	void display();

	void ChangeAtom(int protons, int neutrons);
	void CheckKeyboard();

private:
	Camera* m_Camera;
	Atom* atom;

	GLuint _viewID, _projectionID;
	glm::mat4 ProjectionMatrix, ViewMatrix;

	int num;
	int typeOfElement;
};

#endif

