//
//  GLWindow.h
//  Void Life
//
//  Created by Cal McLelland on 17-02-14.
//  Copyright (c) 2017 __MyCompanyName__. All rights reserved.
//

#ifndef Void_Life_GLWindow_h
#define Void_Life_GLWindow_h

#define checkView true

#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#include <glm/glm.hpp>

class GLWindow
{
private:
    glm::mat4 worldToViewMatrix;
public:
    GLWindow();
    void    render();
    void    lookAt();
    void    setLookAtMatrix(glm::mat4);
};

#endif
