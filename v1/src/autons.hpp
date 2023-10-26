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
    .p = 4.9, 
    .i = 0.4, 
    .d = 26, 
    .tolerance = 0.01, 
    .integralThreshold = 1.1, 
    .maxIntegral = 100
}; 

pidConstants _5 {
    .p = 4.9, 
    .i = 0.4, 
    .d = 26, 
    .tolerance = 0.01, 
    .integralThreshold = 1.1, 
    .maxIntegral = 100
}; 

pidConstants _lin {
    .p = 10,
    .i = 0,
    .d = 0,
    .tolerance = 0,
    .integralThreshold = 0,
    .maxIntegral = 0
};

pidConstants _arc {
    .p = 1.7,
    .i = 0.2,
    .d = 2,
    .tolerance = 0,
    .integralThreshold = 3,
    .maxIntegral = 100
};

void test1() {
    // chass.pidDrive(1000, 1500, linear);
    // chass.profiledDrive(25);    
    // chass.profiledTurn(25,1);
    chass.arcTurn(90, 12, 1400, 1, _arc);
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
    robot::blocker.spin(40);
    scraper.toggle();
    pros::delay(500);
    chass.profiledDrive(5, 130);
    chass.profiledDrive(-17, 130);
    robot::blocker.stop('c');
    chass.pidTurn(90, 900, _45);
    robot::blocker.spin(-45);
    robot::scraper.toggle();
    pros::delay(475);
    robot::blocker.stop('b');
    chass.profiledDrive(-24, 130);
    chass.pidTurn(45, 900, _45);
    chass.profiledDrive(26,100);
    robot::intake.spin(-127);
    chass.pidTurn(0, 1200, _45);
    chass.profiledDrive(23.4,100);
    robot::blocker.spin(-30);
    pros::delay(700);
    robot::blocker.stop('c');
}

void skills() {
    chass.profiledDrive(15, 130);
    chass.pidTurn(neg(15), 800, _15);
    chass.profiledDrive(3);
    // bool prev = false;
    // int count = 0;
    // while (count < 5) {
    //     if (glb::limit.get_value() != prev && !glb::limit.get_value()) {
    //         count ++;
    //     }
    //     prev = glb::limit.get_value();
    //     robot::cata.spin(-127);
    // }
    // robot::cata.stop('c');
    chass.arcTurn(60, 7, 600, 1, _arc);
    chass.arcTurn(0, 10, 860, -1, _arc);
    robot::intake.spin(-127);
    // chass.pidTurn(30, 900, _45);
    // chass.profiledDrive(-34, 130);
    // chass.pidTurn(0, 900, _15);
    chass.profiledDrive(-46, 30);
    chass.arcTurn(neg(90), 10, 1000, -1, _arc);
    chass.profiledDrive(-20, 130);
    chass.pidTurn(neg(80), 500, _45);
    chass.profiledDrive(20, 130);
    chass.pidTurn(neg(60), 500, _45);
    chass.profiledDrive(-30, 130);
    chass.profiledDrive(10, 130);
    chass.pidTurn(8, 700, _90);
    chass.profiledDrive(28, 130);
    chass.arcTurn(90, 6, 1000, -1, _arc);
    chass.profiledDrive(10, 130);
    chass.pidTurn(neg(20), 700, _45);
    robot::wings.toggle();
    chass.profiledDrive(-28, 130);
    chass.pidTurn(neg(20), 700, _45);
    robot::wings.toggle();
    chass.profiledDrive(20, 130);
    robot::wings.toggle();
    chass.profiledDrive(-28, 130);
    chass.pidTurn(10, 700, _15);
    robot::wings.toggle();

    chass.profiledDrive(27, 130);
    // chass.pidTurn(90, 900, _90);
    // chass.profiledDrive(20, 130);
    chass.pidTurn(0, 700, _45);
    robot::wings.toggle();
    chass.profiledDrive(-30, 130);
    chass.pidTurn(0, 700, _45);
    robot::wings.toggle();
    chass.profiledDrive(20, 130);
    chass.pidTurn(90, 900, _90);
    chass.profiledDrive(25, 130);
    chass.pidTurn(20, 900, _90);
    robot::wings.toggle();
    chass.profiledDrive(-30, 130);
    robot::wings.toggle();
    chass.arcTurn(95, 5, 1300, -1, _arc);
    chass.profiledDrive(30, 0);
    chass.profiledDrive(7, 130);
    chass.pidTurn(180, 200, _90);
    chass.pidTurn(neg(90), 200, _90);
    chass.pidTurn(0, 800, _90);
    chass.arcTurn(90, 10, 1000, 1, _arc);
    chass.profiledDrive(-20, 130);
    chass.pidTurn(80, 500, _45);
    chass.profiledDrive(20, 130);
    chass.pidTurn(60, 500, _45);
    chass.profiledDrive(-30, 130);


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
    {test1, test2, six_far, calcTrack, safe_near, skills}, 
    {"test", "test2", "six_far", "track", "safe_near", "skills"}
};