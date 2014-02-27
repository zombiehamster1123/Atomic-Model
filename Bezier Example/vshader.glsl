#version 150 

in  vec4 vPosition;
in  vec4 vColor;
out vec4 color;

// Model View Prospective Matrices - http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() 
{
	gl_PointSize = 10;	// Size of Points rendered
    gl_Position = projection * view * model * vPosition/vPosition.w;
    color = vColor;
} 