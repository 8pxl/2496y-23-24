#pragma once
#include "../include/keejLib/lib.h"

void lib::chassis::driveAngle(double target, double heading, double timeout, lib::pidConstants lCons, lib::pidConstants acons, bool reset = true, double rushError = -1, double slew = -1)
{
  lib::timer timer;

  double currHeading = imu -> get_heading();
  double sgn = sign(target);
  lib::pid linearController(lCons, target);
  lib::pid angularController(acons,0);
  double linError = target;
  double prev = 0;
  bool run = true;
  if (reset) {
    chass -> reset();
  }

  while (run)
  {
    currHeading = imu -> get_heading();
    double angularError = lib::minError(heading, currHeading);
    linError = target - chass -> getRotation();

    if (std::abs(angularError) < acons.tolerance)
    {
      angularError = 0;
    }
    double va = angularController.out(angularError);
    double vl = linearController.out(linError);
    
    if (std::abs(vl - prev) > slew && slew != -1) {
        vl = prev + (sign(vl - prev) * slew);
    }
    prev = vl;
    
    if (std::abs(linError) > std::abs(rushError) && rushError > 0) {
        vl = 127 * sign(vl);
    }
    // std::cout << chass -> getRotation() << std::endl;

    if (std::abs(vl) + std::abs(va) > 127)
    {
      vl = (127 - std::abs(va)) * sign(vl);
    }
    
    if (rushError > 0 && std::abs(linError) < lCons.tolerance && std::abs(vl) < 20) {
        break;
    }
    
    chass -> spinDiffy(vl - va, vl + va);
    
    run = timer.time() <= timeout;
    if (rushError == 0) {
        run = run && std::abs(linError) > lCons.tolerance;
    }
    pros::delay(10);
  }
  chass -> stop('b');
}

std::vector<double> lib::chassis::pidMTPVel(const lib::point& target, double rotationBias, lib::pid* lCont, lib::pid* rCont)
{
    double linearError = dist(pos,target);
    double currHeading = imu -> get_heading();
    double targetHeading = absoluteAngleToPoint(pos, target);
    double rotationError = lib::minError(targetHeading,currHeading);
    double cre = abs(rotationError) > 90 ? 0.1 : cos(lib::dtr(rotationError));
    double angularVel = rCont -> out(rotationError);
    double linearVel = cre * lCont -> out(linearError);
    double rVel = (linearVel - (fabs(angularVel) * rotationBias)) + angularVel;
    double lVel = (linearVel - (fabs(angularVel) * rotationBias)) - angularVel;
    return(std::vector<double> {rVel, lVel});
}

void lib::chassis::pidMoveTo(const lib::point& target, double timeout, lib::pidConstants lConstants, lib::pidConstants rConstants, double rotationBias)
{
  lib::timer timeoutTimer;
  lib::pid linearController(lConstants, 0);
  lib::pid rotationController(rConstants, 0);

  while (timeoutTimer.time() < timeout) chass -> spinDiffy(lib::chassis::pidMTPVel(target, rotationBias, &linearController, &rotationController));
  chass -> stop('b');
}

void lib::chassis::boomerang(const lib::point& target, double timeout, double dLead, double thetaEnd, double rotationBias, lib::pidConstants lConstants, lib::pidConstants rConstants)
{
  lib::timer timeoutTimer;
  lib::pid linearController(lConstants, 0);
  lib::pid rotationController(rConstants, 0);

  while (timeoutTimer.time() < timeout)
  {
    double h = hypot(pos.x - target.x, pos.y - target.y);
    lib::point carrot = {target.x - (h * sin(thetaEnd) * dLead), target.y - (h * cos(thetaEnd) * dLead)};
    chass -> spinDiffy(lib::chassis::pidMTPVel(carrot, rotationBias, &linearController, &rotationController));
  }
}