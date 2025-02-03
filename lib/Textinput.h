#pragma once

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>

char getChar() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void InsertMode(std::string filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::vector<std::string> buffer;
    std::string line;
    int cursorX = 0;
    
    std::cout << "Insert Mode (ESC to exit, Arrows to move, Backspace to delete)\n";

    while (true) {
        char ch = getChar();

        if (ch == 27) { // ESC key
            break;
        }

        if (ch == '\n') { // Enter key
            buffer.push_back(line);
            file << line << std::endl;
            std::cout << std::endl;
            line.clear();
            cursorX = 0;
        } else if (ch == 127) { // Backspace key
            if (cursorX > 0) {
                line.erase(cursorX - 1, 1);
                cursorX--;
                std::cout << "\b \b"; // Move cursor back and clear character
            }
        } else if (ch == '\033') { // Arrow key detection (multi-byte sequence)
            getChar(); // Skip '['
            switch (getChar()) {
                case 'D': // Left arrow
                    if (cursorX > 0) {
                        cursorX--;
                        std::cout << "\b";
                    }
                    break;
                case 'C': // Right arrow
                    if (cursorX < line.size()) {
                        std::cout << line[cursorX];
                        cursorX++;
                    }
                    break;
                case 'A': // Up arrow (optional: move between lines)
                case 'B': // Down arrow (optional)
                    break;
            }
        } else {
            line.insert(line.begin() + cursorX, ch);
            cursorX++;
            std::cout << ch;
        }
    }

    file.close();
    std::cout << "\nExited Insert Mode.\n";
}
