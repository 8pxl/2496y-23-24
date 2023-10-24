#pragma once
#include "robot.hpp"

#define neg(a) 360-a

using namespace robot;
using namespace lib;

pidConstants _180 {
    .p = 5.9, 
    .i = 0.6, 
    .d = 70, 
    .tolerance = 0.05, 
    .integralThreshold = 1.1, 
    .maxIntegral = 20
}; 

pidConstants _135 {
    .p = 6.3, 
    .i = 0.43, 
    .d = 59, 
    .tolerance = 0.01, 
    .integralThreshold = 1, 
    .maxIntegral = 100
}; 


pidConstants _90 {
    .p = 6.3, 
    .i = 0.43, 
    .d = 59, 
    .tolerance = 0.01, 
    .integralThreshold = 1, 
    .maxIntegral = 100
}; 

pidConstants _45 {
    .p = 4.9, 
    .i = 0.4, 
    .d = 26, 
    .tolerance = 0.01, 
    .integralThreshold = 1.1, 
    .maxIntegral = 100
}; 

pidConstants _30 {
    .p = 5.9, 
    .i = 0.6, 
    .d = 70, 
    .tolerance = 0.05, 
    .integralThreshold = 1.1, 
    .maxIntegral = 20
}; 

pidConstants _15 {
    .p = 5.9, 
    .i = 0.6, 
    .d = 70, 
    .tolerance = 0.05, 
    .integralThreshold = 1.1, 
    .maxIntegral = 20
}; 

pidConstants _5 {
    .p = 5.9, 
    .i = 0.6, 
    .d = 70, 
    .tolerance = 0.05, 
    .integralThreshold = 1.1, 
    .maxIntegral = 20
}; 

pidConstants _lin {
    .p = 10,
    .i = 0,
    .d = 0,
    .tolerance = 0,
    .integralThreshold = 0,
    .maxIntegral = 0
};

// pidConstants _arc {
//     .p = 10,
//     .i = 0,
//     .d = 0,
//     .tolerance = 0,
//     .integralThreshold = 0,
//     .maxIntegral = 0
// };

void test1() {
    // chass.pidDrive(1000, 1500, linear);
    // chass.profiledDrive(25);    
    chass.profiledTurn(25,1);
}

void test2() {
    // chass.arcTurn()
    // chass.pidTurn(90, 4000, _90);
    // chass.pidTurn(45, 4000, _45);
}

void six_far() {
    glb::wpis1.set_value(true);
    pros::delay(300);
    glb::wpis1.set_value(false);
    robot::intake.spin(127);
    chass.profiledDrive(22, 200);
    chass.profiledDrive(-30, 130);
    robot::intake.spin(5);
    chass.pidTurn(135, 700, _135);
    robot::intake.spin(-127);
    chass.profiledDrive(13, 100);
    chass.pidTurn(45, 700, _90);
    robot::scraper.toggle();
    chass.profiledDrive(-8, 100);
    chass.pidTurn(neg(45), 920, _90);
    robot::scraper.toggle();
    chass.profiledDrive(-19, 100);
    chass.pidTurn(neg(90), 700, _45);
    chass.profiledDrive(-20, 40);
    chass.profiledDrive(5, 100);
    chass.pidTurn(0, 690, _90);
    chass.profiledDrive(21, 100);
    chass.pidTurn(45, 600, _45);
    robot::intake.spin(127);
    chass.profiledDrive(31, 200);
    glb::wpis1.set_value(true);
    robot:intake.spin(20);
    chass.pidTurn(173, 800, _135);
    robot::intake.spin(-127);
    glb::wpis1.set_value(false);
    chass.profiledDrive(20, 100);
    chass.profiledDrive(10, 100);
    chass.pidTurn(127, 700, _45);
    chass.profiledDrive(-33, 0);
    robot::scraper.toggle();
}

void safe_near() {
    chass.profiledDrive(-20, 130);
    chass.pidTurn(135, 900, _90);
    chass.profiledDrive(20, 130);
    chass.pidTurn(neg(45), 900, _45);
    chass.profiledDrive(-10,100);
    robot::scraper.toggle();
}

void calcTrack() {
	double dl = 0;
	double dr = 0;
	double rotation;
	double delta;
	for (int i = 0; i < 10; i++)
	{
		rotation = glb::imu.get_heading();
		robot::chassMtrs.reset();
		chass.pidTurn(fmod(rotation + 90, 360), 1500, _90);
        pros::delay(600);
		delta = lib::minError(glb::imu.get_heading(), rotation) * PI / 180;
        auto d = robot::chassMtrs.getDiffy();
		dl += (d[0] * 0.0179987079112) / (delta);
		dr += (d[1] * 0.0179987079112) / (delta);

		printf("%f,%f\n", dl, dr);
		// glb::controller.print(0,0,"%f,%f", dl, dr);
	}
    std::cout << dl/10 << ' ' << dr / 10 << std::endl;
}

//creates list of auton function pointers and names - useful for auton selector
lib::atns autons = {
    {test1, test2, six_far, calcTrack, safe_near}, 
    {"test", "test2", "six_far", "track", "safe_near"}
};