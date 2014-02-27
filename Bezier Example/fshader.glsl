#version 150

out vec4  fColor;
uniform vec4 fColorIn;

void
main()
{
    fColor = fColorIn;
}

//#version 150
//
//in vec4 color;
//out vec4  fColor;
//
//void
//main()
//{
//    fColor = color;
//}
