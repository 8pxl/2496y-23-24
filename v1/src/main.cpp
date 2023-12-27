#include "main.h"
#include "robot.hpp"
#include "controls.hpp"
#include "autons.hpp"
#include "keejLib/lib.hpp"

void (*auton)();

void initialize() {
	glb::imu.reset();
	// glb::async.init();
	// init();
	cata::init();
	auton = autons.autonsList[robot::controller.select(autons.names)];	
}

void autonomous() {auton();}

void opcontrol() {
	robot::controller.setCurves(0, 0);
	while (true) {
		driver();
		if (glb::controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) auton();
		if(auton == tank) robot::chassMtrs.spinDiffy(robot::controller.drive(1, lib::controller::tank));
		else robot::chassMtrs.spinDiffy(robot::controller.drive(1, lib::controller::arcade));
	}
}