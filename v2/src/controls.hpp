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

// }
void driver() {
    std::vector<bool> state = robot::controller.getAll(ALLBUTTONS);
    if (state[L2]) {
        if (state[L1])  robot::vwings.setState(true);
        if (state[NR2])  robot::hang.toggle();
        if (state[R1])  robot::cata.spin(127);
        else robot::cata.spin(0);
    }
    else {
        if (state[R1]) robot::intake.spin(127);
        else if (state[R2]) robot::intake.spin(-127);
        else robot::intake.spin(0);

        if (state[L1]) robot::wings.setState(true);
        else {
            robot::wings.setState(false);
            robot::vwings.setState(false);
        }

        if(state[NY]) robot::pto.toggle();
    }
    pros::delay(20);
}