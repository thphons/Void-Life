//
//  GLControl.cpp
//  Void Life
//
//  Created by Cal McLelland on 17-02-14.
//  Copyright (c) 2017 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "GLControl.h"

GLControl::GLControl()
:   window(new GLWindow()),
    camera(new Camera()),
    mouseMoveX(0.0f),
    mouseMoveY(0.0f)
{
    for(int i = 0; i < numKeys; i++)
    {
        keys[i] = false;
    }
    for(int i = 0; i < numMouse; i++)
    {
        mouse[i] = false;
    }
}

int GLControl::run()
{
    GLFWwindow *win;
    
    // initialize glfw
    if(!glfwInit())
    {
        return -1;
    }
    
    // initialize glfw window
    win = glfwCreateWindow(640, 480, "Menu", NULL, NULL);
    
    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
        return -1;
    }
    
    glfwMakeContextCurrent(win);
    
    // create a callback for keyboard input
    glfwSetKeyCallback(win, key_callback);
    
    glfwSetMouseButtonCallback(win, mouse_callback);
    
    glfwSetWindowUserPointer(win, this);
    
    //glEnable(GL_DEPTH_TEST);
    
    // game loop
    while(!glfwWindowShouldClose(win)) 
    {
        glfwPollEvents();
        handleEvents(win);
        // create the scene and render
        window->setLookAtMatrix(camera->getWorldToViewMatrix());
        window->render();
        glfwSwapBuffers(win);
        
    }
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}

void GLControl::handleEvents(GLFWwindow *win)
{
    if(keys[0])
    {
        camera->position += (camera->move * sensitivity);
        camera->viewDirection += (camera->move * sensitivity);
    }
    if(keys[1])
    {
        camera->position -= glm::cross(camera->move, camera->up) * sensitivity;
        camera->viewDirection -= glm::cross(camera->move, camera->up) * sensitivity;
    }
    if(keys[2])
    {
        camera->position -= (camera->move * sensitivity);
        camera->viewDirection -= (camera->move * sensitivity);
    }
    if(keys[3])
    {
        camera->position += glm::cross(camera->move, camera->up) * sensitivity;
        camera->viewDirection += glm::cross(camera->move, camera->up) * sensitivity;
    }
    if(keys[4])
    {
        camera->position += (camera->up * sensitivity);
        camera->viewDirection += (camera->up * sensitivity);
    }
    if(keys[5])
    {
        camera->position -= (camera->up * sensitivity);
        camera->viewDirection -= (camera->up * sensitivity);
    }
    
    if(mouse[1])
    {
        glfwGetCursorPos(win, &mouseMoveX, &mouseMoveY);
        
        double moveX = mouseMoveX - mouseStartX;
        double moveY = mouseMoveY - mouseStartY;
        

        
    }
    return;
}

void GLControl::key_callback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
    GLControl *control = reinterpret_cast<GLControl *>(glfwGetWindowUserPointer(win));
    
    if (key == GLFW_KEY_W) 
    {
        if(action == GLFW_PRESS)
        {
            control->keys[0] = true;
        }
        if(action == GLFW_RELEASE)
        {
            control->keys[0] = false;
        }
    }
    if (key == GLFW_KEY_A) 
    {
        if(action == GLFW_PRESS)
        {
            control->keys[1] = true;
        }
        if(action == GLFW_RELEASE)
        {
            control->keys[1] = false;
        }
    }
    if (key == GLFW_KEY_S) 
    {
        if(action == GLFW_PRESS)
        {
            control->keys[2] = true;
        }
        if(action == GLFW_RELEASE)
        {
            control->keys[2] = false;
        }
    }
    if (key == GLFW_KEY_D) 
    {
        if(action == GLFW_PRESS)
        {
            control->keys[3] = true;
        }
        if(action == GLFW_RELEASE)
        {
            control->keys[3] = false;
        }
    }
    if (key == GLFW_KEY_SPACE) 
    {
        if(action == GLFW_PRESS)
        {
            control->keys[4] = true;
        }
        if(action == GLFW_RELEASE)
        {
            control->keys[4] = false;
        }
    }
    if (key == GLFW_KEY_LEFT_SHIFT) 
    {
        if(action == GLFW_PRESS)
        {
            control->keys[5] = true;
        }
        if(action == GLFW_RELEASE)
        {
            control->keys[5] = false;
        }
    }
    return;
}

void GLControl::mouse_callback(GLFWwindow* win, int button, int action, int mouse)
{
    GLControl *control = reinterpret_cast<GLControl *>(glfwGetWindowUserPointer(win));
    
    if(button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if(action == GLFW_PRESS)
        {
            glfwGetCursorPos(win, &control->mouseStartX, &control->mouseStartY);
        }
        if(action == GLFW_RELEASE)
        {
            control->mouseStartX = 0.0;
            control->mouseStartY = 0.0;
        }
    }
    return;
}



