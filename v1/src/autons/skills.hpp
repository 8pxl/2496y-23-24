#include "constants.hpp"

void pre_matchload() {
    glb::vpis1.set_value(true);
    pros::delay(250);
    glb::vpis1.set_value(false);
    pros::delay(250);
    robot::intake.spin(-127);
    chass.profiledDrive(4, 0,0,0);
    robot::chassMtrs.stop('b');
    pros::delay(500);
    // // robot::scraper.toggle();
    // // robot::blocker.spin(-50);
    // // chass.pidTurn(neg(22.6), 900, _15);
    chass.pidTurn(151, 900, _90);
    // // robot::scraper.toggle();
    // // robot::blocker.spin(0);
    // chass.profiledDrive(-2.5, 0);
    // glb::vpis1.set_value(true);
    cata::toggle();
    glb::wpis2.set_value(true);
}

void matchload() {
    lib::timer t1;
    while (t1.time() < 24000) {
        if(t1.time() >= 20000 && t1.time() < 24000) {
            chass.pidTurn(151, 300, _15);
        }
        else {
            chass.pidTurn(151, 300, _15);
        }
        pros::delay(20);
        // robot::cata.spin(-104);
    }
    cata::toggle();
}

void post_matchload() {
    // glb::vpis1.set_value(false);
    glb::wpis2.set_value(false);
    // robot::scraper.toggle();
    robot::cata.stop('c');
    robot::intake.spin(-127);
    chass.pidTurn(45, 380, _90);
    chass.driveAngle(1600, 45, 500, _lin, _ang);
    // chass.arcTurn(90, 7.3, 390, -1, _arc, 5, 40);
    chass.driveAngle(300, 90, 200, _lin, _angBig);
    // glb::vpis2.set_value(true);
    chass.timedDrive(300, 127);
    chass.driveAngle(600, 90, 200, _lin, _ang);
    // chass.profiledDrive(-6,10);
    // glb::vpis2.set_value(false);
    // chass.timedDrive(300, 100);
    pros::delay(100);

    // - cool s manuever + drive
    // chass.arcTurn(45, 7.3, 380, -1, _arc, 35, 15);
    chass.driveAngle(-1800, 45, 760, _lin, _ang);

    // chass.profiledDrive(-23.2, 0, 15, 60);
    // chass.arcTurn(2, 7.3, 270, -1, _arc, 20, 30);
    chass.driveAngle(-600, 0, 260, _lin, _angBig);
    robot::intake.spin(-127);
    // chass.profiledDrive(-46, 30);
    // chass.profiledDrive(-79, 0, 40, 55);
    chass.driveAngle(-4050, 4, 1260, _lin, _ang);
    cata::cut();
    cata::fire();

    // - first side push
    robot::intake.spin(127);
    glb::wpis1.set_value(true);
    chass.arcTurn(neg(21), 9.3, 400, -1, _arc, 40);
    chass.driveAngle(-1240, neg(21), 410, _lin, _ang);
    chass.arcTurn(neg(75), 7.1, 410, -1, _arc);
    chass.timedDrive(500, -127);
    glb::wpis1.set_value(false);

    chass.driveAngle(400, neg(65), 260, _lin, _angBig);
    chass.driveAngle(1500, neg(65), 540, _lin, _ang);
    
    chass.pidTurn(6, 500, _90);
    glb::wpis1.set_value(true);
    
    // glb::wpis1.set_value(false);
    // chass.arcTurn(neg(20), 9, 380, -1, _arc, 40);

    chass.driveAngle(-1300, neg(34), 410, _lin, _ang);
    chass.arcTurn(neg(75), 6, 400, -1, _arc);

    // chass.driveAngle(900, neg(70), 600, _lin, _angBig);

    chass.timedDrive(550, -127);
    glb::wpis1.set_value(false);

    // chass.driveAngle(130, neg(90), 150, _lin, _angBig);
    // chass.pidTurn(neg(87), 300, _90);
    // chass.driveAngle(500, neg(90), 500, _lin, _ang);



    // chass.profiledDrive(7, 5);
    // chass.pidTurn(15, 470, _90);

    

    // - reallign balls on the side

    
    robot::intake.spin(127);
    chass.arcTurn(3, 5.1, 480, -1, _arc, 5);
    chass.driveAngle(1460, 4, 600, _lin, _ang);
    // chass.arcTurn(173, 5.3, 800, -1, _arc, 5);
    // chass.arcTurn(45, 5.3, 600, -1, _arc, 5);
    chass.pidTurn(neg(90), 360, _90);
    robot::wings.toggle();
    chass.driveAngle(-880, neg(90), 400, _lin, _ang);
    chass.driveAngle(500, neg(90), 360, _lin, _ang);
    robot::wings.toggle();
    // pros::delay(200);//

    // - push #1
    chass.pidTurn(30, 480, _90);
    robot::intake.spin(-127);
    chass.driveAngle(1290, 30, 480, _lin, _ang);
    chass.driveAngle(950, 80, 390, _lin, _ang);
    chass.pidTurn(176, 430, _90);
    // chass.driveAngle(700, 163, 250, _lin, _ang);
    robot::intake.spin(-127);
    // robot::vwings.toggle();
    glb::vpis2.set_value(true);
    chass.driveAngle(1500, 176, 300, _lin, _ang);
    chass.timedDrive(500, 90);
    glb::vpis2.set_value(false);

// - push #2
    chass.driveAngle(-300, 177, 300, _lin, _angBig);
    // robot::intake.spin(127);
    chass.driveAngle(-950, 177, 330, _lin, _angBig);
    chass.arcTurn(neg(140), 5.7, 370, 1, _arc, 30);
    chass.driveAngle(-800, neg(140), 430, _lin, _angBig);
    chass.pidTurn(181.7, 430, _90);
    glb::vpis2.set_value(true);
    robot::intake.spin(-127);
    chass.driveAngle(1500, 181.7, 300, _lin, _ang);
    chass.timedDrive(450, 90);
    glb::vpis2.set_value(false);



    // -push #3
    chass.driveAngle(-300, 170, 300, _lin, _angBig);
    robot::intake.spin(127);
    chass.driveAngle(-1370, 170, 450, _lin, _ang);
    chass.arcTurn(neg(110), 4.6, 390, 1, _arc, 15, 10);
    chass.driveAngle(-900 , neg(110), 550, _lin, _ang);
    chass.pidTurn(180, 480, _90);
    robot::intake.spin(-127);
    // chass.timedDrive(400, -30);
    // glb::vpis2.set_value(true);
    glb::vpis2.set_value(true);
    chass.driveAngle(1500, 184, 300, _lin, _ang);
    // - push #2
    chass.timedDrive(530, 90);
    // glb::vpis2.set_value(false);
    glb::vpis2.set_value(false);

    /*
        chass.driveAngle(-300, 170, 300, _lin, _angBig);
        chass.driveAngle(-1240, 170, 450, _lin, _ang);
        chass.arcTurn(neg(91), 4.6, 390, 1, _arc, 20, 10);
        chass.driveAngle(-560, neg(90), 410, _lin, _ang);
        chass.pidTurn(183, 480, _90);
        glb::vpis2.set_value(true);
        // - push #2
        chass.timedDrive(750, 127);
        glb::vpis2.set_value(false);
    */

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


    // chass.profiledDrive(-27, 0, 0, 0);
    chass.driveAngle(-300, 170, 300, _lin, _angBig);
    robot::intake.spin(127);
    chass.driveAngle(-900, 170, 460, _lin, _ang);
    chass.arcTurn(84, 5.9, 400, -1, _arc, 20);
    // chass.driveAngle(-1460, neg(97), 700, _lin, _ang);
    chass.driveAngle(2490, 84, 800, _lin, _ang);
    // glb::wpis2.set_value(true);

    // - get balls from corner
    // robot::wings.toggle();
    // chass.pidTurn(88, 450, _90);
    chass.pidTurn(180, 310, _90);
    robot::intake.spin(-127);
    chass.driveAngle(700, 180, 600, _lin, _ang);
    chass.driveAngle(-400, 180, 410, _lin, _ang);
    // chass.driveAngle(350, neg(10), 410, _lin, _ang);
    // chass.profiledDrive(-17, 0, 0, 0);

    chass.pidTurn(neg(135), 410, _90);
    robot::vwings.toggle();
    chass.profiledDrive(6, 0, 0, 0);
    // robot::wings.toggle();

    // glb::wpis1.set_value(true);
    // chass.arcTurn(0, 5.8, 710, -1, _arc, 0, 30);
        // chass.profiledDrive(-6, 0, 0, 0);
        robot::intake.spin(40);
    chass.timedDrive(560, 45);
    chass.eulerTurn(180, 0.0022, 750, 1, _eul);
    robot::intake.spin(-127);
    chass.driveAngle(-300, 180, 410, _lin, _ang);
    // pros::delay(70);
    chass.timedDrive(560, 127);
    chass.driveAngle(-600, 180, 410, _lin, _ang);
    chass.timedDrive(560, 127);
    robot::intake.spin(-127);
    // robot::wings.toggle();
    robot::vwings.toggle();
    
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
    robot::intake.spin(127);
    // chass.driveAngle(470, 10, 250, _lin, _angBig);
    // chass.driveAngle(400, 45, 200, _lin, _angBig);
    // chass.driveAngle(400, 91, 300, _lin, _ang);
    // chass.driveAngle(3200, 94, 1180, _lin, _ang);
    chass.driveAngle(-470, neg(170), 250, _lin, _angBig);
    chass.driveAngle(-400, neg(135), 200, _lin, _angBig);
    chass.driveAngle(-400, neg(90), 300, _lin, _ang);
    chass.driveAngle(-3200, neg(94), 1180, _lin, _ang);
    robot::intake.spin(-127);

    // glb::wpis1.set_value(true);
    chass.pidTurn(10, 300, _90);
    chass.pidTurn(40, 300, _90);
    chass.pidTurn(neg(87), 400, _90);
    chass.timedDrive(400, -70);
    // glb::wpis1.set_value(false);
    glb::wpis2.set_value(true);
   chass.pidTurn(neg(4.2), 500, _90);
    // glb::wpis2.set_value(true);
    chass.driveAngle(-600, 0, 300, _lin, _ang);
    // chass.arcTurn(20, 9, 380, 1, _arc, 40);
    chass.driveAngle(-1100, 15, 410, _lin, _ang);
    // chass.arcTurn(80, 6, 480, 1, _arc);
    chass.driveAngle(-500, 80, 410, _lin, _ang);
    chass.timedDrive(500, -127); //hi
    glb::wpis2.set_value(false);
    robot::intake.spin(127);
    chass.driveAngle(400, 50, 300, _lin, _angBig);

    chass.driveAngle(1700, 50, 600, _lin, _ang);
    robot::intake.spin(-70);
    
    chass.pidTurn(neg(4.2), 500, _90);
    glb::wpis2.set_value(true);
    
    // glb::wpis1.set_value(false);
    chass.arcTurn(20, 9, 380, 1, _arc, 40);

    chass.driveAngle(-900, 15, 410, _lin, _ang);
    chass.arcTurn(89, 6, 480, 1, _arc);
    chass.timedDrive(500, -127);
    glb::wpis2.set_value(false);
    
    chass.driveAngle(400, 50, 300, _lin, _angBig);
    chass.driveAngle(600, 50, 600, _lin, _ang);

    // chass.pidTurn(neg(2.5), 700, _90);
    // chass.arcTurn(20, 9, 380, 1, _arc, 40);
    // chass.driveAngle(-900, 15, 410, _lin, _ang);
    // chass.arcTurn(89, 6, 480, 1, _arc);
    // chass.timedDrive(500, -127);
    // chass.profiledDrive(20, 0,0 ,0);
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