#pragma once
#include "../include/keejLib/lib.h"

namespace lib {
    void motorMedic(mtrs& motors, int voltage, int time, std::vector<int> indexes) {
        timer t;
        for (int i: indexes) {
            t.reset();
            while (t.time() <= time) {
                motors.spin(i, voltage);
                double vel = motors.getSpeed(i);  
                std::cout << i << " " << motors.getPort(i) << " " << vel << std::endl;
                pros::delay(80);
            }
            motors.stop('c');
        }
    }
}