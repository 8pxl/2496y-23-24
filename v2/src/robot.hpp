#pragma once

#include "keejLib/lib.hpp"
#include "main.h"

#define MAX_LIN 0.647953484803
#define MAX_ANG 0.647953484803

namespace glb {
// pros
pros::Imu imu(6);
pros::ADIDigitalOut rhoriz('G');
pros::ADIDigitalOut lhoriz('H');
pros::ADIDigitalOut spis('A');
pros::ADIDigitalOut lvert('D');
pros::ADIDigitalOut rvert('C');
pros::ADIDigitalOut pto('E');
pros::ADIDigitalOut hang('F');
pros::ADIButton limit(-1);
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Rotation rot(3);
lib::scheduler async;
} // namespace glb

// https://www.desmos.com/calculator/zwl4noapxl
// math for robot constants
namespace robot {
    lib::diffy chassMtrs({-20, -18, -17, 11, 13, 14});
    lib::mtrs intake({-7});
    lib::mtrs tsukasa({-1});
    lib::mtrs cata({-9});
    lib::pis wings({glb::lhoriz, glb::rhoriz}, false);
    lib::pis vwings({glb::lvert, glb::rvert}, false);
    lib::pis pto({glb::pto}, false);
    lib::pis hang({glb::hang}, false);
    lib::controller controller(glb::controller);
    lib::chassis chass(chassMtrs, glb::imu, {-1, -1},
        {
            .horizTrack = 5.53532 + 5.25712,
            .vertTrack = (5.53532 + 5.25712) / 2,
            .trackDia = 0,
        },
        {
            .maxSpeed = MAX_LIN,
            .fwdAccel = MAX_LIN / 26,
            .fwdDecel = MAX_LIN / 18,
            .revAccel = MAX_LIN / 18,
            .revDecel = MAX_LIN / 32,
            .velToVolt = 196.001723856},
        {.maxSpeed = MAX_ANG,
            .fwdAccel = MAX_ANG / 40,
            .fwdDecel = MAX_ANG / 40,
            .revAccel = MAX_ANG / 20,
            .revDecel = MAX_ANG / 20,
            .velToVolt = 127 / MAX_ANG});
} // namespace robot
