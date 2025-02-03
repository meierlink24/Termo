#pragma once

#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class FileManager {
public:
    static std::string selectFile() {
        std::vector<std::string> files;
        std::cout << "\nAvailable files in directory:\n";

        // List all files in the current directory
        for (const auto& entry : fs::directory_iterator(".")) {
            if (entry.is_regular_file()) {
                files.push_back(entry.path().filename().string());
                std::cout << files.size() << ". " << entry.path().filename().string() << "\n";
            }
        }

        if (files.empty()) {
            std::cout << "No files found! Create a new one.\n";
            return "";
        }

        std::cout << "Enter file number or name: ";
        std::string input;
        std::getline(std::cin, input);

        // If input is a number, select by index
        if (isdigit(input[0])) {
            int index = std::stoi(input) - 1;
            if (index >= 0 && index < files.size()) {
                return files[index];
            }
        } 
        // Otherwise, assume it's a filename
        else if (fs::exists(input)) {
            return input;
        }

        std::cout << "Invalid file selection!\n";
        return "";
    }
};
