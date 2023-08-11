#include "block.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "texture.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

void Block::push_Data()
{
    m_data_vertices.push_data(sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
    m_data_vertices.bind();
    m_vao.push_data(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    //m_vao.push_data(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(sizeof(float) * 3));

    
    uv.push_data(sizeof(uvs), uvs, GL_STATIC_DRAW);
    uv.bind();
    m_vao.push_data(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    
    //m_data_vertices.push_data(sizeof(uvs), uvs, GL_STATIC_DRAW);
    //m_ebo.push_data(sizeof(cube_elements), cube_elements, GL_UNSIGNED_SHORT);
}

Block::Block()
{
    Block::push_Data();
}

void Block::draw()
{
    int offset = 0;
    for (auto side : isdrawable)
    {
        
        if (side)
        {
            m_vao.bind();
            m_vao.bind();
            m_ebo.bind();
            
            glDrawArrays(GL_TRIANGLES, offset, 6);
            /*glDrawArrays(GL_TRIANGLES, 6, 6);
            glDrawArrays(GL_TRIANGLES, 12, 6);
            glDrawArrays(GL_TRIANGLES, 18, 6);
            glDrawArrays(GL_TRIANGLES, 24, 6);
            glDrawArrays(GL_TRIANGLES, 30, 6);*/

            //glDrawArrays(GL_TRIANGLES, 36, 6);
            //glDrawArrays(GL_TRIANGLES, 48, 6);
            //glDrawArrays(GL_TRIANGLES, 50, 6);
        }
        offset += 6;
    }
}