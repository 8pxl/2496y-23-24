#include "constants.hpp"
#include "pros/rtos.hpp"
#define tr(x) 180 + (180 - x)

void pre_matchload() {
    // pros::delay(250);
    // pros::delay(250);
    robot::intake.spin(-127);
    chass.profiledDrive(7.2, 0,0,0);
    robot::chassMtrs.stop('b');
    pros::delay(200);
    chass.pidTurn(neg(153), 800, _90);
    // // robot::scraper.toggle();
    // // robot::blocker.spin(0);
    chass.profiledDrive(-3.7, 0);
        robot::chassMtrs.stop('b');
    pros::delay(200);
    // glb::rhoriz.set_value(true);
}

void matchload() {
    // cata::toggle();
    lib::timer t1;
    // glb::lvert.set_value(true);
    robot::cata.spin(127);
    while (t1.time() < 22000) {
        chass.pidTurn(neg(153.4), 300, _15);
        pros::delay(20);
    }
    // glb::lvert.set_value(false);
    // cata::toggle();
}

void end(){
    // chass.driveAngle(800, 45, 400, _lin, _ang);
    // chass.driveAngle(2000, 83, 400, _lin, _ang);
    
    // - hang
    // chass.driveAngle(1600, 0, 500, _lin, _ang,false );
    
    // chass.driveAngle(2800, neg(31), 900, _lin, _ang,false )
    chass.arcTurn(neg(31), 5.5, 1000, 1, _arc);
    // chass.driveAngle(600, 0, 700, _lin, _ang);
    // chass.pidTurn(neg(31), 350, _45);
    chass.driveAngle(1990, neg(31), 900, _lin, _ang, true);
    chass.pidTurn(neg(135), 500, _90);
    robot::hang.toggle();
    pros::delay(700);
    // chass.driveAngle(-1000, neg(135), 800, _lin, _ang, true, 0, 10);
    // chass.pidDrive(-800, 800, _lin);
    chass.timedDrive(300, -60);
    chass.timedDrive(800, -25);
    chass.timedDrive(200, -10);
    chass.timedDrive(200, 60);
    
    robot::pto.toggle();
    chass.timedDrive(600, 127);
    robot::boost.toggle();
    chass.timedDrive(5000, 127);
}

void far_half() {
    cata::cut();
    cata::fire();

    // - first side push
    robot::intake.spin(-127);
    // chass.pidTurn(183, 450, _90);
    robot::wings.setState(true);
    // glb::rhoriz.set_value(true);
    chass.driveAngle(2100, 153, 720, _lin, _ang);
    // chass.driveAngle(500, 135, 200, _lin, _ang);
    chass.driveAngle(1200, 94, 300, _lin, _ang);
    glb::lhoriz.set_value(false);
    // chass.driveAngle(-1000, 100, 200, _lin, _ang);
    chass.driveAngle(3000, 94, 350, _lin, _ang);
    // chass.timedDrive(500, -127);
    // glb::rhoriz.set_value(false);

    chass.driveAngle(-3000, 94, 300, _lin, _ang);
    chass.driveAngle(8000, 94, 500, _lin, _ang);
    robot::wings.setState(false);

    /*
    // - drive out
    chass.driveAngle(-400, 127, 260, _lin, _angBig);
    chass.driveAngle(-1300, 127, 450, _lin, _ang);
    chass.driveAngle(-1300, 160, 460, _lin, _ang);

    // - second side push
    chass.pidTurn(174, 200, _90);
    glb::rhoriz.set_value(true);
    chass.driveAngle(1240, 150, 480, _lin, _ang);
    chass.driveAngle(990, 135, 300, _lin, _ang);
    // chass.driveAngle(-300, neg(81), 240, _lin, _ang);
    chass.driveAngle(700, 93, 300, _lin, _ang);
    chass.driveAngle(5000, 93, 400, _lin, _ang);
    // chass.driveAngle(-5000, 100, 700, _lin, _ang);
    glb::rhoriz.set_value(false);
    */

    // - reallign balls on the side

    /* old allign
    robot::intake.spin(127);
    chass.arcTurn(3, 5.1, 480, -1, _arc, 5);
    chass.driveAngle(1300, 4, 550, _lin, _ang);
    chass.pidTurn(neg(90), 360, _90);
    robot::wings.toggle();
    chass.driveAngle(-1040, neg(90), 400, _lin, _ang);
    robot::wings.toggle();
    pros::delay(100);
    chass.driveAngle(500, neg(90), 360, _lin, _ang);
    */
    robot::intake.spin(127);
    chass.pidTurn(117, 200, _90);
    chass.driveAngle(-700, 117, 400, _lin, _ang);
    robot::wings.setState(false);
    chass.pidTurn(13, 490, _90);
    robot::wings.setState(true);
    chass.driveAngle(1400, 13, 490, _lin, _ang);
    glb::lhoriz.set_value(false);
    chass.driveAngle(1500, neg(18), 500, _lin, _ang);
    chass.pidTurn(90, 300, _90);
    robot::intake.spin(-127);
    chass.driveAngle(1300, 90, 540, _lin, _ang);
    chass.driveAngle(400, 90, 310, _lin, _ang, false);
    // chass.pidTurn(180, 300, _90);
    // chass.driveAngle(600, 180, 300, _lin, _ang);

    // glb::rhoriz.set_value(true);
    // glb::lhoriz.set_value(true);
    chass.pidTurn(neg(30), 340, _90);
    robot::wings.setState(false);
    robot::vwings.setState(true);
    robot::intake.spin(-127);
    chass.driveAngle(-1550, neg(30), 600, _lin, _ang);
    chass.driveAngle(-1500, 0, 300, _lin, _ang);
    chass.timedDrive(500, -127);
    robot::vwings.setState(false);

    // new allign
    /*
    robot::intake.spin(127);
    chass.arcTurn(3, 5.1, 480, -1, _arc, 5);
    chass.driveAngle(1300, 4, 550, _lin, _ang);

    // - push #1
    chass.pidTurn(30, 400, _90);
    chass.driveAngle(1330, 30, 510, _lin, _ang);
    robot::intake.spin(-127);
    chass.driveAngle(930, 80, 550, _lin, _ang);
    chass.pidTurn(176, 530, _90);
    robot::intake.spin(-127);
    glb::lhoriz.set_value(true);
    chass.driveAngle(1500, 176, 300, _lin, _ang);
    chass.timedDrive(500, 90);
    glb::lhoriz.set_value(falsyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy7e);
    */

    // - push #2
    // chass.driveAngle(-500, 177, 159, _lin, _angBig);
    robot::intake.spin(127);
    chass.driveAngle(1500, neg(20), 550, _lin, _angBig);
    chass.arcTurn(290, 10, 500, 1, _arc, 30);
    robot::vwings.setState(true);
    chass.driveAngle(-1000, 280, 500, _lin, _ang);
    chass.pidTurn(neg(2), 500, _90);
    // robot::vwings.setState(true);
    // glb::lhoriz.set_value(true);

    chass.driveAngle(-1500, neg(2), 300, _lin, _ang);
    chass.timedDrive(740, -90);
    robot::vwings.setState(false);
    chass.driveAngle(900, 0, 400, _lin, _ang);
    glb::rvert.set_value(true);
    chass.driveAngle(-1500, 0, 500, _lin, _ang);
    glb::rvert.set_value(false);
    // chass.driveAngle(-400, 181.7, 200, _lin, _ang);
    // chass.timedDrive(120, 127);
    // robot::wings.toggle();
    // glb::lhoriz.set_value(false);



    // -push #3
    // chass.driveAngle(-300, 170, 300, _lin, _angBig);
    // robot::intake.spin(127);
    // chass.driveAngle(-1370, 170, 450, _lin, _ang);
    // chass.arcTurn(neg(110), 4.6, 390, 1, _arc, 15, 10);
    // chass.driveAngle(-900 , neg(110), 550, _lin, _ang);
    // chass.pidTurn(180, 480, _90);
    // robot::intake.spin(-127);
    // // chass.timedDrive(400, -30);
    // // glb::lhoriz.set_value(true);
    // glb::lhoriz.set_value(true);
    // chass.driveAngle(1500, 184, 300, _lin, _ang);
    // chass.timedDrive(530, 90);
    // // glb::lhoriz.set_value(false);
    // glb::lhoriz.set_value(false);

    // - get balls from corner
    chass.driveAngle(300, neg(15), 200, _lin, _angBig);
    robot::intake.spin(127);
    chass.driveAngle(1600, neg(15), 600, _lin, _ang);
    chass.arcTurn(280, 5.9, 300, 1, _arc, 20);
    // chass.driveAngle(-1460, neg(97), 700, _lin, _ang);
    chass.driveAngle(-3280, 280, 900, _lin, _ang);
    // glb::wpis2.set_value(true);

    // robot::wings.toggle();
    // chass.pidTurn(88, 450, _90);
    robot::intake.spin(-127);
    chass.pidTurn(0, 310, _90);
    robot::vwings.setState(true);
    chass.driveAngle(-700, 0, 200, _lin, _ang);
    // chass.driveAngle(-400, 180, 200, _lin, _ang);
    // chass.profiledDrive(-17, 0, 0, 0);

    robot::intake.spin(127);
    // robot::wings.toggle();
    chass.pidTurn(neg(117+180), 410, _90);
    chass.driveAngle(-1100, neg(117+180), 490, _lin, _ang);
    chass.driveAngle(-400, 0, 380, _lin, _ang);
    robot::intake.spin(-127);
    // chass.profiledDrive(6, 0, 0, 0);
    // robot::wings.toggle();

    // glb::wpis1.set_value(true);
    // chass.arcTurn(0, 5.8, 710, -1, _arc, 0, 30);
        // chass.profiledDrive(-6, 0, 0, 0);
    chass.timedDrive(560, -90);
    // chass.eulerTurn(180, 0.0022, 750, 1, _eulF);
    // chass.
    robot::intake.spin(-127);
    chass.driveAngle(1200, 0, 360, _lin, _ang);
    // pros::delay(70);
    // chass.timedDrive(560, 127);
    // chass.driveAngle(-600, 180, 410, _lin, _ang);
    chass.timedDrive(600, -90);
    robot::vwings.setState(false);
    robot::intake.spin(-127);
    // robot::wings.toggle();

    // chass.driveAngle(-300, 180, 250, _lin, _angBig);
    // chass.driveAngle(-800, 180, 500, _lin, _ang);

    // chass.pidTurn(0, 500, _180);
    // robot::wings.toggle();
    // chass.timedDrive(800, -127);
    // robot::wings.toggle();
    // robot::wings.toggle();

    // // // - push

    // chass.timedDrive(800, 127);
    // robot::wings.toggle();
    // robot::intake.spin(127);
    // chass.driveAngle(470, 10, 250, _lin, _angBig);
    // chass.driveAngle(400, 45, 200, _lin, _angBig);
    // chass.driveAngle(400, 91, 300, _lin, _ang);
    // chass.driveAngle(3200, 94, 1180, _lin, _ang);
    chass.driveAngle(650, neg(170+180), 400, _lin, _angBig);
    robot::wings.setState(false);
    chass.pidTurn(105, 340, _90);
    chass.driveAngle(1500, 105, 500, _lin, _ang);
    // chass.driveAngle(400, 100, 300, _lin, _ang);
    chass.driveAngle(2000, 83, 300, _lin, _angBig);
    chass.driveAngle(2000, 83, 400, _lin, _ang, false);
    robot::wings.toggle();
    chass.pidTurn(200, 300, _180);
    chass.pidTurn(neg(90), 300, _180);
    // chass.driveAngle(900, 0, 400, _lin, _ang);
    // robot::wings.toggle();
    robot::intake.spin(-127);

    // glb::wpis1.set_value(true);
    //
    // chass.pidTurn(neg(145), 400, _90);

    // chass.pidTurn(90, 340, _90);
    chass.driveAngle(800, neg(10), 360, _lin, _angBig);
    // chass.pidTurn(neg(10), 350, _90);
    robot::wings.toggle();
    glb::rvert.set_value(true);
    chass.driveAngle(-1770, 27, 620, _lin, _ang);
    chass.driveAngle(-1000, 80, 300, _lin, _ang);
    // chass.driveAngle(-4000, 80, 340, _lin, _ang);
    chass.timedDrive(500, -127);
    chass.driveAngle(1000, 90, 250, _lin, _ang);
    chass.timedDrive(400, -127);
    glb::rvert.set_value(false);

    // - drive out
    end();
    
    /*
    // chass.driveAngle(-1300, neg(126), 450, _lin, _ang);
    // chass.driveAngle(-1270, neg(160), 460, _lin, _ang);

    // - second side push
    chass.pidTurn(neg(174), 190, _90);
    glb::lhoriz.set_value(true);
    chass.driveAngle(1240, neg(150), 480, _lin, _ang);
    chass.driveAngle(1300, neg(135), 370, _lin, _ang);
    // chass.driveAngle(-300, neg(81), 240, _lin, _ang);
    // chass.pidTurn(93, neg(150), _90);
    chass.driveAngle(4000, neg(93), 450, _lin, _ang);
    chass.driveAngle(-3000, neg(93), 300, _lin, _ang);
    chass.driveAngle(8000, neg(93), 500, _lin, _ang);
    // chass.driveAngle(-5000, 100, 700, _lin, _ang);
    glb::lhoriz.set_value(false);

    // hang
    chass.driveAngle(-580, neg(137), 300, _lin, _angBig);
    // robot::blocker.spin(100);
    chass.driveAngle(-1839, neg(137), 600, _lin, _ang);
    // chass.pidTurn(neg(1.3), 490, _90);
    // // // robot::blocker.spin(10);
    // chass.driveAngle(2500, neg(1.3), 860, _lin, _ang);
    // // robot::blocker.stop('c');
    // // robot::pto.toggle();
    // chass.timedDrive(1000, 110);
    //
    */
}

void post_matchload() {
    // - score starting matchloads
    robot::cata.stop('c');
    robot::intake.spin(-127);
    chass.pidTurn(neg(45), 380, _90);
    chass.driveAngle(700, neg(50), 340, _lin, _ang);
    chass.driveAngle(1200, neg(90), 400, _lin, _ang);
    chass.timedDrive(300, 127);

    // - drive back
    chass.driveAngle(-800, neg(45), 470, _lin, _ang);
    chass.pidTurn(neg(150), 380, _90);
    robot::intake.spin(127);
    chass.driveAngle(2830, neg(150), 870, _lin, _ang);
    glb::lvert.set_value(true);
    glb::rhoriz.set_value(true);
    chass.driveAngle(500, neg(99), 250, _lin, _angBig);
    robot::intake.spin(-127);
    chass.driveAngle(4300, neg(99), 1600, _lin, _ang);
    chass.driveAngle(-800, neg(90), 360, _lin, _ang);
    glb::lvert.set_value(false);
    glb::rhoriz.set_value(false);
    chass.driveAngle(1300, neg(90), 430, _lin, _ang);
    robot::intake.spin(127);
    chass.driveAngle(-400, neg(90), 310, _lin, _ang);
    chass.pidTurn(neg(19), 400, _90);
    chass.driveAngle(1800, neg(19), 500, _lin, _ang);
    glb::lvert.set_value(true);
    chass.driveAngle(1260, neg(97), 600, _lin, _angBig);
    glb::lvert.set_value(false);
    chass.driveAngle(1000, neg(140), 440, _lin, _ang);
    chass.driveAngle(900, 183, 200, _lin, _angBig);
    chass.driveAngle(900, 185, 300, _lin, _ang);

    // chass.driveAngle(-1400, 135, 590, _lin, _ang);
    // chass.pidTurn(45, 240, _90);
    // chass.driveAngle(-1400, 45, 300, _lin, _ang);
    // chass.pidTurn(17, 230, _90);
    // chass.driveAngle(-900, 17, 100, _lin, _ang);
    // robot::wings.toggle();
    // chass.driveAngle(-1000, 6, 190, _lin, _angBig);

    // - get from matchload bar
    // robot::intake.spin(-127);


    // - drive back from matchloads + turn to face
    // chass.driveAngle(-1800, 45, 760, _lin, _ang);
    // chass.driveAngle(-600, 0, 260, _lin, _angBig);

    // - cross the field
    robot::wings.toggle();
    chass.driveAngle(3200, 187 , 1000, _lin, _ang);
    robot::intake.spin(-127);
    // robot::wings.toggle();
    far_half();
}

void skills() {
    pre_matchload();
    matchload();
    post_matchload();
}

void no_matchload() {
    pre_matchload();
    post_matchload();
}
