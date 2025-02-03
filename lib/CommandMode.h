#pragma once

#include "Textinput.h"
#include "FileManager.h"
#include <fstream>
#include <vector>

class VisualMode {
private:
    std::vector<std::string> fileContent;
    std::string currentFile;
    
public:
    void getCommandInput() {
        std::string input;
        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        if (input == "open") {
            openFile();
        } else if (input == "insert") {
            if (!currentFile.empty()) InsertMode(currentFile);
            else std::cout << "No file is open! Use 'open' first.\n";
        } else if (input == "save") {
            saveFile();
        } else if (input == "q") {
            std::cout << "Quitting...\n";
            exit(0);
        } else {
            std::cout << "Invalid command!\n";
        }
    }

    void openFile() {
        std::string filename = FileManager::selectFile();
        if (filename.empty()) return;

        currentFile = filename;
        fileContent.clear();
        
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            fileContent.push_back(line);
        }
        file.close();

        std::cout << "\n--- Editing: " << filename << " ---\n";
        for (const auto& line : fileContent) {
            std::cout << line << std::endl;
        }
        std::cout << "---------------------------------\n";
    }

    void saveFile() {
        if (currentFile.empty()) {
            std::cout << "No file open to save!\n";
            return;
        }

        std::ofstream file(currentFile);
        for (const auto& line : fileContent) {
            file << line << "\n";
        }
        file.close();
        std::cout << "Saved " << currentFile << "\n";
    }
};
