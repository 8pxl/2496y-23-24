#pragma once

#include "main.h"
#include "keejLib/lib.hpp"

#define MAX_LIN 0.647953484803
#define MAX_ANG 0.796332147963

namespace glb {
    //pros
    pros::Imu imu(13);
    pros::ADIDigitalOut wpis1('B');
    pros::ADIDigitalOut wpis2('H');
    pros::ADIDigitalOut spis('C');
    pros::ADIButton limit('G');
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    pros::Rotation rot(19);
}

//https://www.desmos.com/calculator/zwl4noapxl
//math for robot constants
//units: inches and 10 ms,
//ex: vel -> inches / 10 ms
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
        {6, 8}, {
            .horizTrack = 5.53532 + 5.25712, 
            .vertTrack = (5.53532 + 5.25712)/2,
            .trackDia = 0,
        }, {
            .maxSpeed = MAX_LIN,
            .fwdAccel = MAX_LIN / 26,
            .fwdDecel = MAX_LIN / 18,
            .revAccel = MAX_LIN / 18,
            .revDecel = MAX_LIN / 32,
            .velToVolt = 196.001723856
        }, {
            .maxSpeed = MAX_ANG,
            .fwdAccel = MAX_ANG / 40,
            .fwdDecel =  MAX_ANG / 40,
            .revAccel =  MAX_ANG / 20,
            .revDecel = MAX_ANG / 20,
            .velToVolt = 127 / MAX_ANG
        }
    );
}


