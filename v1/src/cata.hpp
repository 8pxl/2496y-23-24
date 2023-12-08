#include "robot.hpp"

using namespace glb;
using namespace robot;


namespace cata {
    constexpr double halfPos = 17499;
    constexpr double load = 17182;

    enum cataState {
        firing,
        reloading,
        half,
        idle,
        toggeled,
        delayed,
    };
    
    cataState state = idle;
    lib::pid pid({
        .p = 2.8,
        .i = 0, 
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
                double vel = pid.out(error);
                if (vel < 0) {
                    vel = 0;
                }
                robot::cata.spin(vel);
                if(fabs(error) < 20) {
                    state = idle;
                }
                break;

            case idle:
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
                robot::cata.spin(-127);
                break;
            case delayed:
                if (delay.time() < 300) robot::cata.stop('b');
                else {
                    state = reloading;
                    inRange.reset();
                }
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
}