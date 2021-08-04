#include <iostream>
#include <vector>
#include <time.h>
#include <unordered_map>

class Clock {

    std::string time_zone;
    std::unordered_map<std::string, std::string> um_timezones;

    public: 
        Clock();

        bool isValid(std::string time);
        std::string getFinalTime();


        // void talk();

        // ~Clock();
};