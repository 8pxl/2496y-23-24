#pragma once
using namespace lib;
using namespace robot;
#define neg(a) 360-a

pidConstants _180 {
    .p = 5.9,
    .i = 0.6,
    .d = 70,
    .tolerance = 0.05,
    .integralThreshold = 1.1,
    .maxIntegral = 20
};

pidConstants _135 {
    .p = 6.3,
    .i = 0.43,
    .d = 59,
    .tolerance = 0.01,
    .integralThreshold = 1,
    .maxIntegral = 100
};


pidConstants _90 {
    .p = 6.3,
    .i = 0.43,
    .d = 59,
    .tolerance = 0.01,
    .integralThreshold = 1,
    .maxIntegral = 100
};

pidConstants _45 {
    .p = 4.9,
    .i = 0.4,
    .d = 26,
    .tolerance = 0.01,
    .integralThreshold = 1.1,
    .maxIntegral = 100
};

pidConstants _30 {
    .p = 5.9,
    .i = 0.6,
    .d = 70,
    .tolerance = 0.05,
    .integralThreshold = 1.1,
    .maxIntegral = 20
};

pidConstants _15 {
    .p = 4.9,
    .i = 0.4,
    .d = 26,
    .tolerance = 0.01,
    .integralThreshold = 1.1,
    .maxIntegral = 100
};

pidConstants _5 {
    .p = 4.9,
    .i = 0.4,
    .d = 26,
    .tolerance = 0.01,
    .integralThreshold = 1.1,
    .maxIntegral = 100
};

pidConstants _arc {
    .p = 1.7,
    .i = 0.2,
    .d = 2,
    .tolerance = 0,
    .integralThreshold = 3,
    .maxIntegral = 100
};

pidConstants _arcSlow {
    .p = 1.2,
    .i = 0.2,
    .d = 2,
    .tolerance = 0,
    .integralThreshold = 3,
    .maxIntegral = 100
};

pidConstants _eul {
    .p = 1,
    .i = 0,
    .d = 0,
    .tolerance = 0,
    .integralThreshold = 3,
    .maxIntegral = 100
};

pidConstants _eulF {
    .p = 1.5,
    .i = 0,
    .d = 0,
    .tolerance = 0,
    .integralThreshold = 3,
    .maxIntegral = 100
};


pidConstants _lin {
    .p = 0.13,
    .i = 0,
    .d = 0,
    .tolerance = 40,
    .integralThreshold = 0,
    .maxIntegral = 0
};

pidConstants _ang {
    .p = 1.4,
    .i = 0,
    .d = 0,
    .tolerance = 0,
    .integralThreshold = 0,
    .maxIntegral = 0
};

pidConstants _angBig {
    .p = 2.5,
    .i = 0,
    .d = 0,
    .tolerance = 0,
    .integralThreshold = 0,
    .maxIntegral = 0
};
