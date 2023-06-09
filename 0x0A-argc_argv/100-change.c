#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error" << std::endl;
        return (1);
    }

    int cents = std::atoi(argv[1]);

    if (cents < 0) {
        std::cout << 0 << std::endl;
        return (0);
    }

    int coinCount = 0;

    // Calculate the number of coins required
    while (cents > 0) {
        if (cents >= 25) {
            cents -= 25;
        } else if (cents >= 10) {
            cents -= 10;
        } else if (cents >= 5) {
            cents -= 5;
        } else if (cents >= 2) {
            cents -= 2;
        } else {
            cents -= 1;
        }

        coinCount++;
    }

    std::cout << coinCount << std::endl;
    return (0);
}
