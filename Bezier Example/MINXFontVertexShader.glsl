#version 120

attribute vec4 coord;
varying vec2 texpos;

void main()
{
	gl_Position = vec4(coord.xy, 0.0, 1.0);
	texpos = coord.zw;
}