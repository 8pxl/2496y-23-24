#pragma once
#include "../robot.hpp"
#include "constants.hpp"
#include "skills.hpp"

using namespace robot;
using namespace lib;

void touch_near() {
  glb::lhoriz.set_value(true);
  robot::intake.spin(-127);
  chass.driveAngle(2660, neg(77), 300, _lin, _ang);
  glb::lhoriz.set_value(false);
  robot::intake.spin(127);
  chass.driveAngle(2660, neg(77), 700, _lin, _ang, false);
  chass.driveAngle(-200, neg(77), 300, _lin, _ang);
  chass.pidTurn(0, 440, _90);
  glb::lhoriz.set_value(true);
  chass.driveAngle(1200, 0, 600, _lin, _ang);
  glb::lhoriz.set_value(false);
  chass.driveAngle(-2930, neg(55), 1300, _lin, _ang);
  chass.driveAngle(-500, 45, 500, _lin, _ang);
  glb::lvert.set_value(true);
  pros::delay(100);
  chass.pidTurn(neg(30), 400, _45);
  glb::lvert.set_value(false);
  chass.pidTurn(30, 500, _15);
  robot::intake.spin(-127);
  pros::delay(200);
  // robot::wings.setState(true);
  glb::rhoriz.set_value(true);
  // chass.driveAngle(1200, 45, 800, _lin, _ang);
  chass.driveAngle(2040, 0, 1300, _lin, _ang);
}

void greedy_near() {
  touch_near();
  chass.driveAngle(-1600, 0, 800, _lin, _ang);
}

void rush_far() {
  wings.toggle();
  robot::intake.spin(127);
  chass.driveAngle(2700, 80, 300, _lin, _ang);
  wings.toggle();
  chass.driveAngle(2700, 80, 780, _lin, _ang, false);
  chass.driveAngle(-900, 79, 820, _lin, _ang, false);
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
  chass.driveAngle(-650, 100, 300, _lin, _ang);
  robot::wings.setState(false);
  chass.pidTurn(29, 350, _45);
  robot::intake.spin(127);
  chass.driveAngle(2810, 29, 1100, _lin, _ang);
  chass.pidTurn(150, 530, _90);
  chass.driveAngle(2400, 150, 200, _lin, _ang);
  robot::intake.spin(-127);
  chass.driveAngle(2400, 180, 500, _lin, _ang, false);
  chass.driveAngle(-980, 170, 400, _lin, _ang);
  robot::intake.spin(127);
  chass.pidTurn(24, 500, _180);
  chass.driveAngle(800, 24, 400, _lin, _ang);
  chass.driveAngle(-800, 24, 400, _lin, _ang);
  chass.pidTurn(170, 500, _90);
  robot::intake.spin(-127);
  robot::wings.toggle();
  chass.driveAngle(2000, 180, 150, _lin, _ang);
  robot::intake.spin(-127);
  chass.driveAngle(2400, 180, 500, _lin, _ang, false);
  chass.driveAngle(-1200, 180, 500, _lin, _ang, false);
}

void safe_far() {
  glb::lhoriz.set_value(true);
  robot::intake.spin(127);
  glb::rvert.set_value(true);
  pros::delay(150);
  chass.driveAngle(-950, neg(45), 500, _lin, _ang);
  glb::lhoriz.set_value(false);
  glb::rvert.set_value(false);
  chass.driveAngle(600, neg(37), 600, _lin, _ang);
  chass.driveAngle(-800, neg(37), 400, _lin, _ang);
  chass.arcTurn(neg(90), 6.8, 500, -1, _arc, 0, 0);
  chass.timedDrive(600, -100);
  chass.arcTurn(0, 7, 600, -1, _arc, 0, 0);

chass.driveAngle(2960, 29, 1100, _lin, _ang);
  chass.pidTurn(140, 530, _90);
  chass.driveAngle(2400, 140, 300, _lin, _ang);
  robot::intake.spin(-127);
  chass.driveAngle(3100, 180, 600, _lin, _ang, false);
  chass.driveAngle(-1800, 150, 700, _lin, _ang);
  robot::intake.spin(127);
  chass.pidTurn(65, 500, _180);
  chass.driveAngle(800, 75, 300, _lin, _ang);
  chass.driveAngle(500, 90, 300, _lin, _ang);
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
void medic() {
  lib::motorMedic(robot::chassMtrs, 50, 1000, {0, 1, 2, 3, 4, 5, 6});
}

void tank() {
    
}
void test1() {
}

lib::atns autons = {{touch_near, greedy_near, rush_far, safe_far, safe_near, greedy_far, medic, skills, far_half, no_matchload, tank},
                    {"touch_near (greedy)", "greedy_near", "rush_far", "safe_far", "safe_near", "greedy_far", "medic", "skills", "far_half", "no_matchload", "tank"}};