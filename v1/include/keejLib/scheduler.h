#pragma once
#include "util.h"

namespace lib {    
    class scheduler {
        private: 
            struct task {
                fptr task;
                int start;
            };

            struct cmp {
                bool operator()(const task &a, const task &b) const{
                    return a.start < b.start;
                };
            };
            pros::Task* mainTask = nullptr;
            // bool cmp = [](const task &a, const task &b) {return a.start < b.start;};
            std::multiset<task, cmp> tasks; 
            //create a new function 
        public:
            scheduler(){};
            void run();
            void add(fptr task, int start);
            void init();
    };
}
