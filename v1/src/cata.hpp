#include "robot.hpp"

using namespace glb;
using namespace robot;


namespace cata {
    constexpr double halfPos = 17499;
    constexpr double load = 17300;

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
        .p = 0.5,
        .i = 0, 
        .d = 0, 
        .tolerance = 0.05, 
        .integralThreshold = 1.1, 
        .maxIntegral = 20
    }, 0);
    lib::timer delay;
    lib::timer inRange; 
    double target = load;

    void cataControl() {
        // std::cout << limit.get_value() << std::endl;
        int angle = rot.get_angle();
        double error = abs(lib::minError(target/100, angle/100));
        // std::cout << angle << std::endl;
        switch (state) {
            case firing:
                if (limit.get_value()) {
                    robot::cata.spin(-127);
                }
                else {
                    delay.reset();
                    state = delayed;
                }
                break;

            case reloading:
                if (inRange.time() > 300) {
                    robot::cata.stop('b');
                    state = idle;
                }
                if (!limit.get_value() && !fabs(pid.getDerivative()) < 5) {
                    inRange.reset();
                }
                if (error > target/2) {
                    robot::cata.spin(-127);
                }
                else {
                    robot::cata.spin(-40 - pid.out(error));
                }

                // if (!limit.get_value()) {
                //     inRange.reset();
                //     double error = abs(lib::minError(load/100, angle/100));
                //     std::cout << error << std::endl;
                    // if (error > 40) {
                    //     robot::cata.spin(-127);
                    // }
                    // else {
                    //     robot::cata.spin(-48 - (kp * error));
                    // }
                // }
                // else {
                //     if (angle > load) {
                //         robot::cata.spin(-50);
                //         inRange.reset();
                //     }
                //     else {
                //         if (inRange.time() > 230) {
                //             robot::cata.stop('c');
                //             state = idle;
                //         }
                //     }
                // }
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