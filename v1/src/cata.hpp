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
    
    cataState state;
    lib::timer t1;

    void cataControl() {
        switch (state) {
            case firing:
                if (limit.get_value()) {
                    robot::cata.spin(-127);
                }
                else {
                    state = reloading;
                }
                break;

            case reloading:
                if(!limit.get_value()) {
                    robot::cata.spin(-127);
                }
                else {
                    robot::cata.stop('c');
                    state = idle;
                }
                break;

            case idle:
                break;

            case half:
                if (t1.time() < 500) {
                    robot::cata.spin(-127);
                }
                else {
                    robot::cata.stop('c');
                    state = idle;
                }

            case toggeled: 
                robot::cata.spin(-127);
        }
    }

    void halfway() {
        t1.reset();
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