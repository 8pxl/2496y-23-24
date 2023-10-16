#include "robot.hpp"

using namespace glb;
using namespace robot;


namespace cata {

    constexpr int full = 270                                                      ;
    enum cataState {
        firing,
        reloading,
        half,
        idle,
        toggeled,
    };
    
    cataState state = idle;
    int target;
    double kp = 0.5;

    void calibrate() {
        lib::timer t1;
        while (t1.time() < 1300) {
            robot::cata.spin(-10);
        }
        glb::rot.reset_position();
        pros::delay(300);
        robot::cata.stop('c');
    }

    void cataControl() {
        // std::cout << limit.get_value() << std::endl;
        int angle = rot.get_angle();
        switch (state) {
            case firing:
                if (angle < (full + 10)) {
                    robot::cata.spin(-127);
                }
                else {
                    state = reloading;
                }
                break;

            case reloading:
                if(angle < full || (angle > (full + 10) && angle < 36000)) {
                    if (fmod(angle, full) < full/2) {
                        robot::cata.spin(-127);
                    }
                    else {
                        robot::cata.spin(kp * (full - angle));
                    }
                }
                else {
                    robot::cata.stop('c');
                    state = idle;
                }
                break;

            case idle:
                break;

            case half:
                if(angle < full/2) {
                    robot::cata.spin(-127);
                }
                else {
                    robot::cata.stop('c');
                    state = idle;
                }
                break;

            case toggeled: 
                robot::cata.spin(-127);
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