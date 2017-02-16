//
//  main.cpp
//  Void Life
//
//  Created by Cal McLelland on 17-02-14.
//  Copyright (c) 2017 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "GLControl.h"

int main(int argc, char ** argv)
{
    GLControl *control= new GLControl();
    
    return control->run();
}

