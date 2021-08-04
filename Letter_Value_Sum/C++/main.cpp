#include <iostream>

int main() {

    std::string str = "";
    bool isValid = false;
    int total = 0;
    std::locale loc;

    while (!isValid) {
        std::cout << "Enter a string (no special characters. only letters): ";
        std::cin >> str;
        std::cout << "\n";

        isValid = true;

        transform(str.begin(), str.end(), str.begin(), ::tolower);
        for (std::string::iterator it=str.begin(); it!= str.end(); ++it) {


            total += int(*it);
            if (!std::isalpha(*it, loc)) {
                isValid = false;
                total = 0;
                break;
            }
        }
    }

    total -= 96*str.length();
    std::cout << total;


}