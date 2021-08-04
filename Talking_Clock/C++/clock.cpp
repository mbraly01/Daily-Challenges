#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <unordered_map>
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "clock.hpp"

Clock::Clock() {

    std::ifstream file("/Users/mattbraly/Documents/Summer/Daily_Challenges/Talking_Clock/C++/TimeZones.csv");
    if(!file.is_open()) throw std::runtime_error("Could not open file");

    std::string line;
    std::unordered_map<std::string, std::string> umap;
    if(file.good()) {
        while( std::getline (file, line)) {

            std::vector<std::string> line_split;
            std::stringstream ss(line);

            while (ss.good()) {
                std::string substr;
                std::getline(ss, substr, ',');
                line_split.push_back(substr);
            }
            umap[line_split[0]] = line_split[2];
        }
    }
    this->um_timezones = umap;
}

bool Clock::isValid(std::string time) {

    int len = time.size();
    char b;

    for (int i = 0; i < len; i ++) {
        b = time[i];
        b = toupper(b);
        time[i] = b;
    }

    if (um_timezones.find(time) != um_timezones.end()) {
        time_zone = um_timezones[time].substr(0, um_timezones[time].find(' '));
        this->time_zone = um_timezones[time];
        return true;
    }
    else {
        return false;
    }
}

std::string Clock::getFinalTime() {

    std::string final_time = "";
    std::string am_pm = "AM";
    time_t now;
    struct tm * ptm;
    char buffer[10];
    time ( &now );
    ptm = gmtime ( &now );
    strftime(buffer, sizeof(buffer), "%H:%M", ptm);
    std::string str(buffer);
    std::stringstream ss_hour(time_zone.substr(1,3));
    int hour = 0;
    ss_hour >> hour;
    if (time_zone[0] == '-') {
        hour *= -1;
    }
    int gmt_hour = 0;
    std::stringstream ss_gmt_hour(str.substr(0,2));
    ss_gmt_hour >> gmt_hour;
    int min = 0;

    std::stringstream ss_gmt_min(str.substr(str.find(":") + 1, str.length()));
    int gmt_min = 0;
    ss_gmt_min >> gmt_min;
    if (time_zone.find(":") < time_zone.length()) {
        std::stringstream ss_min(time_zone.substr(time_zone.find(":"), time_zone.length() -1));
        ss_min >> min;
        
        if (hour < 0) {
            gmt_min -= min;
        }
        else {
            gmt_min += min;
        }
        if (gmt_min < 0) {
            gmt_hour -= 1;
            gmt_min += 60;
        }
        else if (gmt_min > 59) {
            gmt_hour += 1;
            gmt_min -= 60;
        }
    }
    gmt_hour += hour;
    if (gmt_hour < 0 ) {
        gmt_hour += 24;
    }

    if (gmt_hour > 11) {
        gmt_hour -= 12;
        am_pm = "PM";
    }
    if (gmt_hour == 0) {
        final_time += "twelve ";
    }
    else if (gmt_hour == 1) {
        final_time += "one ";
    }
    else if (gmt_hour == 2) {
        final_time += "two ";
    }
    else if (gmt_hour == 3) {
        final_time += "three ";
    }
    else if (gmt_hour == 4) {
        final_time += "four ";
    }
    else if (gmt_hour == 5) {
        final_time += "five ";
    }
    else if (gmt_hour == 6) {
        final_time += "six ";
    }
    else if (gmt_hour == 7) {
        final_time += "seven ";
    }
    else if (gmt_hour == 8) {
        final_time += "eight ";
    }
    else if (gmt_hour == 9) {
        final_time += "nine ";
    }
    else if (gmt_hour == 10) {
        final_time += "ten ";
    }
    else if (gmt_hour == 11) {
        final_time += "eleven ";
    }
    if (gmt_min < 10 || gmt_min > 19) {
        if (gmt_min / 10 == 0) {
            final_time += "o ";
        }
        else if (gmt_min / 10 == 2) {
            final_time += "twenty ";
        }
        else if (gmt_min / 10 == 3) {
            final_time += "thirty ";
        }
        else if (gmt_min / 10 == 4) {
            final_time += "forty ";
        }
        else if (gmt_min / 10 == 5) {
            final_time += "fifty" ;
        }
    }
    if (gmt_min == 10) {
        final_time += "ten ";
    }
    else if (gmt_min == 11) {
        final_time += "eleven";
    }
    else if (gmt_min == 12) {
        final_time += "twelve ";
    }
    else if (gmt_min == 13) {
        final_time += "thirteen ";
    }
    else if (gmt_min % 10 == 1) {
        final_time += "one ";
    }
    else if (gmt_min % 10 == 2) {
        final_time += "two ";
    }
    else if (gmt_min % 10 == 3) {
        final_time += "three ";
    }
    else if (gmt_min % 10 == 4) {
        final_time += "four ";
    }
    else if (gmt_min % 10 == 5) {
        final_time += "five ";
    }
    else if (gmt_min % 10 == 6) {
        final_time += "six ";
    }
    else if (gmt_min % 10 == 7) {
        final_time += "seven ";
    }
    else if (gmt_min % 10 == 8) {
        final_time += "eight ";
    }
    else if (gmt_min % 10 == 9) {
        final_time += "nine ";
    }
    final_time += am_pm;
    return final_time;
    
}


