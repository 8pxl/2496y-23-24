#pragma once
#include "../include/keejLib/lib.h"

<<<<<<< HEAD
std::vector<double> lib::chassis::asymTrapezoidalProfile(double dist, double maxSpeed, double accel, double decel, double start, double end)
{
  double a = ((1 / (2*accel)) + (1 / (2*decel)));
  double c1= (-pow(start, 2) / (2*accel)) - (pow(end, 2) / (2*decel));
  double c = c1 - dist;
  double max = std::min((2 * std::sqrt(-a*c) / 2*a), maxSpeed);
  double accelTime = (max-start) / accel;
  double decelTime = (max-end) / decel;
  double coastDist = dist - (a * pow(max, 2)) - c1;
  double coastTime = coastDist / max;
  double totalTime = accelTime + decelTime + coastTime;
  double vel = 0;
  double diff;
  std::vector<double> profile;
  for (int i = 0; i < std::ceil(totalTime); i++)
  {
    if (i < std::floor(accelTime))
=======
std::vector<double> lib::chassis::asymTrapezoidalProfile(double dist, double maxSpeed, double accel, double decel, double start = 0, double end = 0)
{
  if (start == 0 && end == 0) {
    double max = std::min(std::sqrt((2 * accel * decel * dist) / accel + decel), maxSpeed);
    double accelTime = max / accel;
    double decelTime = max / decel;
    double coastDist = (dist / max) - (max / (2 * accel)) - (max / (2*decel));
    double coastTime = coastDist / max;
    double totalTime = accelTime + decelTime + coastTime;
    double vel = 0;
    double diff;
    std::vector<double> profile;
    for (int i = 0; i < std::ceil(totalTime); i++)
>>>>>>> main
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
  else {
    start /= linear.velToVolt;
    end /= linear.velToVolt;
    double a = ((1 / (2*accel)) + (1 / (2*decel)));
    double c1= (-pow(start, 2) / (2*accel)) - (pow(end, 2) / (2*decel));
    double c = c1 - dist;
    double max = std::min((std::sqrt(-a*c) / a), maxSpeed);
    double accelTime = (max-start) / accel;
    double decelTime = (max-end) / decel;
    double coastDist = dist - (a * pow(max, 2)) - c1;
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
<<<<<<< HEAD
  return profile;
} 

// void lib::chassis::profiledDrive(double target, int endDelay = 500, double start = 0, double end = 0)
// {
//   //kv: rpm -> voltage
//   //sf: in/ms -> rpm
//   int sign = lib::sign(target);
//   target = fabs(target);
//   std::vector<double> profile;
//   start /= linear.velToVolt;
//   end /= linear.velToVolt; 
//   // std::cout << "reached 1" << std::endl;
//   if(sign > 0) profile = asymTrapezoidalProfile(target, linear.maxSpeed, linear.fwdAccel, linear.fwdDecel, start, end);
//   else profile = asymTrapezoidalProfile(target, linear.maxSpeed, linear.revAccel, linear.revDecel, start, end);
//   chass -> reset();
//   for (int i = 0; i < profile.size(); i++)
//   {
//     chass -> spin(profile[i] * linear.velToVolt * sign);
//     pros::delay(10);
//   }
//   chass -> stop('b');
//   pros::delay(endDelay);
// }


// std::vector<double> lib::chassis::asymTrapezoidalProfile(double dist, double maxSpeed, double accel, double decel)
// {
//   double max = std::min(std::sqrt((2 * accel * decel * dist) / accel + decel), maxSpeed);
//   double accelTime = max / accel;
//   double decelTime = max / decel;
//   double coastDist = (dist / max) - (max / (2 * accel)) - (max / (2*decel));
//   double coastTime = coastDist / max;
//   double totalTime = accelTime + decelTime + coastTime;
//   double vel = 0;
//   double diff;
//   std::vector<double> profile;
//   for (int i = 0; i < std::ceil(totalTime); i++)
//   {
//     if (i < std::floor(accelTime))
//     {
//       profile.push_back(vel);
//       vel += accel;
//     }

//     else if (i < coastTime + accelTime)
//     {
//       profile.push_back(max);
//     }

//     else
//     {
//       profile.push_back(vel);
//       vel -= decel;
//     }
//   }
//   return profile;
// }

// void lib::chassis::profiledDrive(double target, int endDelay = 500)
// {
//   //kv: rpm -> voltage
//   //sf: in/ms -> rpm
//   int sign = lib::sign(target);
//   target = fabs(target);
//   std::vector<double> profile;
//   // std::cout << "reached 1" << std::endl;
//   if(sign > 0) profile = asymTrapezoidalProfile(target, linear.maxSpeed, linear.fwdAccel, linear.fwdDecel);
//   else profile = asymTrapezoidalProfile(target, linear.maxSpeed, linear.revAccel, linear.revDecel);
//   chass -> reset();
//   for (int i = 0; i < profile.size(); i++)
//   {
//     chass -> spin(profile[i] * linear.velToVolt * sign);
//     pros::delay(10);
//   }
//   chass -> stop('b');
//   pros::delay(endDelay);
// }


=======
}

>>>>>>> main
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
  // chass -> stop('b');
  pros::delay(endDelay);
}

<<<<<<< HEAD
void lib::chassis::profiledTurn(double target, int endDelay = 500)
{
  //kv: rpm -> voltage
  //sf: in/ms -> rpm
  double error = lib::minError(target, imu -> get_heading());
  int dir = lib::sign(error);
  double amt = lib::dtr(std::abs(error));
  double rot = constants.vertTrack * amt;
  std::vector<double> profile = asymTrapezoidalProfile(amt, linear.maxSpeed, linear.fwdAccel,  linear.fwdDecel, 0, 0);
=======
// void lib::chassis::profiledTurn(double target, int dir, int endDelay = 500)
// {
//   //kv: rpm -> voltage
//   //sf: in/ms -> rpm
//   std::vector<double> profile = asymTrapezoidalProfile(target, angular.maxSpeed, angular.fwdAccel,  angular.fwdDecel, 0,0);
//   chass -> reset();
//   std::cout << profile.size() << std::endl;
//   for (int i = 0; i < profile.size(); i++)
//   {
//     double vel = profile[i] * angular.velToVolt * dir;
//     chass -> spinDiffy(vel, -vel);
//     pros::delay(10);
//   }
//   chass -> stop('b');
//   pros::delay(endDelay);
// }

void lib::chassis::profiledTurn(double target, int dir, int endDelay = 500)
{
  //kv: rpm -> voltage
  //sf: in/ms -> rpma
  // double error = lib::minError(target, imu -> get_heading());
  double error = target;
  dir = lib::sign(error);
  double amt = lib::dtr(std::abs(error));
  double rot = constants.horizTrack * amt;
  std::vector<double> profile = asymTrapezoidalProfile(rot, linear.maxSpeed, linear.fwdAccel, linear.fwdDecel, 0, 0);
>>>>>>> main
  chass -> reset();
  double prev = 0;
  for (int i = 0; i < profile.size(); i++)
  {
<<<<<<< HEAD
    double vel = profile[i] * linear.velToVolt * dir;
=======
    // double currVel = chass -> getSpeed(true);
    // std::cout << (profile[i] - linear.rpmToVel * currVel) << std::endl;
    // double vel = (dir * profile[i] * linear.kv) + (linear.ka * (profile[i] - prev)) + (linear.kp * (profile[i] - (currVel - prevVel)));
    // double vel = ((dir * profile[i] * linear.kv) + (linear.ka * (profile[i]-prev)) + (linear.kp * ((profile[i] - linear.rpmToVel * currVel))));
    double vel = profile[i] * linear.velToVolt;
    // prev = profile[i];
>>>>>>> main
    chass -> spinDiffy(vel, -vel);
    pros::delay(10);
  }
  chass -> stop('b');
  pros::delay(endDelay);
}

void lib::chassis::timedDrive(int time, int speed) {
  lib::timer t1;
  while(t1.time() < time) {
    chass -> spin(speed);
    pros::delay(10);
  }
  chass -> stop('b');
<<<<<<< HEAD
}
=======
}
>>>>>>> main
