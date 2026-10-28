#pragma once

#include "Member.h"
#include <string>
#include <vector>

class InputHandler {
    private:
    static void processInput(std::istream& inputStream);

    public:
    static void handleFileInput(std::string filePath);
    static void handleStdinInput();

};