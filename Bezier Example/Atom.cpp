#include "Atom.h"

Atom::Atom(int protons, int neutrons)
{
	m_NumProtons = protons;
	m_NumNeutrons = neutrons;
	m_NumElectrons = m_NumProtons;

	if(m_NumProtons < 5)
	{
		MINRANGE = 0.1;
		MAXRANGE = 0.4;
	}
	else if(m_NumProtons > 5 && m_NumProtons < 10)
	{
		MINRANGE = 0.4;
		MAXRANGE = 0.7;
	}

	else
	{
		MINRANGE = 0.5;
		MAXRANGE = 1.2;
	}

	for(int i = 0; i < m_NumProtons; ++i)
	{
		float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (MAXRANGE - MINRANGE));
		float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (MAXRANGE - MINRANGE));
		float z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (MAXRANGE - MINRANGE));
		m_Protons.push_back(new Sphere(PROTONCOLOR, PROTONSIZE, glm::vec3(x, y, -z)));
	}

	for(int i = 0; i < m_NumNeutrons; ++i)
	{
		float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (MINRANGE));
		float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (MAXRANGE - MINRANGE));
		float z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (MAXRANGE - MINRANGE));
		m_Neutrons.push_back(new Sphere(NEUTRONCOLOR, PROTONSIZE, glm::vec3(x, y, -z)));
	}

	FillElectrons();
}

Atom::~Atom()
{
	Remove(m_Protons);
	Remove(m_Neutrons);
	Remove(m_Electrons);
}

void Atom::FillVector(std::vector<Sphere*>& spheres, int num, glm::vec4 location)
{
	for(int i = 0; i < num; ++i)
	{
		float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (0.5));
		float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (1.0 - 0.5));
		float z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (1.0 - 0.5));
		spheres.push_back(new Sphere(PROTONCOLOR, PROTONSIZE, glm::vec3(x, y, -z)));
	}
}

void Atom::Remove(std::vector<Sphere*>& spheres)
{
	int spheresLength = spheres.size();
	for( int i = 0; i < spheresLength; ++i )
	{
		delete spheres[i];
	}

	// empty vector
	spheres.clear();
}

void Atom::Render(std::vector<Sphere*>& spheres)
{
	for( int i = 0; i < spheres.size(); ++i )
		spheres[i]->Render();
}

void Atom::RenderAll()
{
	Render(m_Protons);
	Render(m_Neutrons);
	Render(m_Electrons);
}

void Atom::Move(std::vector<Sphere*>& spheres)
{
	glm::vec3 u = glm::vec3(0.1, 0.2, 0.3);

	int length = spheres.size();
	int current = 0;
	int speed = 1000;

	for(int i = 0; i < length; ++i)
	{
		if(i >= 4)
		{
			i = 0;
			length -= 4;
			if(speed >= 100)
				speed -= 20;
		}

		if(length >= 0)
		{
			switch (i)
			{
			case 0:
				ChangeSpeed(speed);
				RotateXYZ(u, spheres[current]);
				break;
			case 1:
				ChangeSpeed(speed);
				RotateZ(u, spheres[current]);
				break;
			case 2:
				ChangeSpeed(speed);
				RotateZ(u, spheres[current]);
				break;
			case 3:
				ChangeSpeed(speed);
				RotateXYZ(u, spheres[current]);
				break;
			}
		}

		++current;
	}
}

void Atom::Update()
{
	Move(m_Electrons);
}

void Atom::Around(float displacement)
{
	m_Electrons.push_back(new Sphere(ELECTRONCOLOR, ELECTRONSIZE, displacement, 0.0, 0.0));
	m_Electrons.push_back(new Sphere(ELECTRONCOLOR, ELECTRONSIZE, 0.0, displacement, 0.0));
	m_Electrons.push_back(new Sphere(ELECTRONCOLOR, ELECTRONSIZE, -displacement, 0.0, 0.0));
	m_Electrons.push_back(new Sphere(ELECTRONCOLOR, ELECTRONSIZE, 0.0, -displacement, 0.0));
}

void Atom::FillValence(float displacement)
{
	valences[0] = glm::vec3(displacement, 0.0, 0.0);
	valences[1] = glm::vec3(0.0, displacement, 0.0);
	valences[2] = glm::vec3(-displacement, 0.0, 0.0);
	valences[3] = glm::vec3(0.0, -displacement, 0.0);
}

void Atom::FillShells(int numShells)
{
	for(float i = 0.8; i < numShells; ++i)
	{
		float j = i + DISPLACEMENT;
		Around(i);
		Around(j);
	}
}

void Atom::FillElectrons()
{
	float temp = m_NumElectrons;

	int numShells = temp / 8;
	int remaining = temp - (numShells * 8);

	FillShells(numShells);

	// New Stuff as of 12/10
	float displacement = numShells + .8;

	FillValence(displacement);

	if(remaining < 4)
	{
		for(int i = 0; i < remaining; ++i)
			m_Electrons.push_back(new Sphere(ELECTRONCOLOR, ELECTRONSIZE, valences[i]));
	}

	else
	{
		for(int i = 0; i < 4; ++i)
		{
			m_Electrons.push_back(new Sphere(ELECTRONCOLOR, ELECTRONSIZE, valences[i]));
			--remaining;
		}

		displacement += DISPLACEMENT;
		FillValence(displacement);

		for(int i = 0; i < remaining; ++i)
			m_Electrons.push_back(new Sphere(ELECTRONCOLOR, ELECTRONSIZE, valences[i]));
	}
	
}