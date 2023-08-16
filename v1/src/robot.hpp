#pragma once

#include "main.h"
#include "keejLib/lib.hpp"

namespace glb
{
    //pros
    pros::Imu imu(9);
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
}

namespace robot
{
    lib::diffy chassMtrs({1, 2, 3, 4, 5, 6});
    lib::mtrs intake({7});
    lib::mtrs cata({8});
    lib::controller controller(glb::controller);
    lib::chassis chass
    (
        chassMtrs, 
        glb::imu, 
        {6, 8}, 
        {
            .horizTrack = 0, 
            .vertTrack = 0,
            .trackDia = 0,
            .maxSpeed = 0,
            .fwdAccel = 0,
            .fwdDecel =  0,
            .revAccel =  0,
            .revDecel = 0,
            .velToVolt = 0
        }
    );
}


