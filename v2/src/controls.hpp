#include "main.h"
#include "robot.hpp"
#include "autons/constants.hpp"

using namespace lib;
enum states {
    
}
void driver() {
    std::vector<bool> state = robot::controller.getAll(ALLBUTTONS);


    pros::delay(20);
}