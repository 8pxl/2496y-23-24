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

        if(state[NL1]) cata::fire();
        if(state[NB]) cata::halfway();
        if(state[NA]) cata::toggle();

        if(state[NUP]) robot::tsukasa.toggle();

        if(state[NL2]) robot::wings.toggle();

        cata::cataControl();
        pros::delay(20);
}


// bool toggle = false;
// void driver() {
//         std::vector<bool> state = robot::controller.getAll(ALLBUTTONS);
//         robot::chassMtrs.spinDiffy(robot::controller.drive(1, lib::controller::arcade));
        
//         if(state[R1]) robot::intake.spin(127);
//         else if(state[R2]) robot::intake.spin(-127);
//         else robot::intake.stop('c');

//         if(state[L1]) robot::cata.spin(127);
//         else if(!toggle) robot::cata.stop('c');

//         if(state[NUP]) robot::tsukasa.toggle();

//         if(toggle) robot::cata.spin(127);
//         if(state[NA]) toggle = !toggle;

//         if(state[NL2]) robot::wings.toggle();
//         pros::delay(20);
// }