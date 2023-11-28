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
    // chass.arcTurn(90, 12, 1400, 1, _arc, 20);
    // chass.profiledDrive(25, 0, 0, 0);    
    chass.profiledTurn(90,1);
    // chass.arcTurn(90, 12, 1400, 1, _arc);
    // chass.eulerTurn(90, 0.005, 1200, 1, _arc);
}

void test2() {
    // chass.arcTurn()
    // chass.pidTurn(90, 4000, _90);
    // chass.pidTurn(45, 4000, _45);
}

void rush_far() {
    robot::scraper.toggle();
    robot::blocker.spin(40);
    glb::wpis1.set_value(true);
    pros::delay(300);
    glb::wpis1.set_value(false);
    robot::intake.spin(127);
    robot::scraper.toggle();
    chass.profiledDrive(48, 200);
    robot::intake.spin(40);
    glb::wpis1.set_value(true);
    chass.arcTurn(180, 5, 1000, -1, _arc);
    glb::wpis1.set_value(false);
    chass.profiledDrive(10, 100);
    robot::intake.spin(-127);
    chass.profiledDrive(15, 100);
    chass.arcTurn(90, 8,1200, -1, _arc);
    robot::intake.spin(127);
    chass.profiledDrive(-10, 100);
    chass.pidTurn(0, 800, _90);
    chass.profiledDrive(18, 100);
    chass.pidTurn(180, 800, _90);
    chass.profiledDrive(24, 100);
    robot::intake.spin(-127);
    pros::delay(300);
    chass.arcTurn(0, 7, 1200, -1, _arc);
    robot::intake.spin(127);
    chass.profiledDrive(14, 420);
    chass.profiledDrive(-29, 130);
    chass.arcTurn(neg(90), 10, 800, -1, _arc);
    chass.profiledDrive(-20, 100);

}
void elims_far() {
    robot::scraper.toggle();
    robot::blocker.spin(40);
    glb::wpis1.set_value(true);
    pros::delay(300);
    robot::blocker.spin(-30);
    glb::wpis1.set_value(false);
    robot::intake.spin(127);
    robot::scraper.toggle();
    chass.profiledDrive(22, 200);
    robot::blocker.spin(0);
    robot::blocker.spin(0);
    robot::intake.spin(40);
    chass.profiledDrive(-29, 130);
    chass.pidTurn(135, 700, _135);
    robot::intake.spin(-127);
    chass.profiledDrive(15, 100);
    chass.pidTurn(45, 700, _90);
    robot::scraper.toggle();
    chass.profiledDrive(-8, 100);
    chass.pidTurn(neg(45), 920, _90);
    robot::scraper.toggle();
    chass.profiledDrive(-18, 100);
    chass.pidTurn(neg(90), 600, _45);
    glb::wpis1.set_value(true);
    chass.profiledDrive(-20, 20);
    glb::wpis1.set_value(false);
    chass.profiledDrive(7, 70);
    chass.pidTurn(0, 690, _90);
    chass.profiledDrive(20.6, 100);
    chass.pidTurn(44, 600, _45);
    robot::intake.spin(127);
    chass.profiledDrive(35, 330);
    glb::wpis1.set_value(true);
    robot:intake.spin(80);
    chass.pidTurn(170, 760, _135);
    robot::intake.spin(-127);
    glb::wpis1.set_value(false);
    chass.profiledDrive(20, 150);
    chass.profiledDrive(20, 50);
    robot::blocker.spin(35);
    chass.profiledDrive(-15, 10);
    robot::blocker.stop('b');
    chass.pidTurn(neg(90), 600, _90);
}

void six_far() {
    robot::scraper.toggle();
    robot::blocker.spin(40);
    glb::wpis1.set_value(true);
    pros::delay(300);
    robot::blocker.spin(-30);
    glb::wpis1.set_value(false);
    robot::intake.spin(127);
    robot::scraper.toggle();
    chass.profiledDrive(22, 10);
    robot::blocker.spin(0);
    robot::blocker.spin(0);
    robot::intake.spin(40);
    chass.profiledDrive(-24, 0);
    chass.arcTurn(neg(45), 11, 690, -1, _arc, 40);
    chass.arcTurn(45, 5, 800, 1, _arc, 5);
    robot::scraper.toggle();
    chass.profiledDrive(-8, 100);
    chass.pidTurn(neg(45), 920, _90);
    robot::scraper.toggle();
    chass.profiledDrive(-17, 100);
    chass.pidTurn(neg(90), 600, _45);
    chass.profiledDrive(-20, 20);
    chass.profiledDrive(7, 70);
    chass.pidTurn(0, 690, _90);
    chass.profiledDrive(20, 100);
    chass.pidTurn(44, 600, _45);
    robot::intake.spin(127);
    chass.profiledDrive(35, 330);
    glb::wpis1.set_value(true);
    robot:intake.spin(80);
    chass.pidTurn(170, 760, _135);
    robot::intake.spin(-127);
    glb::wpis1.set_value(false);
    chass.profiledDrive(20, 100);
    chass.profiledDrive(10, 100);
    robot::blocker.spin(70);
    chass.pidTurn(124, 600, _45);
    robot::blocker.stop('b');
    chass.profiledDrive(-35, 0);
    chass.arcTurn(133, 11, 1000, 1, _arc);
}

void safe_near() {
    // robot::scraper.toggle();
    // robot::blocker.spin(40);
    // pros::delay(300);
    // robot::blocker.spin(-30);
    // robot::intake.spin(127);
    // robot::scraper.toggle();
    chass.arcTurn(neg(45), 10, 1300, -1, _arc);
    robot::scraper.toggle();
    chass.pidTurn(neg(135), 900, _180);
    robot::scraper.toggle();
    robot::intake.spin(-127);
    chass.arcTurn(neg(90), 14, 1300, -1, _arc);
    chass.profiledDrive(17, 200);
    chass.arcTurn(180, 11, 1300, -1, _arc);
    robot::blocker.spin(50);
    chass.profiledDrive(-30, 200);
    robot::blocker.spin(0);
}

void skills() {
    robot::scraper.toggle();
    robot::blocker.spin(40);
    robot::intake.spin(-127);
    chass.profiledDrive(15, 130);
    robot::scraper.toggle();
    robot::blocker.spin(-20);
    chass.pidTurn(neg(17.4), 800, _15);
    robot::scraper.toggle();
    chass.profiledDrive(3);
    robot::blocker.spin(0);
    lib::timer t1;
    while (t1.time() < 30000) {
        robot::cata.spin(-127);
    }
    robot::scraper.toggle();
    robot::cata.stop('c');
    chass.arcTurn(60, 6.7, 600, 1, _arc, 30);
    chass.arcTurn(0, 7, 700, -1, _arc);
    robot::intake.spin(-127);
    chass.profiledDrive(-46, 0);
    chass.arcTurn(neg(90), 10, 800, -1, _arc);
    chass.timedDrive(800, -127);
    chass.pidTurn(neg(80), 200, _45);
    chass.profiledDrive(10, 0);
    chass.pidTurn(neg(70), 190, _45);
    chass.timedDrive(800,-127);
    chass.profiledDrive(5, 0);
    chass.pidTurn(10, 500, _90);
    chass.profiledDrive(39, 0);
    glb::wpis2.set_value(true);
    chass.pidTurn(90, 600, _90);
    glb::wpis2.set_value(false);
    chass.profiledDrive(20, 10);
    chass.pidTurn(4, 600, _45);
    robot::wings.toggle();
    chass.timedDrive(800, -127);
    chass.pidTurn(neg(2), 300, _45);
    robot::wings.toggle();
    // chass.pidTurn(90, 200, _90);
    // chass.pidTurn(180, 700, _90);
    // chass.arcTurn(neg(90), 7, 600, 1, _arc);
    // chass.arcTurn(0, 7, 1200, 1, _arc);
    // chass.arcTurn(90, 10, 950, -1, _arc, 20);
    chass.profiledDrive(20, 0);
    chass.pidTurn(85, 500, _90);
    chass.profiledDrive(21, 0);
    chass.pidTurn(4, 600, _45);
    robot::wings.toggle();
    chass.timedDrive(800, -127);
    chass.pidTurn(4, 300, _45);
    robot::wings.toggle();
    chass.profiledDrive(20, 10);
    chass.pidTurn(86, 500, _90);
    chass.profiledDrive(20, 10);
    glb::wpis2.set_value(true);
    chass.pidTurn(180, 600, _90);
    chass.profiledDrive(-10, 10);
    glb::wpis2.set_value(false);
    chass.pidTurn(neg(90), 600, _90);
    chass.timedDrive(1300, -127);
    chass.pidTurn(0, 900, _90);
    chass.arcTurn(90, 10, 800, 1, _arc);
    chass.profiledDrive(-20, 10);
    chass.pidTurn(80, 400, _45);
    chass.profiledDrive(20, 10);
    chass.pidTurn(60, 500, _45);
    chass.profiledDrive(-30, 130);


    // chass.pidTurn(neg(10), 700, _90);
    // chass.profiledDrive(25, 0);
    // chass.pidTurn(15, 700, _90);
    // chass.timedDrive(800, -127);
    // chass.pidTurn(0, 500, _45);
    // robot::wings.toggle();
    // chass.profiledDrive(27, 130);
    // chass.pidTurn(90, 550, _90);
    // robot::wings.toggle();
    // chass.profiledDrive(-15, 40);
    // chass.pidTurn(neg(10), 600, _45);
    // robot::wings.toggle();
    // chass.timedDrive(800, -127);

    // robot::wings.toggle();
    // chass.pidTurn(90, 200,


    // chass.pidTurn(190, 630, _90);
    // chass.profiledDrive(25, 50);
    // chass.profiledDrive(-30, 50);
    // robot::wings.toggle();

    // chass.pidTurn(90, 600, _90);
    // chass.profiledDrive(-15, 50);
    // chass.pidTurn(0, 550, _90);
    // robot::wings.toggle();
    // chass.profiledDrive(-30, 130);
    // robot::wings.toggle();
    // chass.arcTurn(107, 4.8, 940, -1, _arc);
    // chass.profiledDrive(30, 0);
    // chass.profiledDrive(7, 130);
    // chass.pidTurn(180, 200, _90);
    // chass.pidTurn(neg(90), 200, _90);
    // chass.pidTurn(0, 500, _90);
    // chass.arcTurn(90, 10, 800, 1, _arc);
    // chass.profiledDrive(-20, 10);
    // chass.pidTurn(80, 400, _45);
    // chass.profiledDrive(20, 10);
    // chass.pidTurn(60, 500, _45);
    // chass.profiledDrive(-30, 130);
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
    {test1, test2, six_far, calcTrack, safe_near, skills, elims_far, rush_far}, 
    {"test", "test2", "six_far", "track", "safe_near", "skills", "elims_far", "rush_far"}
};