#version 330 core

layout (location = 0) in vec3 pos;
//layout (location = 1) in vec3 color;
layout (location = 1) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//out vec3 vert_color;
out vec3 Normal;
out vec3 FragPos;

void main()
{
//  vert_color = color;
	Normal = normal;
	gl_Position = projection * view * model * vec4(pos, 1.0);
};

//#version 330 core
//layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aNormal;
//
//out vec3 FragPos;
//out vec3 Normal;
//
//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;
//
//void main()
//{
//    FragPos = vec3(model * vec4(aPos, 1.0));
//    Normal = aNormal;  
//    gl_Position = projection * view * model * vec4(FragPos, 1.0);
//}
