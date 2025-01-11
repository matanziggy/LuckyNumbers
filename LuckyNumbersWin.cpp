#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For system("cls")

void clearAndMoveToTop() {
    system("cls"); // Clear the screen
}

void generateAndDisplayNumbers() {
    int num1 = std::rand() % 37 + 1;
    int num2 = std::rand() % 37 + 1;
    int num3 = std::rand() % 37 + 1;
    int num4 = std::rand() % 37 + 1;
    int num5 = std::rand() % 37 + 1;
    int num6 = std::rand() % 37 + 1;
    int num7 = std::rand() % 7 + 1;

    std::cout << num1 << " " << num2 << " " << num3 << " "
              << num4 << " " << num5 << " " << num6 << ", "
              << num7 << std::endl;
}

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    while (true) {
        generateAndDisplayNumbers();

        // Wait for a key press
        while (!_kbhit()); // Wait until a key is pressed
        int key = _getch(); // Get the key pressed

        if (key == 27) { // 27 is the ASCII code for Esc
            break; // Exit the loop
        }
    }

    return 0;
}
