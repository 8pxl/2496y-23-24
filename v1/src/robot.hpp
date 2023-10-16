#pragma once

#include "main.h"
#include "keejLib/lib.hpp"

namespace glb {
    //pros
    pros::Imu imu(9);
    pros::ADIDigitalOut wpis1('G');
    pros::ADIDigitalOut wpis2('H');
    pros::ADIDigitalOut spis('F');
    pros::ADIButton limit('C');
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    pros::Rotation rot(15);
}

namespace robot {
    lib::diffy chassMtrs({-2, -3, -1, 9, 6, 10});
    lib::mtrs intake({-5});
    lib::mtrs blocker({-20});
    lib::mtrs cata({-8});
    lib::pis scraper({glb::spis}, false);
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


