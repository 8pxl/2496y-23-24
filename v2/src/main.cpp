#include "main.h"
#include "pros/misc.h"
#include "robot.hpp"
#include "controls.hpp"
#include "cata.hpp"
#include "autons/autons.hpp"
#include "keejLib/lib.hpp"

void (*auton)();

void initialize() {
	glb::imu.reset();
	auton = autons.autonsList[robot::controller.select(autons.names)];
}

void autonomous() {auton(); robot::chassMtrs.stop('c');}

void opcontrol() {
	robot::controller.setCurves(0, 0);
	robot::chassMtrs.stop('c');
	while (true) {
		driver();
		if (glb::controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) auton();
		if (glb::controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
		    glb::imu.reset();
		    auton = autons.autonsList[robot::controller.select(autons.names)];
		}
		if(auton == tank) robot::chassMtrs.spinDiffy(robot::controller.drive(1, lib::controller::tank));
		else robot::chassMtrs.spinDiffy(robot::controller.drive(1, lib::controller::arcade));
	}
}