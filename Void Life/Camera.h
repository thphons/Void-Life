//
//  Camera.h
//  Void Life
//
//  Created by Cal McLelland on 17-02-14.
//  Copyright (c) 2017 __MyCompanyName__. All rights reserved.
//

#ifndef Void_Life_Camera_h
#define Void_Life_Camera_h

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
    
    Camera();
    ~Camera();
    
    glm::mat4 getWorldToViewMatrix() const;
    
    glm::vec3 position;
    glm::vec3 viewDirection;
    glm::vec3 up;
    glm::vec3 move;
};



#endif
