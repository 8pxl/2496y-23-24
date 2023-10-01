#pragma once

#include "main.h"
#include "keejLib/lib.hpp"

namespace glb {
    //pros
    pros::Imu imu(9);
    pros::ADIDigitalOut ipis('E');
    pros::ADIDigitalOut wpis1('B');
    pros::ADIDigitalOut wpis2('D');
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
}

namespace robot {
    lib::diffy chassMtrs({-14, -6, -3, 17, 5, 10});
    lib::mtrs intake({12});
    lib::mtrs cata({20});
    lib::pis tsukasa({glb::ipis}, false);
    lib::pis wings({glb::wpis1, glb::wpis2}, false);
    lib::controller controller(glb::controller);
    lib::chassis chass (
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


