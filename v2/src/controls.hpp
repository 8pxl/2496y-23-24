#include "main.h"
#include "robot.hpp"
#include "autons/constants.hpp"

// bool toggle = false;
using namespace lib;
// // enum driveStates {
// //     idle,
// //     descore,
// //     matchload,
// //     push
// // }

// void normal() {

// }

// void descore() {

// }

// void matchload() {

// }

// void push() {

bool closeWings = true;
bool toggeled = false;
void driver() {
    closeWings = true;
    std::vector<bool> state = robot::controller.getAll(ALLBUTTONS);
    if (state[L2]) {
        if (state[L1])  robot::vwings.setState(true);
        if (state[R2])  {
            robot::wings.setState(true);
            closeWings = false;
        }
        if (state[R1])  {
            robot::cata.spin(127);
            toggeled = false;
        }
        else if (!toggeled) robot::cata.spin(0);
    }
    else {
        if (state[R1]) robot::intake.spin(127);

        if (state[L1]) {
            robot::wings.setState(true);
            closeWings = false;
        }
        else {
            robot::vwings.setState(false);
        }

        if(state[NY]) robot::pto.toggle();
        if(state[NA]) robot::hang.toggle();
    }
    if (closeWings) {
        robot::wings.setState(false);
    }

    if (state[R2]) {
        robot::intake.spin(-127);
    }
    else if (!state[R1]) {
        robot::intake.spin(0);
    }

    if (state[NLEFT]) {
        robot::intake.spin(-127);
        chass.profiledDrive(7.2, 0,0,0);
        robot::chassMtrs.stop('b');
        pros::delay(200);
        chass.pidTurn(neg(153), 800, _90);
        chass.profiledDrive(-3.7, 0);
        robot::cata.spin(127);
        toggeled = true;
    }
    pros::delay(20);
}