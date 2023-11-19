#include "main.h"
#include "robot.hpp"
#include "cata.hpp"
// #include "util.hpp"

using namespace lib;

void driver() {
        std::vector<bool> state = robot::controller.getAll(ALLBUTTONS);
        robot::chassMtrs.spinDiffy(robot::controller.drive(1, lib::controller::arcade));

        if(state[L2]) {
            if (state[L1]) robot::wings.setState(true);
            if (state[R1]) robot::blocker.spin(127);
            else if (state[R2]) robot::blocker.spin(-127);
            else robot::blocker.stop('h');
        }
        
        else {
            // if (state[NL1]) cata::fire();
            if (state[L1]) glb::spis.set_value(true);
            else glb::spis.set_value(false);
            if (state[NB]) cata::halfway();
            if (state[NA]) cata::toggle();

            if (state[R1]) robot::intake.spin(127);
            else if (state[R2]) robot::intake.spin(-127);
            else robot::intake.stop('c');

            if (state[X]) robot::blocker.stop('c');

            if (state[UP]) cata::halfway();

            if (state[NLEFT]) scraper.toggle();
            if (state[UP]) robot::cata.spin(-127); 
            else if (cata::state == cata::cataState::idle) {
                robot::cata.spin(0);
            }
        }
        
        if(!state[L1]) robot::wings.setState(false);

        cata::cataControl();
        pros::delay(20);
}