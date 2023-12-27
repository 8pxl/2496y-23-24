#include "robot.hpp"

using namespace glb;
using namespace robot;


namespace cata {
    constexpr double halfPos = 21717;
    constexpr double load = 21717;

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
        .p = 2.8,
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
                inRange.reset();
                if (limit.get_value()) {
                    robot::cata.spin(-127);
                }
                else {
                    delay.reset();
                    state = delayed;
                }
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
                robot::cata.spin(-103);
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
}