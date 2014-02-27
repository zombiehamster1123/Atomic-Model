#ifndef ATOM_H
#define ATOM_H

#include <vector>
#include "Sphere.h"
#include "Rotation.h"
#include <random>

const float ELECTRONSIZE = 0.2;
const float DISPLACEMENT = 0.05;
static float PROTONSIZE = 0.3;

static float MINRANGE = 0.5;
static float MAXRANGE = 1.0;

const glm::vec4 PROTONCOLOR = glm::vec4(0.0, 1.0, 0.0, 1.0);
const glm::vec4 ELECTRONCOLOR = glm::vec4(0.0, 0.0, 1.0, 1.0);
const glm::vec4 NEUTRONCOLOR = glm::vec4(1.0, 0.0, 0.0, 1.0);

class Atom
{
public:
	Atom(int, int);
	~Atom();

	void Render(std::vector<Sphere*>&);
	void RenderAll();

	void Move(std::vector<Sphere*>&);
	void Update();

	void FillElectrons();
	void FillShells(int numShells);
	void Around(float displacement);
	void FillValence(float displacement);

private:
	int m_NumProtons;
	int m_NumNeutrons;
	int m_NumElectrons;

	std::vector<Sphere*> m_Protons;
	std::vector<Sphere*> m_Neutrons;
	std::vector<Sphere*> m_Electrons;

	glm::vec3 valences[4];

	void FillVector(std::vector<Sphere*>& spheres, int num, glm::vec4 color);
	void Remove(std::vector<Sphere*>&);
};

#endif