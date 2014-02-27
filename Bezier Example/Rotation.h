#ifndef ROTATION_H
#define ROTATION_H

#include "Constants.h"
#include "Atom.h"

static int SPEED = 400;

void ChangeSpeed(int);

void RotateX(const glm::vec3, Figure*);
void RotateY(const glm::vec3, Figure*);
void RotateZ(const glm::vec3, Figure*);
void RotateXYZ(const glm::vec3, Figure*);

#endif