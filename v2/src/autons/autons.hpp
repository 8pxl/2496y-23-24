#pragma once
#include "../robot.hpp"
#include "constants.hpp"
#include "skills.hpp"

using namespace robot;
using namespace lib;

void center_near_greedy() {
  glb::lhoriz.set_value(true);
  robot::intake.spin(-127);
  chass.driveAngle(2660, neg(77), 300, _lin, _angBig);
  glb::lhoriz.set_value(false);
  robot::intake.spin(127);
  chass.driveAngle(2660, neg(77), 700, _lin, _ang, false);
  chass.driveAngle(2460, neg(77), 300, _lin, _ang, false);
  chass.pidTurn(0, 440, _90);
  glb::lhoriz.set_value(true);
  chass.driveAngle(1200, 0, 600, _lin, _ang);
  glb::lhoriz.set_value(false);
  chass.driveAngle(800, 0, 600, _lin, _ang, false);
  chass.pidTurn(neg(57), 900, _90);
  chass.driveAngle(-2650, neg(57), 1500, _lin, _ang, true, -1, 5);
  // chass.pidTurn(54, 400, _90);
  // chass.driveAngle(-800, 54, 600, _lin, _ang);
  // chass.driveAngle(-500, 45, 500, _lin, _ang, true, -1, 0.2);
  chass.arcTurn(45, 4.1, 1200, 1, _arcSlow);
  glb::lvert.set_value(true);
  chass.driveAngle(300, 45, 500, _lin, _ang, true, -1, 4);
  pros::delay(100);
  chass.pidTurn(neg(30), 400, _45);
  chass.pidTurn(30, 500, _15);
  glb::lvert.set_value(false);
  pros::delay(200);
  glb::rhoriz.set_value(true);
  // robot::wings.setState(true);
  // chass.driveAngle(1200, 45, 800, _lin, _ang);
  chass.driveAngle(880, 30, 900, _lin, _ang);
  chass.pidTurn(0, 500, _15);
  robot::intake.spin(-127);
  chass.driveAngle(1480, 0, 1500, _lin, _ang);
  glb::rhoriz.set_value(false);
}

void greedy_near() {
  center_near_greedy();
  chass.driveAngle(-1600, 0, 800, _lin, _ang);
}

void center_far() {
  glb::rhoriz.set_value(true);
  robot::intake.spin(127);
  chass.driveAngle(2700, 84.5, 70, _lin, _ang);
  glb::rhoriz.set_value(false);
  chass.driveAngle(2700, 84.5, 200, _lin, _ang);
  glb::lhoriz.set_value(true);
  chass.driveAngle(2700, 84.5, 300, _lin, _ang, false);
  glb::lhoriz.set_value(false);
  // wings.toggle();
  chass.driveAngle(2700, 78, 780, _lin, _angBig, false, 400);
  chass.driveAngle(10, 72.5, 1070, _lin, _ang, false, 0);
  robot::intake.spin(-10);
  chass.pidTurn(150, 200, _90);
  robot::intake.spin(-127);
  chass.pidTurn(150, 200, _90);
  chass.pidTurn(0, 500, _90);
  robot::intake.spin( 127);
  chass.driveAngle(1630, 0, 850, _lin, _angBig, 0);
  chass.driveAngle(-100, neg(5), 650, _lin, _angBig, false, 0);
  glb::rvert.set_value(true);
  chass.driveAngle(-1100, neg(45), 400, _lin, _ang);
  chass.pidTurn(neg(130), 250, _90);
  glb::rvert.set_value(false);
  glb::lvert.set_value(true);
  chass.pidTurn(neg(30), 300, _90);
  chass.driveAngle(-600, neg(45), 300, _lin, _ang);
  chass.driveAngle(-700, neg(90), 160, _lin, _ang);
  chass.driveAngle(-3000, neg(90), 500, _lin, _ang);
  chass.driveAngle(400, neg(90), 300, _lin, _ang);
  chass.timedDrive(350, -127);
  glb::lvert.set_value(false);
  chass.driveAngle(660, neg(70), 300, _lin, _ang);
  chass.pidTurn(0, 100, _180);
  robot::intake.spin(0);
  chass.pidTurn(100, 430, _180);
  robot::intake.spin(-127);
  glb::lhoriz.set_value(true);
  pros::delay(150);
  chass.driveAngle(3000, 100, 400, _lin, _ang);
  // chass.driveAngle(-1400, 100, 250, _lin, _ang);
  // chass.timedDrive(500, 127);
  chass.driveAngle(-650, 100, 300, _lin, _ang);
  robot::wings.setState(false);
  chass.pidTurn(29, 330, _45);
  robot::intake.spin(127);
  chass.driveAngle(2810, 29, 1100, _lin, _ang);
  chass.pidTurn(140, 490, _90);
  chass.driveAngle(900, 140, 300, _lin, _ang);
  robot::intake.spin(-127);
  robot::wings.toggle();
  chass.driveAngle(2400, 180, 590, _lin, _ang, false);
  robot::wings.toggle();
  chass.driveAngle(-980, 170, 350, _lin, _ang);
  robot::intake.spin(127);
  chass.pidTurn(24, 480, _180);
  chass.driveAngle(800, 24, 400, _lin, _ang);
  chass.driveAngle(-800, 24, 400, _lin, _ang);
  robot::intake.spin(0);
  chass.pidTurn(170, 500, _90);
  robot::intake.spin(-127);
  robot::wings.toggle();
  chass.driveAngle(2000, 180, 150, _lin, _ang);
  robot::intake.spin(-127);
  chass.driveAngle(2400, 180, 500, _lin, _ang, false);
  chass.driveAngle(-1200, 180, 500, _lin, _ang, false);
}

void barrier_far() {
    glb::rhoriz.set_value(true);
    robot::intake.spin(127);
    chass.driveAngle(3000, 80, 70, _lin, _ang);
    glb::rhoriz.set_value(false);
    chass.driveAngle(3000, 80, 70, _lin, _ang, false);
    glb::lhoriz.set_value(true);
    chass.driveAngle(3000, 80, 160, _lin, _ang, false);
    glb::lhoriz.set_value(false);
    // wings.toggle();
    chass.driveAngle(3000, 46, 1000, _lin, _angBig, false, 400);
    chass.driveAngle(-200, 57, 800, _lin, _ang, false, 0);
  chass.driveAngle(-1300, 90, 300, _lin, _angBig, false);
  chass.pidTurn(150, 200, _90);
  robot::intake.spin(-127);
  chass.pidTurn(150, 200, _90);
  chass.pidTurn(0, 530, _90);
  robot::intake.spin( 127);
  chass.driveAngle(1800, 0, 900, _lin, _ang, 0);
  chass.driveAngle(150, neg(5), 700, _lin, _angBig, false, 0);
  glb::rvert.set_value(true);
  chass.driveAngle(-1630, neg(45), 520, _lin, _ang);
  glb::rvert.set_value(false);
  glb::lvert.set_value(true);
  chass.pidTurn(neg(90), 170, _90);
  chass.pidTurn(neg(45), 170, _90);
  chass.driveAngle(-500, neg(75), 200, _lin, _ang);
  chass.driveAngle(-700, neg(90), 160, _lin, _ang);
  chass.driveAngle(-3000, neg(90), 500, _lin, _ang);
  chass.driveAngle(400, neg(90), 300, _lin, _ang);
  chass.timedDrive(400, -127);
  glb::lvert.set_value(false);
  chass.driveAngle(660, neg(70), 300, _lin, _ang);
  chass.pidTurn(0, 100, _180);
  chass.pidTurn(100, 560, _180);
  glb::lhoriz.set_value(true);
  robot::intake.spin(-127);
  pros::delay(160);
  chass.driveAngle(3000, 100, 600, _lin, _ang);
  chass.driveAngle(-650, 100, 300, _lin, _ang);
  robot::wings.setState(false);
  chass.pidTurn(29, 350, _45);
  robot::intake.spin(127);
  chass.driveAngle(2810, 29, 1000, _lin, _ang);
  chass.driveAngle(1750, 90, 650, _lin, _ang);
  chass.pidTurn(180, 500, _90);
  robot::intake.spin(-127);
  robot::wings.toggle();
  chass.driveAngle(2000, 180, 150, _lin, _ang);
  robot::intake.spin(-127);
  chass.driveAngle(2400, 180, 500, _lin, _ang, false);
  chass.driveAngle(-600, 180, 200, _lin, _ang, false);
  chass.driveAngle(2400, 180, 500, _lin, _ang, false);
  chass.driveAngle(-900, 180, 1200, _lin, _ang, false);
}


void safe_far() {
  glb::lhoriz.set_value(true);
  robot::intake.spin(127);
  glb::lvert.set_value(true);
  pros::delay(150);
  chass.driveAngle(550, 135, 500, _lin, _ang);
  chass.pidTurn(80, 400, _90);
  glb::lvert.set_value(false);
  chass.pidTurn(150, 500, _90);
  intake.spin(-127);
  // chass.driveAngle(600, 90, 600, _lin, _ang);
  // chass.driveAngle(-800, 90, 400, _lin, _ang);
  
  chass.arcTurn(90, 7.5, 500, 1, _arc, 0, 0);
  chass.timedDrive(600, 127);
  chass.driveAngle(-1000, 90, 500, _lin, _ang);
  chass.timedDrive(600, 127);
  glb::lhoriz.set_value(false);
  chass.driveAngle(-600, 110, 300, _lin, _ang);
  chass.driveAngle(-1100, 135, 500, _lin, _ang, false);
  chass.pidTurn(24, 500, _90);

chass.driveAngle(2960, 24, 1100, _lin, _ang);
  chass.pidTurn(140, 530, _90);
  chass.driveAngle(2400, 140, 300, _lin, _ang);
  robot::intake.spin(-127);
  chass.driveAngle(3100, 180, 600, _lin, _ang, false);
  chass.driveAngle(-1800, 150, 700, _lin, _ang);
  robot::intake.spin(127);
  chass.pidTurn(65, 500, _180);
  chass.driveAngle(800, 75, 300, _lin, _ang);
  chass.driveAngle(400, 90, 300, _lin, _ang);
  // chass.driveAngle(-800, 33, 300, _lin, _ang);
  chass.pidTurn(180, 500, _90);
  robot::intake.spin(10);
  robot::wings.toggle();
  chass.driveAngle(2000, 180, 150, _lin, _ang);
  // robot::intake.spin(-127);
  chass.driveAngle(2400, 180, 500, _lin, _ang, false);
  robot::intake.spin(-127);
  chass.driveAngle(-600, 180, 400, _lin, _ang);
  chass.driveAngle(600, 180, 400, _lin, _ang);
  robot::wings.toggle();
  chass.driveAngle(-2000, 180, 500, _lin, _ang);
  chass.pidTurn(neg(80), 400, _90);
  chass.driveAngle(2000, neg(84), 800, _lin, _ang);
  chass.timedDrive(600, 40);
}

void center_near() {
    glb::lhoriz.set_value(true);
    robot::intake.spin(-127);
    chass.driveAngle(2660, neg(77), 300, _lin, _angBig);
    glb::lhoriz.set_value(false);
    robot::intake.spin(127);
    chass.driveAngle(2660, neg(77), 700, _lin, _ang, false);
    // chass.driveAngle(2660, neg(77), 700, _lin, _ang, false);
    // chass.driveAngle(2460, neg(77), 300, _lin, _ang, false);
    // chass.pidTurn(0, 440, _90);
    // glb::lhoriz.set_value(true);
    // chass.driveAngle(1200, 0, 600, _lin, _ang);
    // glb::lhoriz.set_value(false);
    // chass.driveAngle(800, 0, 600, _lin, _ang, false);
    // chass.pidTurn(neg(57), 900, _90);
    chass.driveAngle(400, neg(70), 1500, _lin, _ang, false, -1, 5);
    // chass.pidTurn(54, 400, _90);
    // chass.driveAngle(-800, 54, 600, _lin, _ang);
    // chass.driveAngle(-500, 45, 500, _lin, _ang, true, -1, 0.2);
    chass.arcTurn(45, 4.1, 1200, 1, _arcSlow);
    glb::lvert.set_value(true);
    chass.driveAngle(300, 45, 500, _lin, _ang, true, -1, 4);
    pros::delay(100);
    chass.pidTurn(neg(30), 400, _45);
    chass.pidTurn(30, 500, _15);
    glb::lvert.set_value(false);
    pros::delay(200);
    glb::rhoriz.set_value(true);
    // robot::wings.setState(true);
    // chass.driveAngle(1200, 45, 800, _lin, _ang);
    chass.driveAngle(880, 30, 900, _lin, _ang);
    chass.pidTurn(0, 500, _15);
    robot::intake.spin(-127);
    chass.driveAngle(1450, 0, 1500, _lin, _ang);
    glb::rhoriz.set_value(false);
}

void barrier_near_greedy() {
    glb::lhoriz.set_value(true);
    robot::intake.spin(-127);
    chass.driveAngle(3000, neg(80), 300, _lin, _angBig);
    glb::lhoriz.set_value(false);
    robot::intake.spin(127);
    chass.driveAngle(3000, neg(44), 1100, _lin, _ang, false);
    // glb::lhoriz.set_value(true);
    // chass.driveAngle(-700, 4, 500, _lin, _ang);
    // // chass.driveAngle(-900, neg(45), 500, _lin, _ang);
    // chass.pidTurn(neg(90), 200, _90);
    // chass.pidTurn(180, 260, _90);
    // chass.pidTurn(120, 500, _90);
    // 
}

void barrier_near() {
    glb::lhoriz.set_value(true);
    robot::intake.spin(-127);
    chass.driveAngle(3000, neg(80), 300, _lin, _angBig);
    glb::lhoriz.set_value(false);
    robot::intake.spin(127);
    chass.driveAngle(3000, neg(44), 1000, _lin, _ang, false);
    // glb::lhoriz.set_value(true);
    // chass.driveAngle(-700, 4, 500, _lin, _ang);
    // chass.pidTurn(neg(57), 900, _90);
    chass.driveAngle(-2730, neg(57), 1500, _lin, _ang, true, -1, 5);
    // chass.pidTurn(54, 400, _90);
    // chass.driveAngle(-800, 54, 600, _lin, _ang);
    // chass.driveAngle(-500, 45, 500, _lin, _ang, true, -1, 0.2);
    chass.arcTurn(45, 4.1, 1200, 1, _arcSlow);
    glb::lvert.set_value(true);
    chass.driveAngle(400, 45, 500, _lin, _ang, true, -1, 4);
    chass.pidTurn(neg(30), 400, _45);
    chass.pidTurn(30, 500, _15);
    glb::lvert.set_value(false);
    pros::delay(200);
    glb::rhoriz.set_value(true);
    // robot::wings.setState(true);
    // chass.driveAngle(1200, 45, 800, _lin, _ang);
    chass.driveAngle(880, 30, 900, _lin, _ang);
    chass.pidTurn(0, 500, _15);
    robot::intake.spin(-127);
    chass.driveAngle(1510, 0, 1500, _lin, _ang);
    glb::rhoriz.set_value(false);
}
void safe_near() {
  glb::lhoriz.set_value(true);
  robot::intake.spin(-127);
  chass.driveAngle(2660, neg(77), 300, _lin, _ang);
  glb::lhoriz.set_value(false);
  robot::intake.spin(127);
  chass.driveAngle(2660, neg(77), 700, _lin, _ang, false);
  chass.driveAngle(-100, neg(64), 1200, _lin, _ang, false);
  chass.driveAngle(-500, 45, 500, _lin, _ang);
  glb::lvert.set_value(true);
  pros::delay(100);
  chass.pidTurn(neg(30), 400, _45);
  glb::lvert.set_value(false);
  chass.pidTurn(39, 500, _15);
  robot::intake.spin(-127);
  glb::rhoriz.set_value(true);
  pros::delay(200);
  // robot::wings.setState(true);
  // chass.driveAngle(1200, 45, 800, _lin, _ang);
  chass.driveAngle(2100, 0, 1500, _lin, _ang);
}

void greedy_far() {
  wings.toggle();
  robot::intake.spin(127);
  chass.driveAngle(2700, 40, 300, _lin, _ang);
  wings.toggle();
  chass.driveAngle(2700, 40, 600, _lin, _ang, false);
  chass.pidTurn(180, 400, _135);
  wings.toggle();
  chass.driveAngle(1500, 180, 700, _lin, _ang, false);
  chass.pidTurn(150, 200, _90);
  robot::intake.spin(-127);
  chass.pidTurn(150, 200, _90);
  chass.pidTurn(0, 300, _90);
  robot::intake.spin( 127);
  chass.driveAngle(2180, 0, 950, _lin, _ang);
  chass.driveAngle(0, 0, 700, _lin, _ang, false);
  glb::rvert.set_value(true);
  chass.driveAngle(-1720, neg(45), 470, _lin, _ang);
  glb::rvert.set_value(false);
  glb::lvert.set_value(true);
  chass.pidTurn(neg(90), 170, _90);
  chass.pidTurn(neg(45), 170, _90);
  chass.driveAngle(-500, neg(75), 200, _lin, _ang);
  chass.driveAngle(-700, neg(90), 160, _lin, _ang);
  chass.driveAngle(-3000, neg(90), 500, _lin, _ang);
  chass.driveAngle(400, neg(90), 300, _lin, _ang);
  chass.timedDrive(400, -127);
  glb::lvert.set_value(false);
  chass.driveAngle(660, neg(70), 300, _lin, _ang);
  chass.pidTurn(100, 560, _180);
  glb::lhoriz.set_value(true);
  robot::intake.spin(-127);
  pros::delay(100);
  chass.driveAngle(3000, 100, 600, _lin, _ang);
  chass.driveAngle(-600, 100, 300, _lin, _ang);
  robot::wings.setState(false);
  chass.pidTurn(29, 350, _45);
  robot::intake.spin(127);
  chass.driveAngle(2810, 29, 1100, _lin, _ang);
  chass.pidTurn(150, 530, _90);
  chass.driveAngle(2400, 150, 200, _lin, _ang);
  robot::intake.spin(-127);
  chass.driveAngle(2400, 180, 500, _lin, _ang, false);
  chass.driveAngle(-980, 180, 400, _lin, _ang);
  robot::intake.spin(127);
  chass.pidTurn(24, 500, _180);
  chass.driveAngle(800, 24, 300, _lin, _ang);
  chass.driveAngle(-800, 24, 300, _lin, _ang);
  chass.pidTurn(170, 500, _90);
  robot::intake.spin(-127);
  robot::wings.toggle();
  chass.driveAngle(2000, 180, 150, _lin, _ang);
  robot::intake.spin(-127);
  chass.driveAngle(2400, 180, 500, _lin, _ang, false);
  chass.driveAngle(-1200, 180, 500, _lin, _ang, false);
}

void wing_far() {
    glb::lhoriz.set_value(true);
    chass.driveAngle(-2000, neg(114), 200, _lin, _ang, true, 300);
    glb::lhoriz.set_value(false);
    chass.driveAngle(-2000, neg(114), 1300, _lin, _ang, false, 300);
    glb::lvert.set_value(true);
    chass.pidTurn(40, 560, _90);
    glb::lvert.set_value(false);
    robot::intake.spin(127);
    chass.driveAngle(900, 40, 500, _lin, _ang);
    
    chass.driveAngle(-3100, 50, 400, _lin, _ang, true);
    chass.driveAngle(-3100, 85, 750, _lin, _ang, false);
    chass.pidTurn(150, 200, _90);
    robot::intake.spin(-127);
    chass.pidTurn(150, 200, _90);
    chass.pidTurn(0, 380, _90);
    robot::intake.spin( 127);
    chass.driveAngle(1900, 0, 950, _lin, _ang);
    chass.driveAngle(40, neg(2), 700, _lin, _ang, false);
    glb::rvert.set_value(true);
    chass.driveAngle(-1720, neg(45), 470, _lin, _ang);
    glb::rvert.set_value(false);
    glb::lvert.set_value(true);
    chass.pidTurn(neg(90), 170, _90);
    chass.pidTurn(neg(45), 170, _90);
    chass.driveAngle(-500, neg(75), 200, _lin, _ang);
    chass.driveAngle(-700, neg(90), 160, _lin, _ang);
    chass.driveAngle(-3000, neg(90), 500, _lin, _ang);
    chass.driveAngle(400, neg(90), 300, _lin, _ang);
    chass.timedDrive(400, -127);
    glb::lvert.set_value(false);
    chass.driveAngle(660, neg(70), 300, _lin, _ang);
    chass.pidTurn(100, 560, _180);
    glb::lhoriz.set_value(true);
    robot::intake.spin(-127);
    pros::delay(100);
    chass.driveAngle(3000, 100, 600, _lin, _ang);
    chass.driveAngle(-650, 100, 300, _lin, _ang);
    robot::wings.setState(false);
    chass.pidTurn(29, 350, _45);
    robot::intake.spin(127);
    chass.driveAngle(2810, 29, 1100, _lin, _ang);
    chass.driveAngle(1600, 90, 600, _lin, _ang);
    chass.pidTurn(180, 500, _180);
    robot::wings.toggle();
    robot::intake.spin(-127);
    chass.driveAngle(2000, 180, 800, _lin, _ang);
    chass.driveAngle(-1000, 180, 800, _lin, _ang);
    
    
}
void medic() {
  lib::motorMedic(robot::chassMtrs, 50, 1000, {0, 1, 2, 3, 4, 5, 6});
}

void tank() {
    
}
void test1() {
}

lib::atns autons = {{center_near_greedy, greedy_near, center_near, barrier_near, barrier_near_greedy, barrier_far, center_far, safe_far, safe_near, greedy_far, medic, end, skills, far_half, wing_far, no_matchload, tank},
                    {"center_near_greedy", "greedy_near", "center_near", "barrier_near", "barrier_near_greedy", "barrier_far", "center_far", "safe_far", "safe_near", "greedy_far", "medic", "hang", "skills", "far_half", "wing_far", "no_matchload", "tank"}};