#include <iostream>
#include "clock.hpp"

int main() {

    Clock talking_clock; 
    std::string time;

    //Gets valid time
    while (!talking_clock.isValid(time)) {
        std::cout << "Enter timezone: ";
        std::cin >> time;
        std::cout << "\n";
    }
    std::string final_time = talking_clock.getFinalTime();
    
}