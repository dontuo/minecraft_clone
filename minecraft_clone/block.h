#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "texture.h"
//#include "EBO.h"
#include "VAO.h"
#include "VBO.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*static GLfloat cube_vertices[] = {
    // front
    -1.0, -1.0,  1.0,
     1.0, -1.0,  1.0,
     1.0,  1.0,  1.0,
    -1.0,  1.0,  1.0,
    // back
    -1.0, -1.0, -1.0,
     1.0, -1.0, -1.0,
     1.0,  1.0, -1.0,
    -1.0,  1.0, -1.0
};*/
/*
static GLushort cube_elements[] = {
    // front
    0, 1, 2,
    2, 3, 0,
    // right
    1, 5, 6,
    6, 2, 1,
    // back
    7, 6, 5,
    5, 4, 7,
    // left
    4, 0, 3,
    3, 7, 4,
    // bottom
    4, 5, 1,
    1, 0, 4,
    // top
    3, 2, 6,
    6, 7, 3,
};*/

/*
GLushort front_elements[] =
{
    // front
    0, 1, 2,
    2, 3, 0,
};

GLushort right_elements[] =
{
    // right
    1, 5, 6,
    6, 2, 1,
};

GLushort back_elements[] =
{
    7, 6, 5,
    5, 4, 7,
};


GLushort left_elements[] =
{
    4, 0, 3,
    3, 7, 4,
};

GLushort bottom_elements[] =
{
    4, 5, 1,
    1, 0, 4,
};

GLushort top_elements[] =
{
    3, 2, 6,
    6, 7, 3
};
*/
static float uvs[] =
{
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,

    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f, 
};


static float cube_vertices[] = {
        -1.f, -1.f, -1.f, //front
         1.f, -1.f, -1.f,
         1.f,  1.f, -1.f,
         1.f,  1.f, -1.f,
        -1.f,  1.f, -1.f,
        -1.f, -1.f, -1.f,

        -1.f, -1.f,  1.f,
         1.f, -1.f,  1.f,
         1.f,  1.f,  1.f,
         1.f,  1.f,  1.f,
        -1.f,  1.f,  1.f,
        -1.f, -1.f,  1.f,

        -1.f,  1.f,  1.f,
        -1.f,  1.f, -1.f,
        -1.f, -1.f, -1.f,
        -1.f, -1.f, -1.f,
        -1.f, -1.f,  1.f,
        -1.f,  1.f,  1.f,

         1.f,  1.f,  1.f,
         1.f,  1.f, -1.f,
         1.f, -1.f, -1.f,
         1.f, -1.f, -1.f,
         1.f, -1.f,  1.f,
         1.f,  1.f,  1.f,

        -1.f, -1.f, -1.f,
         1.f, -1.f, -1.f,
         1.f, -1.f,  1.f,
         1.f, -1.f,  1.f,
        -1.f, -1.f,  1.f,
        -1.f, -1.f, -1.f,

        -1.f,  1.f, -1.f,
         1.f,  1.f, -1.f,
         1.f,  1.f,  1.f,
         1.f,  1.f,  1.f,
        -1.f,  1.f,  1.f,
        -1.f,  1.f, -1.f,
};

enum Id : int
{
	AIR = 0,
	GRASS,
	STONE,
};

class Block
{
public:
    glm::vec3 m_coordinate{ 0.0f };
        
    //float* m_cube_data = cube_vertices;
    VBO uv;
    VBO m_vbo_data;
    VAO m_vao;
    //EBO m_ebo;

    // 0: back
    // 1: front
    // 2: left
    // 3: right
    // 4: bottom
    // 5: top
    bool isdrawable[6] = { 1,1,1,1,1,1 }; 
    Id m_id = Id::STONE;

    void push_Data();
    Block();

    //Texture m_front_Texture;

	void draw();
};