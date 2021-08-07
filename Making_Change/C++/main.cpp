#include <iostream>

int main() {
    int amount;
    int total;

    std::cout << "What is the amount you want to get change for?";
    std::cin >> amount;

    int change[] = {500, 100, 25, 10, 5, 1};
    for (int i : change) {
        total += amount / i;
        amount %= i;
    }

    std::cout << "\n";
    std::cout << total;
}