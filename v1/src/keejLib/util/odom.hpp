#pragma once
#include "../include/keejLib/lib.h"

void lib::chassis::updatePos()
{
  if (odom == odomType::threeEncoder)
  {
    double currRotation = imu -> get_heading();
    double deltaRotation = lib::minError(prevRotation, currRotation);

    prevRotation = currRotation;

    deltaRotation = lib::dtr(deltaRotation);
    currRotation = lib::dtr(currRotation);

    double deltaVert = (constants.trackDia / 360) * vertTracker -> get_value();
    double deltaHoriz = (constants.trackDia / 360) * horizTracker -> get_value();
    double deltaY, deltaX, localX, localY, pAngle, pRadius;

    if (deltaRotation == 0)
    {
      localX = deltaHoriz;
      localY = deltaVert;
    }

    else
    {
      localX = (2 * sin(deltaRotation / 2)) * ((deltaHoriz / deltaRotation) + constants.horizTrack);
      localY = (2 * sin(deltaRotation / 2)) * ((deltaVert / deltaRotation) + constants.vertTrack);
    }

    if (localX == 0 && localY == 0)
    {
      pAngle = 0;
      pRadius = 0;
    } 

    else 
    {
      pAngle = atan2(localY, localX); 
      pRadius = hypot(localX, localY);
    }

    pAngle = pAngle - lib::dtr(prevRotation) - (deltaRotation / 2);
    deltaX = pRadius * cos(pAngle);
    deltaY = pRadius * sin(pAngle);

    pos = {pos.x + deltaX, pos.y + deltaY};

    // reset encoders
    horizTracker -> reset();
    vertTracker -> reset();
  }

  // else if (odom == odomType::twoIME) 
  // {
  //       let deltaRotation = (d.1 - d.0) / (self.robotSize);
  //       self.heading += deltaRotation;
  //       if deltaRotation == 0.0 {
  //           self.position.0  -= (PI/2.0 + self.heading).cos() * d.1;
  //           self.position.1 -= (PI/2.0 + self.heading).sin() * d.1;
  //       }
  //       else {
  //           let r = d.0 / deltaRotation + self.robotSize / 2.0;
  //           let relativeY = 2.0 * (deltaRotation / 2.0).sin() * r;
  //           let rotationOffset = self.heading + (deltaRotation / 2.0);
  //           let theta = PI / 2.0 + rotationOffset;
  //           let radius = relativeY;
  //           self.position.0 -= radius * theta.cos();
  //           self.position.1 -= radius * theta.sin();
  //       }
  // }
}

void lib::chassis::initTracking()
{
  odomTask = new pros::Task {[=] 
  {
    while (true) 
    {
      updatePos();
      pros::delay(10);
    }
  }};
}