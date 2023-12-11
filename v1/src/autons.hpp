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

pidConstants _eul {
    .p = 1,
    .i = 0,
    .d = 0,
    .tolerance = 0,
    .integralThreshold = 3,
    .maxIntegral = 100
};

pidConstants _eulF {
    .p = 1.5,
    .i = 0,
    .d = 0,
    .tolerance = 0,
    .integralThreshold = 3,
    .maxIntegral = 100
};

void test1() {
    // chass.pidDrive(1000, 1500, linear);
    // chass.profiledDrive(25);    
    // chass.profiledTurn(25,1);
    // chass.eulerTurn(180, 0.001, 1300, 1, _eul);
    // chass.arcTurn(90, 12, 1400, 1, _arc);
}


void test2() {
    chass.profiledTurn(90,1);
    // chass.arcTurn()
    // chass.pidTurn(90, 4000, _90);
    // chass.pidTurn(45, 4000, _45);
}

void rush_near() {
    robot::intake.spin(127);
    robot::blocker.spin(80);
    pros::delay(400);
    robot::blocker.spin(-50);
    chass.profiledDrive(-20, 0, 0, 60);
    robot::blocker.spin(0);
    chass.profiledDrive(-45, 0, 60, 0);
    robot::wings.toggle();
    chass.pidTurn(90, 850, _90);
    // chass.pidTurn(neg(90), 500, _90);
    robot::wings.toggle();
    // chass.pidTurn(180, 500, _90);
    chass.arcTurn(125, 8, 700, 1, _arc, 30);
    chass.profiledDrive(-50, 0, 30, 30);
    chass.arcTurn(87, 5, 900, -1, _arc, 0);
    robot::intake.spin(-127);
    pros::delay(200);
    chass.timedDrive(800, 100);
    chass.arcTurn(50, 7, 800, -1, _arc, 30);
    chass.profiledDrive(-10,0);
    chass.arcTurn(140, 5.4, 1300, 1, _arc);
    robot::scraper.toggle();
    chass.profiledDrive(-5, 10);
    chass.pidTurn(45, 1300, _180);
    robot::scraper.toggle();
    robot::intake.spin(-127);
    chass.arcTurn(0, 12.5, 1300, -1, _arc);
    chass.profiledDrive(-28, 200);


}

void rush_far() {
    robot::scraper.toggle();
    robot::blocker.spin(40);
    glb::wpis1.set_value(true);
    pros::delay(300);
    glb::wpis1.set_value(false);
    robot::intake.spin(127);
    robot::scraper.toggle();
    chass.arcTurn(45, 6, 300, 1, _arc, 30);
    robot::intake.spin(127);
    chass.profiledDrive(48, 200, 40, 0);
    chass.pidTurn(0, 500, _45);
    robot::intake.spin(40);
    robot::wings.toggle();
    chass.timedDrive(750, -127);
    robot::wings.toggle();
    chass.profiledDrive(15, 10, 0, 0);
    chass.pidTurn(180, 600, _90);
    robot::intake.spin(0);
    chass.timedDrive(600, 90);
    chass.pidTurn(180, 500, _90);
    robot::blocker.spin(40);
    chass.profiledDrive(-20, 200, 0, 0);
    chass.pidTurn(neg(90), 500, _90);
    robot::blocker.stop('c');
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
    chass.profiledDrive(22, 200);
    robot::blocker.spin(0);
    robot::blocker.spin(0);
    robot::intake.spin(40);
    chass.profiledDrive(-29, 130);
    chass.pidTurn(135, 700, _135);
    robot::intake.spin(-127);
    chass.profiledDrive(15.7, 100);
    chass.pidTurn(45, 700, _90);
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

void reach_far() {
    robot::scraper.toggle();
    robot::blocker.spin(80);
    glb::wpis1.set_value(true);
    pros::delay(300);
    robot::blocker.spin(-70);
    glb::wpis1.set_value(false);
    pros::delay(260);
    robot::intake.spin(127);
    robot::scraper.toggle();
    robot::blocker.spin(0);
    chass.profiledDrive(22, 200);
    robot::intake.spin(40);
    chass.profiledDrive(-27, 0, 0, 50);
    chass.arcTurn(neg(45), 5.3, 340, -1, _arc, 30);
    chass.arcTurn(45, 5.4, 600, 1, _arc);
    robot::scraper.toggle();
    chass.profiledDrive(-10, 10, 0, 0);
    chass.pidTurn(neg(41), 800, _135);
    robot::scraper.toggle();
    pros::delay(260);
    chass.arcTurn(neg(90), 11.9, 750, -1, _arc, 0);
    chass.timedDrive(600, -127);
    chass.pidTurn(neg(70), 200, _135);
    chass.profiledDrive(6, 20, 0, 0);
    chass.pidTurn(90, 740, _90);
    robot::intake.spin(-127);
    chass.timedDrive(400, 100);
    pros::delay(200);
    chass.arcTurn(27.5, 6, 630, -1, _arc, 0);
    robot::intake.spin(127);
    chass.profiledDrive(39, 200);
    chass.pidTurn(150, 460, _90);
    robot::intake.spin(-127);
    chass.profiledDrive(7, 300);
    robot::intake.spin(127);
    chass.pidTurn(64, 400, _90);
    chass.profiledDrive(24, 200, 0, 10);
    chass.pidTurn(0, 500, _45);
    robot::intake.spin(40);
    robot::wings.toggle();
    chass.timedDrive(750, -127);
    robot::wings.toggle();
    chass.profiledDrive(15, 10, 0, 0);
    chass.pidTurn(190, 1000, _90);
    robot::intake.spin(-127);
    chass.timedDrive(760, 90);
    chass.pidTurn(180, 500, _90);
    robot::blocker.spin(40);
    chass.profiledDrive(-20, 200, 0, 0);
    chass.pidTurn(neg(90), 500, _90);
    robot::blocker.stop('c');
}

void new_far() {
    robot::blocker.spin(80);
    glb::wpis1.set_value(true);
    pros::delay(300);
    robot::blocker.spin(-70);
    glb::wpis1.set_value(false);
    pros::delay(260);
    robot::intake.spin(127);
    robot::blocker.spin(0);
    chass.profiledDrive(22, 200);
    // robot::intake.spin(40);
    chass.profiledDrive(-20, 0, 0, 50);
    chass.arcTurn(neg(45), 5.3, 340, -1, _arc, 10, 20);
    chass.pidTurn(135, 600, _90);
    glb::vpis2.set_value(true);
    chass.profiledDrive(14, 10, 0, 0);
    chass.pidTurn(90, 370, _135);
    glb::vpis2.set_value(false);
    pros::delay(50);
    chass.pidTurn(145, 400, _135);
    robot::intake.spin(-127);
    chass.arcTurn(90, 11.8, 750, 1, _arc, 0);
    // robot::vwings.toggle();
    chass.timedDrive(400, 100);
    pros::delay(40);
    chass.profiledDrive(-7, 0, 0, 0);
    // robot::vwings.toggle();
    pros::delay(130);
    chass.timedDrive(400, 100);
    pros::delay(200);
    chass.arcTurn(26, 6.3, 630, -1, _arc, 0);
    robot::intake.spin(127);
    chass.profiledDrive(39, 200);
    chass.pidTurn(148, 460, _90);
    robot::intake.spin(-127);
    pros::delay(400);
    chass.profiledDrive(3, 0, 0, 0);
    robot::intake.spin(127);
    pros::delay(150);
    chass.pidTurn(56.3, 400, _90);
    chass.profiledDrive(20, 0, 0, 0);
    pros::delay(230);
    chass.profiledDrive(-15, 0, 0, 0);
    pros::delay(130);
    // chass.pidTurn(80, 400, _45);
    chass.eulerTurn(183, 0.00335, 1000, -1, _eul);
    chass.pidTurn(184, 290, _90);
    robot::intake.spin(-127);
    robot::vwings.toggle();
    chass.timedDrive(750, 127);
    chass.profiledDrive(-11, 10, 0, 0);
    chass.timedDrive(760, 90);
    chass.pidTurn(180, 500, _90);
    robot::blocker.spin(40);
    chass.profiledDrive(-20, 200, 0, 0);
    robot::vwings.toggle();
    robot::blocker.stop('c');
    chass.pidTurn(neg(90), 500, _90);
}
void safe_near() {
    robot::scraper.toggle();
    robot::blocker.spin(70);
    robot::intake.spin(127);
    pros::delay(400);
    robot::blocker.spin(-70);
    robot::intake.spin(-127);
    robot::scraper.toggle();
    pros::delay(600);
    robot::blocker.spin(0);

    // robot::scraper.toggle();
    // robot::blocker.spin(40);
    // pros::delay(300);
    // robot::blocker.spin(-30);
    // robot::intake.spin(127);
    // robot::scraper.toggle();
    chass.profiledDrive(-5, 200,0,0);
    chass.arcTurn(neg(40), 4, 1300, -1, _arc);
    robot::scraper.toggle();
    chass.profiledDrive(-5, 10);
    chass.pidTurn(neg(135), 1300, _180);
    robot::scraper.toggle();
    // chass.arcTurn(neg(90), 14, 1300, -1, _arc);
    // chass.timedDrive(800, 127);
    // chass.arcTurn(180, 11, 1300, -1, _arc);
    robot::intake.spin(-127);
    chass.arcTurn(180, 12.5, 1300, -1, _arc);
    robot::blocker.spin(50);
    chass.profiledDrive(-24, 200);
    robot::blocker.spin(0);
}

void new_near() {
    // chass.arcTurn(neg(90), 14, 1300, -1, _arc);
    // chass.timedDrive(800, 127);
    // chass.arcTurn(180, 11, 1300, -1, _arc);
    robot::blocker.spin(60);
    glb::vpis1.set_value(true);
    chass.profiledDrive(14, 10, 0, 0);
    robot::blocker.spin(-46);
    chass.pidTurn(90, 370, _135);
    robot::blocker.spin(0);
    glb::vpis1.set_value(false);
    pros::delay(50);
    chass.pidTurn(30, 400, _135);
    robot::intake.spin(-127);
    chass.arcTurn(90, 10, 750, -1, _arc, 0);
    // robot::vwings.toggle();
    chass.timedDrive(450, 127);
    // robot::vwings.toggle();


    chass.arcTurn(45, 7.3, 450, -1, _arc, 60, 10);
    // chass.eulerTurn(45, 0.004, 1000, 1, _eul);
    chass.profiledDrive(-14, 0, 5, 70);
    chass.eulerTurn(0.01, 0.0017, 500, -1, _eulF);
    robot::blocker.spin(50);
    chass.profiledDrive(-32, 0, 5, 0);
    pros::delay(200);
    robot::blocker.spin(0);
}

void safe_far() {
    // robot::scraper.toggle();
    robot::blocker.spin(80);
    robot::intake.spin(127);
    pros::delay(400);
    robot::blocker.spin(-70);
    robot::intake.spin(-127);
    // robot::scraper.toggle();
    pros::delay(600);
    robot::blocker.spin(0);
    chass.timedDrive(1000, -127);
}
void skills() {
    /**/

    // robot::scraper.toggle();
    robot::blocker.spin(60);
    robot::intake.spin(-127);
    chass.profiledDrive(14, 130);
    // robot::scraper.toggle();
    robot::blocker.spin(-50);
    chass.pidTurn(neg(22.6), 900, _15);
    // robot::scraper.toggle();
    robot::blocker.spin(0);
    chass.profiledDrive(1);
    lib::timer t1;
    glb::vpis1.set_value(true);
    // while (t1.time() < 29200) {
    //     if(t1.time() >= 18000 && t1.time() < 20000) {
    //         chass.pidTurn(neg(17.8), 1000, _15);
    //     }
    //     robot::cata.spin(-127);
    // }
    glb::vpis1.set_value(false);
    // robot::scraper.toggle();
    robot::cata.stop('c');
    robot::intake.spin(-127);
    chass.pidTurn(45, 150, _90);
    chass.arcTurn(90, 6.3, 390, -1, _arc, 5, 40);
    // glb::vpis2.set_value(true);
    chass.timedDrive(400, 100);
    // chass.profiledDrive(-6,10);
    // glb::vpis2.set_value(false);
    // chass.timedDrive(300, 100);
    pros::delay(100);

    // - cool s manuever + drive
    chass.arcTurn(45, 7.3, 450, -1, _arc, 20, 40);
    chass.profiledDrive(-29.8, 0, 30, 60);
    chass.arcTurn(3, 7.3, 460, -1, _arc, 20, 10);
    robot::intake.spin(-127);
    // chass.profiledDrive(-46, 30);
    chass.profiledDrive(-79, 0, 40, 55);

    // - first side push
    glb::wpis1.set_value(true);
    chass.arcTurn(neg(83.5), 10.7, 800, -1, _arc);
    chass.timedDrive(500, -127);
    chass.pidTurn(neg(80), 280, _90);
    chass.profiledDrive(15, 0);
    chass.pidTurn(neg(60), 280, _45);
    glb::wpis1.set_value(false);
    chass.timedDrive(550, -127);
    pros::delay(100);


    /**/

    // chass.profiledDrive(7, 5);
    // chass.pidTurn(15, 470, _90);

    // - reallign balls on the side
    chass.arcTurn(neg(5), 5.4, 450, -1, _arc, 5);
    chass.profiledDrive(24, 10, 10, 0);
    chass.pidTurn(neg(89), 400, _90);
    chass.profiledDrive(-9, 0, 0, 10);
    // glb::wpis2.set_value(true);
    // robot::wings.toggle();
    chass.arcTurn(0, 5.5, 710, 1, _arc, 0, 30);
    chass.profiledDrive(6, 0, 0, 0);
    pros::delay(70);
    chass.timedDrive(450, -127);
    glb::wpis2.set_value(false);
    // robot::wings.toggle();


    // - allign for push #1
    chass.pidTurn(neg(6), 300, _90);
    chass.profiledDrive(20, 0, 0, 35);
    chass.arcTurn(45, 6, 370, -1, _arc, 30);
    chass.profiledDrive(13, 0, 0, 0);
    // chass.arcTurn(1, 4.5, 540, 1, _arc, 0, 10, 30);
    // glb::wpis2.set_value(true);
    chass.pidTurn(180, 580, _90);
    glb::vpis2.set_value(true);
    chass.timedDrive(730, 127);
    // glb::wpis2.set_value(false);
    glb::vpis2.set_value(false);
    chass.pidTurn(170, 300, _90);

    // - push #1
    // glb::wpis1.set_value(true);
    // glb::wpis2.set_value(true);
    // glb::wpis2.set_value(false);
    // glb::wpis1.set_value(false);
    // chass.pidTurn(90, 180, _90);
    // chass.pidTurn(183, 400, _90);



    // chass.pidTurn(90, 200, _90);
    // chass.pidTurn(180, 700, _90);
    // chass.arcTurn(neg(90), 7, 600, 1, _arc);
    // chass.arcTurn(0, 7, 1200, 1, _arc);
    // - allign for push #2
    // chass.profiledDrive(12, 0, 0, 50);
    // chass.arcTurn(10, 5.7, 260, -1, _arc, 40, 'c');
    // chass.profiledDrive(20, 0, 40, 30);
    // chass.arcTurn(neg(0), 5.7, 400, 1, _arc, 0);

    // for (int i = 0; i < 3; i++) {
        // - new allign for push #2
        chass.profiledDrive(-25, 0, 0, 5);
        chass.arcTurn(neg(89), 4.6, 400, 1, _arc, 20, 'c');
        chass.profiledDrive(-20, 0, 20, 0);
        chass.pidTurn(180, 510, _90);
        // robot::vwings.toggle();
        glb::vpis2.set_value(true);
        // - push #2
        // glb::wpis2.set_value(true);
        // glb::vpis2.set_value(true);
        // robot::vwings.toggle();
        chass.timedDrive(750, 127);
        glb::vpis2.set_value(false);
        // robot::vwings.toggle();
        chass.pidTurn(178, 460, _90);
    // }

    // - drive to side allign
    // glb::wpis2.set_value(false);
    // glb::vpis2.set_value(false);
    // robot::vwings.toggle();


    // chass.profiledDrive(-23, 0, 0, 0);
    // chass.pidTurn(88, 460, _90);
    //     chass.profiledDrive(8.2, 0, 0, 0);
    //     chass.pidTurn(183, 460, _90);
    //     robot::vwings.toggle();
    // chass.timedDrive(800, 127);
    // robot::vwings.toggle();
    // chass.pidTurn(178, 450, _90);

    // chass.profiledDrive(-23, 0, 0, 0);
    // chass.pidTurn(88, 500, _90);
    // chass.arcTurn(180, 4.6, 600, -1, _arc, 0, 30);
    // glb::vpis2.set_value(true);
    // chass.timedDrive(800, 127);
    // glb::vpis2.set_value(false);
    // chass.pidTurn(178, 500, _90);


    chass.profiledDrive(-27, 0, 0, 0);
    // glb::wpis2.set_value(true);

    // - get balls from corner
    // robot::wings.toggle();
    chass.pidTurn(88, 450, _90);
    chass.profiledDrive(25, 0, 0, 0);
    chass.pidTurn(180, 450, _90);
    chass.profiledDrive(10, 0, 0, 0);
    chass.pidTurn(neg(90), 470, _90);

    robot::vwings.toggle();
    robot::intake.spin(127);
    chass.eulerTurn(180, 0.001, 900, 1, _eul);
    robot::intake.spin(-127);
    chass.timedDrive(400, 127);
    robot::vwings.toggle();



    chass.pidTurn(183, 230, _45);
    chass.profiledDrive(-10, 0, 0, 0);

    chass.pidTurn(0, 600, _180);

    // // - push #1

    // // - push

    robot::wings.toggle();
    chass.timedDrive(800, -127);
    robot::wings.toggle();
    chass.profiledDrive(5, 0, 0, 0);

    
    // robot::wings.toggle();
    // chass.pidTurn(90, 180, _90);
    // chass.pidTurn(177, 400, _90);


    // - drive out and funnel balls
    // chass.profiledDrive(20, 0, 0, 20);
    // chass.arcTurn(neg(90), 5, 500, 1, _arc, 30, 'c');
    // chass.profiledDrive(-50, 0, 30, 0);
    // chass.arcTurn(10, 5, 600, 1, _arc, 30, 'c');

    // robot::wings.toggle();
    // chass.timedDrive(800, -127);
    // chass.pidTurn(0, 500, _45);
    // robot::wings.toggle();

    // glb::wpis1.set_value(true);
    // chass.profiledDrive(17, 0, 30, 0);
    // chass.profiledDrive(-20, 0, 0, 30);
    // robot::wings.toggle();
    // chass.arcTurn(90, 5, 600, -1, _arc, 30);
    // chass.arcTurn(0, 5, 600, -1, _arc, 30);
    // chass.profiledDrive(-20, 0, 30, 0);

    // chass.profiledDrive(25, 0);
    // robot::wings.toggle();
    // chass.pidTurn(180, 630, _90);
    // chass.profiledDrive(15, 50);
    // robot::wings.toggle();
    // chass.arcTurn(neg(90), 6, 800, -1, _arc);
    // chass.arcTurn(neg(0), 6, 800, -1, _arc);
    // robot::wings.toggle();
    // chass.timedDrive(800, -127);
    // robot::wings.toggle();

    chass.arcTurn(92, 4.5, 600, -1, _arc, 5, 10);
    robot::wings.toggle();
    pros::delay(200);
    robot::wings.toggle();
    // chass.pidTurn(97, 400, _90);
    chass.profiledDrive(57, 0, 30, 10);
    glb::wpis2.set_value(true);
    chass.pidTurn(180, 200, _90);
    chass.pidTurn(neg(90), 340, _90);
    glb::wpis2.set_value(false);
    chass.pidTurn(5, 400, _90);
    chass.arcTurn(86, 7.6, 700, 1, _arc);
    chass.timedDrive(700, -127);
    chass.pidTurn(90, 200, _90);
    chass.profiledDrive(17, 10);
    chass.pidTurn(60, 300, _45);
    chass.timedDrive(700, -127);
    chass.profiledDrive(17, 10);
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

void sus_near() {
    robot::blocker.spin(60);
    chass.arcTurn(90, 16, 1300, 1, _arc);
    robot::blocker.spin(-40);
    chass.timedDrive(800, -127);
    robot::blocker.spin(0);
    chass.arcTurn(45, 14, 1300, 1, _arc);
    glb::vpis2.set_value(true);
    chass.profiledDrive(19, 0, 0, 0);
    chass.pidTurn(neg(10), 500, _45);
    glb::vpis2.set_value(false);
    pros::delay(100);
    chass.pidTurn(230, 1000, _90);
    chass.arcTurn(180, 10.1, 800, -1, _arc);
    robot::blocker.spin(50);
    chass.profiledDrive(-37, 0, 20, 0);
    robot::blocker.spin(0);
    robot::chassMtrs.spin(0);      
}

//creates list of auton function pointers and names - useful for auton selector
// lib::atns autons = {
//     {test1, test2, six_far, safe_far, calcTrack, safe_near, skills, rush_far, reach_far, rush_near, new_far, new_near}, 
//     {"test", "test2", "six_far", "safe_far", "track", "safe_near", "skills", "rush_far", "reach_far", "rush_near", "new_far", "new_near"}
// };


lib::atns autons = {
    {skills, new_far, new_near, sus_near}, 
    {"skills", "new_far", "new_near", "sus_near"}
};
