#include "main.h"
#include "robot.hpp"
#include "controls.hpp"
#include "autons.hpp"
#include "keejLib/lib.hpp"

void (*auton)();

void initialize() {
	glb::imu.reset();
	auton = autons.autonsList[robot::controller.select(autons.names)];	
}

void autonomous() {auton();}

void opcontrol() {
	robot::controller.setCurves(0, 0);
	while (true) {
		driver();
		if (glb::controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) auton();
	}
}