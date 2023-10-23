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
    int target;
    double kp = 0.7;
    lib::timer delay;
    lib::timer inRange;

    void calibrate() {
        // lib::timer t1;
        // while (t1.time() < 1600) {
        //     robot::cata.spin(-10);
        // }
        // glb::rot.reset_position();
        // pros::delay(300);
        // robot::cata.stop('c');
    }

    void cataControl() {
        // std::cout << limit.get_value() << std::endl;
        int angle = rot.get_angle();
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
                if (!limit.get_value()) {
                    inRange.reset();
                    double error = abs(lib::minError(load/100, angle/100));
                    std::cout << error << std::endl;
                    if (error > 40) {
                        robot::cata.spin(-127);
                    }
                    else {
                        robot::cata.spin(-48 - (kp * error));
                    }
                }
                else {
                    if (angle > load) {
                        robot::cata.spin(-50);
                        inRange.reset();
                    }
                    else {
                        if (inRange.time() > 230) {
                            robot::cata.stop('c');
                            state = idle;
                        }
                    }
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
                }
                break;
        }
    }

    void halfway() {
        state = half;
    }

    void fire() {
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