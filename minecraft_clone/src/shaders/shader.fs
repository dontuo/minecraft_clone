#version 330 core
out vec4 FragColor;
uniform sampler2D texture1;
uniform sampler2D texture2;
in vec2 texCord;

void main()
{
    //texture2 =1;

    FragColor = mix(texture(texture1, texCord), texture(texture2, texCord), 0.5f); //vec4(.2f, 0.8f, 0.2f, 1.0f);
}