#include "robot.hpp"

using namespace glb;
using namespace robot;


namespace cata {
    constexpr double halfPos = 25681;
    constexpr double load = 25681;
    pros::Task* cataTask = nullptr;

    enum cataState {
        firing,
        reloading,
        half,
        idle,
        toggeled,
        delayed,
        off
    };
    
    cataState state = idle;
    lib::pid pid({
        .p = 2.2,
        .i = 0.4, 
        .d = 0, 
        .tolerance = 0.05, 
        .integralThreshold = 15, 
        .maxIntegral = 20
    }, 0);
    lib::timer delay;
    lib::timer inRange; 
    double target = load;

    void cataControl() {    
        // std::cout << limit.get_value() << std::endl;
        double angle = rot.get_angle();
        double error = lib::minError(target/100.0, angle/100.0);
        std::cout << error << std::endl;
        double vel;
        switch (state) {
            case firing:
                if (inRange.time() > 375) {
                    state = off;
                }
                robot::cata.spin(-127);
                break;

            case reloading:
                // std::cout << "reloading" << std::endl;
                // std::cout << inRange.time() << std::endl;
                if(fabs(error) < 20) {
                    state = idle;
                }
                else {
                    vel = pid.out(error);
                    if (vel < 0) {
                        vel = 127;
                    }
                    robot::cata.spin(-vel);
                }
                break;

            case idle:
                if (error < 0) {
                    state = reloading;
                }
                break;

            case half:
                if(angle < load/2) {
                    robot::cata.spin(-127);
                }
                else {
                    robot::cata.stop('c');
                    state = idle;
                }
                break;

            case toggeled: 
                robot::cata.spin(-121);
                break;
                
            case off:
                robot::cata.stop('c');
                break;
        }
    }

    void halfway() {
        // state = half;
        target = halfPos;
        state = reloading;
    }

    void fire() {
        inRange.reset();
        target = load;
        state = firing;
    }

    void toggle() {
        if (state == toggeled) {
            state = reloading;
        }
        else {
            state = toggeled;
        }
    }

    void cut() {
        if(state == off) {
            state = reloading;
        }
        else {
            state = off;
        }
    }

    void init() {
        cataTask = new pros::Task{[=]{
            while(true) {
                cataControl();
                pros::delay(20);
            }
        }};
    }
}