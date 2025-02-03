#include "CommandMode.h"

int main() {
    VisualMode editor;
    std::cout << "Welcome to Termo Editor!\n";

    while (true) {
        editor.getCommandInput();
    }

    return 0;
}
