#pragma once

#include <iostream>
#include <fstream>
#include "../lib/Member.h"

class OutputHandler {
    private:
    OutputHandler() = delete;
    ~OutputHandler() = delete;
    OutputHandler(const OutputHandler&) = delete;
    OutputHandler& operator=(const OutputHandler&) = delete;

    public:

    static void printToFile(const std::string& filePath) {
        std::ofstream outputFile(filePath);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening file for writing: " << filePath << std::endl;
            return;
        }

        printAssignments(outputFile);
        outputFile.close();
    }

    static void printToStdout() {
        printAssignments();
    }

    private:
    static void printAssignments(std::ostream& outputStream = std::cout) {
        std::string tag;
        for(const auto& [hrMember, assignedMembers] : MemberManager::getHRAssignments()) {
            outputStream << hrMember.getFullName()<< ":" << std::endl;
            for(const auto& member : assignedMembers) {
                if(!(tag = member.getTag()).empty()) tag = " (" + tag + ")";
                outputStream << "  - " << member.getFullName() << tag << std::endl;
            }
            outputStream << std::endl; // Add an empty line between HR members
        }
    }
};