#version 330 core

//in vec3 vert_color;
in vec3 Normal;
out vec4 frag_color;

void main()
{
    frag_color = vec4(Normal, 1.0f);
};

//#version 330 core 
//out vec4 FragColor;
//
//in vec3 Normal;  
//in vec3 FragPos;  
//
//struct DirLight {
//    vec3 direction;
//    vec3 ambient;
//    vec3 diffuse;
//    vec3 specular;
//};
//
//uniform DirLight dirLight;
//
//uniform vec3 viewPos;
//
//void main()
//{
//    // Directional light
//    vec3 norm = normalize(Normal);
//    vec3 lightDir = normalize(-dirLight.direction);
//    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = dirLight.diffuse * diff;
//    
//    // Calculate final color
//    vec3 result = diffuse;
//    FragColor = vec4(result, 1.0);
//}
