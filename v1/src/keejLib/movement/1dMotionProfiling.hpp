#pragma once
#include "../include/keejLib/lib.h"

std::vector<double> lib::chassis::asymTrapezoidalProfile(double dist, double maxSpeed, double accel, double decel, double start, double end)
{
  double a = (1/2*accel + 1/2*decel);
  double c1= -pow(start, 2)/2*accel - pow(end, 2)/2*decel;
  double c = c1 - dist;
  double max = std::min(std::sqrt((2 * accel * decel * dist) / accel + decel), maxSpeed);
  double accelTime = (max-start) / accel;
  double decelTime = (max-end) / decel;
  double coastDist = dist - (a * pow(max,2)) - c1;
  double coastTime = coastDist / max;
  double totalTime = accelTime + decelTime + coastTime;
  double vel = 0;
  double diff;
  std::vector<double> profile;
  for (int i = 0; i < std::ceil(totalTime); i++)
  {
    if (i < std::floor(accelTime))
    {
      profile.push_back(vel);
      vel += accel;
    }

    else if (i < coastTime + accelTime)
    {
      profile.push_back(max);
    }

    else
    {
      profile.push_back(vel);
      vel -= decel;
    }
  }
  return profile;
}

void lib::chassis::profiledDrive(double target, int endDelay = 500, double start = 0, double end = 0)
{
  //kv: rpm -> voltage
  //sf: in/ms -> rpm
  int sign = lib::sign(target);
  target = fabs(target);
  std::vector<double> profile;
  // std::cout << "reached 1" << std::endl;
  if(sign > 0) profile = asymTrapezoidalProfile(target, linear.maxSpeed, linear.fwdAccel, linear.fwdDecel, start, end);
  else profile = asymTrapezoidalProfile(target, linear.maxSpeed, linear.revAccel, linear.revDecel, start, end);
  chass -> reset();
  for (int i = 0; i < profile.size(); i++)
  {
    chass -> spin(profile[i] * linear.velToVolt * sign);
    pros::delay(10);
  }
  chass -> stop('b');
  pros::delay(endDelay);
}

void lib::chassis::profiledTurn(double target, int endDelay = 500, double start = 0, double end = 0)
{
  //kv: rpm -> voltage
  //sf: in/ms -> rpm
  double error = lib::minError(target, imu -> get_heading());
  int dir = lib::sign(error);
  double amt = lib::dtr(std::abs(error));
  double rot = constants.trackDia * amt;
  std::vector<double> profile = asymTrapezoidalProfile(amt, linear.maxSpeed, linear.fwdAccel,  linear.fwdDecel, start, end);
  chass -> reset();
  std::cout << profile.size() << std::endl;
  for (int i = 0; i < profile.size(); i++)
  {
    double vel = profile[i] * linear.velToVolt * dir;
    chass -> spinDiffy(vel, -vel);
    pros::delay(10);
  }
  chass -> stop('b');
  pros::delay(endDelay);
}