//
//  Camera.cpp
//  Void Life
//
//  Created by Cal McLelland on 17-02-14.
//  Copyright (c) 2017 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Camera.h"

Camera::Camera()
:       position(0.0f, 0.0f, 0.0f),
        viewDirection(0.0f, 0.0f, -1.0f),
        up(0.0f, 1.0f, 0.0f),
        move(0.0f, 0.0f, -1.0f)
      
{

}

Camera::~Camera()
{
    
}

glm::mat4 Camera::getWorldToViewMatrix() const
{
    glm::mat4 wtvM;
    
    wtvM[0][0] = position[0];
    wtvM[0][1] = position[1];
    wtvM[0][2] = position[2];
    
    wtvM[1][0] = viewDirection[0];
    wtvM[1][1] = viewDirection[1];
    wtvM[1][2] = viewDirection[2];
    
    wtvM[2][0] = up[0];
    wtvM[2][1] = up[1];
    wtvM[2][2] = up[2];
    
    wtvM[3][0] = move[0];
    wtvM[3][1] = move[1];
    wtvM[3][2] = move[2];
    
    
    return wtvM;
    //return glm::lookAt(position, position + viewDirection, up);
}
