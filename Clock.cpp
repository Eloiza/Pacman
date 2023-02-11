#include "Clock.hpp"

void Clock::start(){
    this->startTime = std::chrono::system_clock::now();
};

std::chrono::duration<double, std::milli> Clock::end(){
    return (std::chrono::system_clock::now() - this->startTime);
};
