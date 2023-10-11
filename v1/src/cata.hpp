#pragma once

#include "keejLib/lib.hpp"
#include "main.h"

namespace cata {
    class cataState {
        public:
            void exit(cata* cata){}
            void enter(cata* cata){}
            void toggle(cata* cata){}
            void run(cata* cata){}
    };

    class cata {
        public:
            lib::mtrs *mtrs;
            pros::ADIDigitalIn *limit;
            cataState *state;
            bool half;
            bool isToggeled;

            cata(lib::mtrs *cataMotors, pros::ADIDigitalIn *limit) : mtrs(cataMotors), limit(limit) {}

            void setState(cataState& newState) {
                state -> exit(this);
                state = &newState;
                state -> enter(this);
            }

            void next() {
                state -> toggle(this);
            }

            void run() {
                state -> run(this);
            }

            void setHalf(bool next) {
                half = next;
            }

            void toggle() {
                isToggeled != isToggeled;
            }
    };

    class cataHalf : public cataState {
        private:
            lib::timer t1;
        public:
        	static cataState& getInstance() {
                static cataReloading singleton;
                return singleton;
            }

            void enter(cata* cata) {
                t1.reset();
            }

            void run(cata* cata) {
                if (t1.time() > 500) {
                    cata -> setState(cataIdle::getInstance());
                }
            }

            void toggle(cata* cata) {
                cata -> setState(cataReloading::getInstance());
            }
    };

    class cataReloading : public cataState {
        public: 
        	static cataState& getInstance() {
                static cataReloading singleton;
                return singleton;
            }

            void enter(cata* cata) {
                cata -> mtrs -> spin(-127);
            }

            void exit(cata* cata) {
                cata -> mtrs -> stop('b');
            }

            void run(cata* cata) {
                if (cata -> limit -> get_value()) {
                    cata -> setState(cataIdle::getInstance());
                }
            }
    };

    class cataIdle : public cataState {
        public:
        	static cataState& getInstance() {
                static cataIdle singleton;
                return singleton;
            }
            
            void enter(cata* cata) {
                cata -> setHalf(true);
                cata -> mtrs -> stop('b'); 
            }

            void toggle(cata* cata) {
                cata -> setState(cataFiring::getInstance());
            }
    };

    class cataFiring : public cataState {
        public:
        	static cataState& getInstance() {
                static cataFiring singleton;
                return singleton;
            }

            void enter(cata* cata) {
                cata -> mtrs -> spin(-127);
            }

            void run(cata* cata) {
                if (!cata -> limit -> get_value() && cata -> isToggeled) {
                    if (cata -> half) {
                        cata -> setState(cataHalf::getInstance());
                    }
                    else {
                        cata -> setHalf(true);
                        cata -> setState(cataReloading::getInstance());
                    }
                }
            }
    };
}