#include "constants.hpp"
#define tr(x) 180 + (180 - x)

void pre_matchload() {
    // glb::vpis1.set_value(true);
    // pros::delay(250);
    // glb::vpis1.set_value(false);
    // pros::delay(250);
    robot::intake.spin(-127);
    chass.profiledDrive(6, 0,0,0);
    robot::chassMtrs.stop('b');
    pros::delay(200);
    // // robot::scraper.toggle();
    // // robot::blocker.spin(-50);
    // // chass.pidTurn(neg(22.6), 900, _15);
    chass.pidTurn(neg(152.1), 800, _90);
    // // robot::scraper.toggle();
    // // robot::blocker.spin(0);
    chass.profiledDrive(-3.7, 0);
        robot::chassMtrs.stop('b');
    pros::delay(200);
    // glb::vpis1.set_value(true);
    glb::wpis2.set_value(true);
}

void matchload() {
    cata::toggle();
    lib::timer t1;
    while (t1.time() < 24000) {
        chass.pidTurn(neg(152.1), 300, _15);
        pros::delay(20);
        // robot::cata.spin(-104);
    }
    cata::toggle();
}

void far_half() {
    cata::cut();
    cata::fire();

    // - first side push
    robot::intake.spin(127);
    glb::wpis1.set_value(true);
    chass.driveAngle(-1830, neg(27), 620, _lin, _ang);
    chass.driveAngle(-500, neg(80), 200, _lin, _ang);
    chass.driveAngle(-1500, neg(80), 400, _lin, _ang);
    // chass.timedDrive(500, -127);
    glb::wpis1.set_value(false);

    // - drive out
    chass.driveAngle(400, neg(53), 260, _lin, _angBig);
    chass.driveAngle(1300, neg(53), 450, _lin, _ang);
    chass.driveAngle(1300, neg(20), 480, _lin, _ang);
    
    // - second side push
    chass.pidTurn(6, 270, _90);
    glb::wpis1.set_value(true);
    glb::wpis2.set_value(true);
    chass.driveAngle(-1240, neg(30), 480, _lin, _ang);
    glb::wpis2.set_value(false);
    chass.driveAngle(-1200, neg(45), 370, _lin, _ang);
    chass.driveAngle(-300, neg(81), 240, _lin, _ang);
    chass.driveAngle(-4000, neg(81), 600, _lin, _ang);
    glb::wpis1.set_value(false);


    // - reallign balls on the side

    robot::intake.spin(127);
    chass.arcTurn(3, 5.1, 480, -1, _arc, 5);
    chass.driveAngle(1300, 4, 550, _lin, _ang);
    chass.pidTurn(neg(90), 360, _90);
    robot::wings.toggle();
    chass.driveAngle(-880, neg(90), 400, _lin, _ang);
    robot::wings.toggle();
    pros::delay(100);
    chass.driveAngle(500, neg(90), 360, _lin, _ang);

    // - push #1
    chass.pidTurn(30, 480, _90);
    chass.driveAngle(1330, 30, 510, _lin, _ang);
    robot::intake.spin(-127);
    chass.driveAngle(810, 80, 550, _lin, _ang);
    chass.pidTurn(176, 530, _90);
    robot::intake.spin(-127);
    glb::vpis2.set_value(true);
    chass.driveAngle(1500, 176, 300, _lin, _ang);
    chass.timedDrive(500, 90);
    glb::vpis2.set_value(false);

    // - push #2
    chass.driveAngle(-500, 177, 159, _lin, _angBig);
    chass.driveAngle(-1000, 177, 300, _lin, _angBig);
    chass.arcTurn(neg(157), 5.7, 370, 1, _arc, 30);
    chass.driveAngle(-1200, neg(157), 570, _lin, _ang);
    chass.pidTurn(181.7, 300, _90);
    robot::vwings.toggle();
    // glb::vpis2.set_value(true);
    robot::intake.spin(-127);
    chass.driveAngle(1500, 181.7, 300, _lin, _ang);
    chass.timedDrive(450, 90);
    robot::vwings.toggle();
    // glb::vpis2.set_value(false);



    // -push #3
    // chass.driveAngle(-300, 170, 300, _lin, _angBig);
    // robot::intake.spin(127);
    // chass.driveAngle(-1370, 170, 450, _lin, _ang);
    // chass.arcTurn(neg(110), 4.6, 390, 1, _arc, 15, 10);
    // chass.driveAngle(-900 , neg(110), 550, _lin, _ang);
    // chass.pidTurn(180, 480, _90);
    // robot::intake.spin(-127);
    // // chass.timedDrive(400, -30);
    // // glb::vpis2.set_value(true);
    // glb::vpis2.set_value(true);
    // chass.driveAngle(1500, 184, 300, _lin, _ang);
    // chass.timedDrive(530, 90);
    // // glb::vpis2.set_value(false);
    // glb::vpis2.set_value(false);

    // - get balls from corner
    chass.driveAngle(-300, 170, 300, _lin, _angBig);
    robot::intake.spin(127);
    chass.driveAngle(-900, 170, 400, _lin, _ang);
    chass.arcTurn(84, 5.9, 300, -1, _arc, 20);
    // chass.driveAngle(-1460, neg(97), 700, _lin, _ang);
    chass.driveAngle(2900, 84, 850, _lin, _ang);
    // glb::wpis2.set_value(true);

    // robot::wings.toggle();
    // chass.pidTurn(88, 450, _90);
    robot::intake.spin(-127);
    chass.pidTurn(180, 310, _90);
    chass.driveAngle(700, 180, 200, _lin, _ang);
    chass.driveAngle(-400, 180, 200, _lin, _ang);
    // chass.profiledDrive(-17, 0, 0, 0);

    robot::intake.spin(127);
    robot::vwings.toggle();
    chass.pidTurn(neg(117), 410, _90);
    chass.driveAngle(1300, neg(117), 540, _lin, _ang);
    chass.driveAngle(400, 180, 380, _lin, _ang);
    robot::intake.spin(-127);
    // chass.profiledDrive(6, 0, 0, 0);
    // robot::wings.toggle();

    // glb::wpis1.set_value(true);
    // chass.arcTurn(0, 5.8, 710, -1, _arc, 0, 30);
        // chass.profiledDrive(-6, 0, 0, 0);
    // chass.timedDrive(560, 45);
    // chass.eulerTurn(180, 0.0022, 750, 1, _eulF);
    // chass.
    robot::intake.spin(-127);
    // chass.driveAngle(-300, 180, 410, _lin, _ang);
    // pros::delay(70);
    // chass.timedDrive(560, 127);
    // chass.driveAngle(-600, 180, 410, _lin, _ang);
    chass.timedDrive(600, 90);
    robot::intake.spin(-127);
    // robot::wings.toggle();
    
    // chass.driveAngle(-300, 180, 250, _lin, _angBig);
    // chass.driveAngle(-800, 180, 500, _lin, _ang);

    // chass.pidTurn(0, 500, _180);
    // robot::wings.toggle();
    // chass.timedDrive(800, -127);
    // robot::wings.toggle();
    // robot::vwings.toggle();

    // // // - push

    // chass.timedDrive(800, 127);
    // robot::vwings.toggle();
    // robot::intake.spin(127);
    // chass.driveAngle(470, 10, 250, _lin, _angBig);
    // chass.driveAngle(400, 45, 200, _lin, _angBig);
    // chass.driveAngle(400, 91, 300, _lin, _ang);
    // chass.driveAngle(3200, 94, 1180, _lin, _ang);
    chass.driveAngle(-600, neg(170), 300, _lin, _angBig);
    robot::vwings.toggle();
    chass.pidTurn(100, 400, _90);
    chass.driveAngle(1500, 100, 500, _lin, _ang);
    // chass.driveAngle(400, 100, 300, _lin, _ang);
    chass.driveAngle(2000, 83, 200, _lin, _angBig);
    chass.driveAngle(2000, 83, 400, _lin, _ang);
    // robot::vwings.toggle();
    robot::intake.spin(-127);

    // glb::wpis1.set_value(true);
    chass.pidTurn(180, 200, _90);
    chass.pidTurn(neg(90), 200, _90);
    // chass.timedDrive(400, -70);
    // glb::wpis1.set_value(false);
   chass.pidTurn(neg(20), 500, _90);
   robot::wings.toggle();
    // glb::wpis2.set_value(true);
    chass.driveAngle(-600, 15, 300, _lin, _ang);
    // chass.arcTurn(20, 9, 380, 1, _arc, 40);
    chass.driveAngle(-1500, 30, 500, _lin, _ang);
    // chass.arcTurn(80, 6, 480, 1, _arc);
    chass.driveAngle(-500, 80, 410, _lin, _ang);
    chass.timedDrive(500, -127); //hi
    robot::wings.toggle();
    robot::intake.spin(127);
    chass.driveAngle(400, 50, 300, _lin, _angBig);

    chass.driveAngle(1700, 50, 600, _lin, _ang);
    robot::intake.spin(-70);
    
    chass.pidTurn(neg(4.2), 500, _90);
    
    // glb::wpis1.set_value(false);
    chass.arcTurn(20, 9, 380, 1, _arc, 40);
    robot::wings.toggle();
    chass.driveAngle(-1200, 15, 410, _lin, _ang);
    chass.driveAngle(-900, 80, 410, _lin, _ang);
    chass.timedDrive(500, -127);
    robot::wings.toggle();
    
    chass.driveAngle(400, 50, 300, _lin, _angBig);
    chass.driveAngle(600, 50, 600, _lin, _ang);
}

void post_matchload() {
    // - score starting matchloads
    glb::wpis2.set_value(false);
    robot::cata.stop('c');
    robot::intake.spin(-127);
    chass.pidTurn(neg(45), 400, _90);
    chass.driveAngle(840, neg(45), 380, _lin, _ang);
    chass.driveAngle(300, neg(81), 200, _lin, _ang);
    chass.driveAngle(1200, neg(81), 400, _lin, _ang);
    pros::delay(100);

    // - drive back 
    chass.driveAngle(-800, neg(45), 500, _lin, _ang);
    chass.pidTurn(neg(150), 380, _90);
    robot::intake.spin(127);
    chass.driveAngle(2780, neg(150), 800, _lin, _ang);
    glb::vpis2.set_value(true);
    chass.driveAngle(500, neg(99), 250, _lin, _angBig);
    robot::intake.spin(-127);
    chass.driveAngle(4300, neg(99), 1600, _lin, _ang);
    chass.driveAngle(-800, neg(90), 360, _lin, _ang);
    glb::vpis2.set_value(false);
    chass.driveAngle(1300, neg(90), 500, _lin, _ang);
    chass.driveAngle(-400, neg(90), 340, _lin, _ang);
    chass.pidTurn(neg(19), 400, _90);
    robot::intake.spin(127);
    chass.driveAngle(2000, neg(19), 600, _lin, _ang);

    // chass.driveAngle(-1400, 135, 590, _lin, _ang);
    chass.pidTurn(45, 240, _90);
    robot::intake.spin(-127);
    chass.driveAngle(-1400, 45, 300, _lin, _ang);
    chass.pidTurn(17, 230, _90);
    chass.driveAngle(-900, 17, 150, _lin, _ang);
    robot::wings.toggle();
    chass.pidTurn(4, 200, _90);
    
    // - get from matchload bar
    // robot::intake.spin(-127);


    // - drive back from matchloads + turn to face
    // chass.driveAngle(-1800, 45, 760, _lin, _ang);
    // chass.driveAngle(-600, 0, 260, _lin, _angBig);
    robot::intake.spin(-127);

    // - cross the field
    chass.driveAngle(-3790, 4, 1290, _lin, _ang);
    robot::wings.toggle();
    far_half();
}

void new_skills() {
    pre_matchload();
    matchload();
    post_matchload();
}


void no_matchload() {
    pre_matchload();
    post_matchload();
}