#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader.h>
#include <learnopengl/camera.h>
#include <iostream>

#include "main.h"
#include "window.h"
#include "glfw.h"
#include "VBO.h"
#include "VAO.h"
#include "texture.h"
#include "block.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);



unsigned int curr_width = 800;
unsigned int curr_height = 600;

int main()
{
    GLFW glfw;

    Window window{ SCR_WIDTH, SCR_HEIGHT, "minecraft clone"};
    {
        glfwSetFramebufferSizeCallback(window.m_window, framebuffer_size_callback);
        glfwSetCursorPosCallback(window.m_window, mouse_callback);
        glfwSetScrollCallback(window.m_window, scroll_callback);

        glfwSetInputMode(window.m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }
    Shader shader("src/shaders/shader.vs", "src/shaders/shader.fs");

    Texture texture("src/textures/test2.jpg", GL_RGB, GL_RGB);
    Texture texture2("src/textures/test.jpg", GL_RGB, GL_RGB);

    Block block;

    shader.use();
    shader.setInt("texture1", 0);
    shader.setInt("texture2", 1);

    
    while (!glfwWindowShouldClose(window.m_window))
    {
        {
            float currentFrame = static_cast<float>(glfwGetTime());
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
        }
        processInput(window.m_window);
        
        window.clear();
        //vao.bind();

        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)curr_width / (float)curr_height, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();

        shader.use();
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);


        texture.bind(0);
        texture2.bind(1);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0, 0, 0));
        shader.setMat4("model", model);

        block.draw();
        
        window.swapBuff();

        window.eventUpdate();

        window.m_width = curr_width;
        window.m_height = curr_height;
    }

    return 0;
}


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    curr_width = width;
    curr_height = height;

    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}