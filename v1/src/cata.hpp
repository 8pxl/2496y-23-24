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
    };
    
    cataState state = idle;
    lib::timer t1;
    lib::timer t2;

    void cataControl() {
        // std::cout << limit.get_value() << std::endl;
        switch (state) {
            case firing:
                if (limit.get_value()) {
                    robot::cata.spin(-127);
                }
                else {
                    t2.reset();
                    state = reloading;
                }
                break;

            case reloading:
                if(!limit.get_value()) {
                    if (t2.time() < 430) {
                        robot::cata.spin(-127);
                    }
                    else {
                        robot::cata.spin(-70);
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