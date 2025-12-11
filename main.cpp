#include <iostream>
using namespace std;

void showHelp() {
    cout << "Basic Commands:\n";
    cout << "  help               Show this help message\n";
    cout << "  exit               Exit the program\n";
}

int main() {
    string command;

    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║         📁 C++ FILE MANAGER          ║\n";
    cout << "╚══════════════════════════════════════╝\n";

    while (true) {
        cout << endl;
        cout << "> ";
        getline(cin, command);

        if (command == "help") {
            showHelp();
        } else if (command == "exit") {
            break;
        }
    }

    return 0;
}