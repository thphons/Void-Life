//
//  GLControl.h
//  Void Life
//
//  Created by Cal McLelland on 17-02-14.
//  Copyright (c) 2017 __MyCompanyName__. All rights reserved.
//

#ifndef Void_Life_GLControl_h
#define Void_Life_GLControl_h

#include <GLFW/glfw3.h>

#include "GLWindow.h"
#include "Camera.h"

#define numKeys         6
#define numMouse        2

#define sensitivity     0.01f

/*

 Keys
    0   w
    1   a
    2   s
    3   d
    4   space
    5   left shift
 
 Mouse
    0   left
    1   right
 
 
*/

class GLControl
{
private:
    GLWindow *window;
    Camera *camera;
    bool keys[numKeys];
    bool mouse[numMouse];
    double mouseStartX;
    double mouseStartY;
    double mouseMoveX;
    double mouseMoveY;
    
public:
    GLControl();
    int             run();
    void            handleEvents(GLFWwindow*);
    static void     key_callback(GLFWwindow*, int, int, int, int);
    static void     mouse_callback(GLFWwindow*, int, int, int);
};



#endif
