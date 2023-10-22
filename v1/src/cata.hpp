#include "robot.hpp"

using namespace glb;
using namespace robot;

namespace cata {

    enum cataState {
        firing,
        reloading,
        half,
        idle,
        toggeled,
        delayed,
    };
    
    cataState state = idle;
    lib::timer t1;
    lib::timer t2;
    lib::timer delay;

    void cataControl() {
        // std::cout << limit.get_value() << std::endl;
        switch (state) {
            case firing:
                if (limit.get_value()) {
                    robot::cata.spin(-127);
                }
                else {
                    t2.reset();
                    delay.reset();
                    state = delayed;
                }
                break;

            case reloading:
                std::cout << robot::cata.getEfficiency() << std::endl;
                if(!limit.get_value()) {
                    // if (t2.time() < 430) {
                        robot::cata.spin(-127);
                    // }
                    // else {
                    //     robot::cata.spin(-70);
                    // }
                }
                else {
                    robot::cata.stop('c');
                    state = idle;
                }
                break;

            case idle:
                break;

            case half:
                if (limit.get_value()) {
                    t1.reset();
                }
                if (t1.time() < 450) {
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
        t1.reset();
        state = half;
    }

    void fire() {
        t2.reset();
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