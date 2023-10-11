#include "main.h"
#include "robot.hpp"
#include "cata.hpp"
// #include "util.hpp"

using namespace lib;

void driver() {
    std::vector<bool> state = robot::controller.getAll(ALLBUTTONS);
    robot::chassMtrs.spinDiffy(robot::controller.drive(1, lib::controller::arcade));

    if(state[R1]) robot::intake.spin(127);
    else if(state[R2]) robot::intake.spin(-127);
    else robot::intake.stop('c');

    if(state[L2]) {
        if(state[NL1]) {
            cataMachine.setHalf(false);
            cataMachine.next();
        }
    }
    else {
        if(state[NL1]) cataMachine.next(); 
    }

    if(state[NA]) cataMachine.toggle();

    if(state[NUP]) robot::tsukasa.toggle();


    cataMachine.run();
    pros::delay(20);
}