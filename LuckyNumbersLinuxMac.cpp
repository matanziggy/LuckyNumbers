#include <iostream>
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include <unistd.h>

// Function to clear the screen and move the cursor to the top
void clearAndMoveToTop() {
    std::cout << "\033[2J\033[H"; // ANSI escape codes to clear screen and move cursor to top
}

// Function to get key press without waiting (non-blocking input)
char getKeyPress() {
    struct termios oldt, newt;
    int ch;
    
    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    newt.c_cc[VMIN] = 1; // Minimum number of characters to read
    newt.c_cc[VTIME] = 0; // No timeout
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new terminal settings

    ch = getchar(); // Get character
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal settings

    return ch; // Return the key pressed
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

        char key = getKeyPress(); // Get key press

        if (key == 27) { // 27 is the ASCII code for Esc
            break; // Exit the loop
        }
    }

    return 0;
}
