#include "../lib/InputHandler.h"
#include <iostream>
#include <fstream>
#include <string>

void InputHandler::processInput(std::istream& inputStream) {
    std::string line, tag, fullName;
    while (std::getline(inputStream, line, '\n')) {
        std::cerr << "Processing line: `" << line << '`'<< std::endl;

        if (line.empty()) {
            std::cerr << "Skipping empty line" << std::endl;
            continue; // Skip empty lines
        }

        if (line[1] == ' ') {
            tag = line[0];
            fullName = line.substr(2);
        } else {
            fullName = line;
        }

        MemberManager::addMember(tag, fullName);
        tag.clear();
        fullName.clear();
    }
}

void InputHandler::handleFileInput(std::string filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    processInput(inputFile);
    inputFile.close();
}

void InputHandler::handleStdinInput() {
    processInput(std::cin);
}