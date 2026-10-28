#include "lib/InputHandler.h"
#include "lib/Member.h"
#include "lib/OutputHandler.h"

int main(int argc, char* argv[]) {
    if (argc > 1) {
        InputHandler::handleFileInput(argv[1]);
    } else {
        InputHandler::handleStdinInput();
    }

    MemberManager::assignHRMembers();

    if(argc > 2) {
        OutputHandler::printToFile(argv[2]);
    } else {
        OutputHandler::printToStdout();
    }

    return 0;
}
