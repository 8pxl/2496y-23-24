#include "main.h"
#include "robot.hpp"
#include "controls.hpp"
#include "autons.hpp"
#include "keejLib/lib.hpp"

// - globals
void (*auton)();
bool color;

void initialize() {
	glb::imu.reset();
	auton = autons.autonsList[robot::controller.select(autons.names)];	
	// color = robot::controller.select({"blue", "red"}); //0 = blue, 1 = red
}

void autonomous() {auton();}

void opcontrol() {
	robot::controller.setCurves(0, 0);
	// robot::chassMtrs.stop('c');

	while (true) 
	{
		driver();
		pros::delay(20);
		if (glb::controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			auton();
		}
	}
}