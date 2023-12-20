#pragma once
#include "main.h"
#include "../include/keejLib/lib.h"
namespace lib {
    
    void lib::scheduler::run() {
        auto it = upper_bound(tasks.begin(), tasks.end(), pros::millis(), [](const uint32_t a, const task &b) {
            return (b.start < a);
        });

        if (it != tasks.end()) {
            uint32_t time = pros::millis();
            for(auto q = tasks.begin(); q != it; q++) {
                task t = *q;
                t.task();
            }
        }
    }

    void lib::scheduler::add(fptr item, int start) {
        task t = {item, start + (int) pros::millis()};
        tasks.insert(t);
    }

    void lib::scheduler::init() {
        mainTask = new pros::Task {[=] {
            while (true) {
                run();
                pros::delay(10);
            }
        }};
    }
}