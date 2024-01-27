#include "main.h"
#include "robot.hpp"
#include "cata.hpp"

using namespace lib;

bool bRunning = true;
char bHold = 'b';
bool r2 = false;
void driver() {
    std::vector<bool> state = robot::controller.getAll(ALLBUTTONS);
    // robot::chassMtrs.spinDiffy(robot::controller.drive(1, lib::controller::arcade));

    if(state[L2]) {
        bRunning = true;
        if (state[R2]) {
            robot::blocker.spin(-127);
        }
        else if (state[R1]) robot::blocker.spin(127);
        else {
            bRunning = false;
            bHold = 'h';
        }
        if(state[L1]) {
            robot::vwings.setState(true);
            robot::intake.spin(-127);
        }
        else {
            robot::intake.stop('c');
        }
    }
    
    else {
        // if (state[L1]) glb::spis.set_value(true);
        // else glb::spis.set_value(false);
        if (state[L1]) robot::wings.setState(true);
        if (state[NB]) cata::cut();
        if (state[NA]) cata::toggle();
        if (state[NUP]) cata::fire();

        if (state[R1]) robot::intake.spin(127);
        else if (state[R2]) robot::intake.spin(-127);
        else if(!state[L1]) robot::intake.stop('c');

        if (state[X]) {
            bHold = 'c';
        }

        if (state[NLEFT]) scraper.toggle();
        // if (state[UP]) robot::cata.spin(-127); 
        else if (cata::state == cata::cataState::idle) robot::cata.spin(0);

        if(state[NY]) robot::pto.toggle();
        if(robot::pto.getState()) bHold = 'c';
        if(!state[R2] && !state[R1]) bRunning = false;
    }

    if (state[R2] != r2 && r2) bHold = 'c';
    r2 = state[R2];
    if (!bRunning) {
        robot::blocker.stop(bHold);
    }
    if (cata::state == cata::toggeled) {
        robot::wings.setState(true);
        robot::chassMtrs.setBrake('b');
    }
    else if(!state[L1]) {
        robot::chassMtrs.setBrake('c');
        robot::wings.setState(false);
    }
    if(!state[L1]) robot::vwings.setState(false);

    if(state[NRIGHT]) glb::imu.reset();

    // cata::cataControl();
    pros::delay(20);
}