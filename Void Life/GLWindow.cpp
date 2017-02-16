//
//  GLWindow.cpp
//  Void Life
//
//  Created by Cal McLelland on 17-02-14.
//  Copyright (c) 2017 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "GLWindow.h"

#define drawLookAt true

GLWindow::GLWindow()
{
}

void GLWindow::render(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    
	glPushMatrix();
    
    //glEnable(GL_DEPTH_TEST);
    
    glLoadIdentity();
    lookAt();
    
    /*-----------------------------------//
     
     Render Code Start
     
    //-----------------------------------*/
    
    glColor3f(1.0f, 1.0f, 1.0f);
    
    // Draw Body 
    glTranslatef(0.0f ,0.75f, 0.0f);
    glutSolidSphere(0.75f,20,20);
    
    
    // Draw Head
    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.25f,20,20);
    
    // Draw Eyes
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    glTranslatef(0.05f, 0.10f, 0.18f);
    glutSolidSphere(0.05f,10,10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f,10,10);
    glPopMatrix();
    
    // Draw Nose
    glColor3f(1.0f, 0.5f , 0.5f);
    glRotatef(0.0f,1.0f, 0.0f, 0.0f);
    glutSolidCone(0.08f,0.5f,10,2);

    
    /*-----------------------------------//
     
     Render Code End
     
    //-----------------------------------*/
    
    if(drawLookAt)
    {
        
        // draw x
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_STRIP);
        glVertex3f(0.0f, 0.0f, 0.0f);  // V0
        glVertex3f(1.0f, 0.0f, 0.0f);  // V1
        glEnd();
        
        // draw z
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_LINE_STRIP);
        glVertex3f(0.0f, 0.0f, 0.0f);  // V0
        glVertex3f(0.0f, 1.0f, 0.0f);  // V1
        glEnd();
        
        // draw y
        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex3f(0.0f, 0.0f, 0.0f);  // V0
        glVertex3f(0.0f, 0.0f, 1.0f);  // V1
        glEnd();
        
    }
    
	glPopMatrix();
    
    glutSwapBuffers();
    
	//glFlush();
    return;
    
}

void GLWindow::lookAt()
{
    gluLookAt(worldToViewMatrix[0][0], worldToViewMatrix[0][1], worldToViewMatrix[0][2], worldToViewMatrix[1][0], worldToViewMatrix[1][1], worldToViewMatrix[1][2], worldToViewMatrix[2][0], worldToViewMatrix[2][1], worldToViewMatrix[2][2]);
    if(checkView)
    {
        printf("eye: %f, %f, %f\nlook: %f, %f, %f\nup: %f, %f, %f\n\n",worldToViewMatrix[0][0], worldToViewMatrix[0][1], worldToViewMatrix[0][2], worldToViewMatrix[1][0], worldToViewMatrix[1][1], worldToViewMatrix[1][2], worldToViewMatrix[2][0], worldToViewMatrix[2][1], worldToViewMatrix[2][2]);
    }
    return;
}

void GLWindow::setLookAtMatrix(glm::mat4 inMatrix)
{
    worldToViewMatrix = inMatrix;
    return;
}