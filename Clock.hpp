#ifndef CLOCK_HPP 
#define CLOCK_HPP

#include <chrono>

class Clock{
    public:
        void start();
        std::chrono::duration<double, std::milli> end();
    private:
        std::chrono::_V2::system_clock::time_point startTime;
};
#endif