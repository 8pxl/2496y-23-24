#pragma once

#include "main.h"
#include "keejLib/lib.hpp"

#define MAX_LIN 0.647953484803
#define MAX_ANG 0.647953484803

namespace glb {
    //pros
    pros::Imu imu(13);
    pros::ADIDigitalOut wpis1('B');
    pros::ADIDigitalOut wpis2('H');
    pros::ADIDigitalOut spis('A');
    pros::ADIDigitalOut vpis1('D');
    pros::ADIDigitalOut vpis2('F');
    pros::ADIDigitalOut pto('C');
    pros::ADIButton limit(-1);
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    pros::Rotation rot(3);
    lib::scheduler async;
}

//https://www.desmos.com/calculator/zwl4noapxl
//math for robot constants
namespace robot {
    lib::diffy chassMtrs({-12, -17, -8, 16, 14, 5});
    lib::mtrs intake({9});
    lib::mtrs blocker({-10});
    lib::mtrs cata({-1});
    lib::pis scraper({glb::spis}, false);
    lib::pis wings({glb::wpis1, glb::wpis2}, false);
    lib::pis vwings({glb::vpis1, glb::vpis2}, false);
    lib::pis pto({glb::pto}, false);
    lib::controller controller(glb::controller);
    lib::chassis chass (
        chassMtrs, 
        glb::imu, 
        {-1, -1}, {
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


