#pragma once

#include "main.h"
#include "keejLib/lib.hpp"

<<<<<<< HEAD
#define MAX_LIN 0.647953484803
#define MAX_ANG 0.647953484803
=======
#define MAX_LIN 0.628318530718
#define MAX_ANG 0.628318530718
>>>>>>> some-testing

namespace glb {
    //pros
    pros::Imu imu(17);
    pros::ADIDigitalOut wpis1('B');
    pros::ADIDigitalOut wpis2('H');
    pros::ADIDigitalOut spis('C');
    pros::ADIButton limit('G');
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    pros::Rotation rot(19);
}

// https://www.desmos.com/calculator/zwl4noapxl
//math for robot constants
//units: inches and 10 ms,
//ex: vel -> inches / 10 ms
namespace robot {
<<<<<<< HEAD
    lib::diffy chassMtrs({-2, -3, -1, 9, 6, 10});
    lib::mtrs intake({5});
=======
    lib::diffy chassMtrs({21, -19, -20, -14, 13, 11});
    lib::mtrs intake({-5});
>>>>>>> some-testing
    lib::mtrs blocker({-20});
    lib::mtrs cata({-8});
    lib::pis scraper({glb::spis}, false);
    lib::pis wings({glb::wpis1, glb::wpis2}, false);
    lib::controller controller(glb::controller);
    lib::chassis chass (
        chassMtrs, 
        glb::imu, 
        {6, 8}, {
            .horizTrack = 4.7261 + 4.7261, 
            .vertTrack = (4.7261 + 4.7261)/2,
            .trackDia = 0,
        }, {
            .maxSpeed = MAX_LIN,
            .fwdAccel = MAX_LIN / 20,
            .fwdDecel = MAX_LIN / 20,
            .revAccel = MAX_LIN / 18,
            .revDecel = MAX_LIN / 32,
            .rpmToVel = 0.0010471975512,
            .kv = 202.126777727,
            .kp = 630,
            .ka = 100,
        }, {
            .maxSpeed = MAX_ANG,
            .fwdAccel = MAX_ANG / 40,
            .fwdDecel =  MAX_ANG / 50,  
            .revAccel =  MAX_ANG / 40,
            .revDecel = MAX_ANG / 40,
            .rpmToVel = 0.0010471975512,
            .kv = 127 / MAX_ANG,
            .kp = 0.35,
            .ka = 0.5,
        }
    );
}


