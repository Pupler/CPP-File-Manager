#include <iostream>
#include <filesystem>
using namespace std;

void showHeader() {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║         📁 C++ FILE MANAGER          ║\n";
    cout << "╚══════════════════════════════════════╝\n";
}

void showHelp() {
    cout << "Basic Commands:\n";
    cout << "  help               Show this help message\n";
    cout << "  exit               Exit the program\n";
    cout << "  clear              Clear console\n";
    cout << "\nFile Operations:\n";
    cout << "  list [path]              List directory contents\n";
    cout << "  SOON: info <file>        Show file information\n";
    cout << "  SOON: create <file>      Create a new file\n";
    cout << "  SOON: delete <file>      Delete a file\n";
    cout << "  SOON: copy <src> <dst>   Copy file\n";
    cout << "  SOON: move <src> <dst>   Move/rename file\n";
    cout << "\nNavigation:\n";
    cout << "  SOON: cd <path>          Change directory\n";
    cout << "  SOON: pwd                Print working directory\n";
}

void listDirectory(string& command) {
    try {
        if (command.length() > 5) {
            string path = command.substr(5);
            for (const auto& entry : filesystem::directory_iterator(path)) {
                if (filesystem::is_directory(entry.status())) {
                    cout << entry.path().filename() << " [DIR]" << endl;
                } else {
                    cout << entry.path().filename() << " [FILE]" << endl;
                }
            }
        } else {
            cout << "Error: path is empty!" << endl;
        }
    } catch(...) {
        cout << "Error: path doesn't exist" << endl;
    }
}

int main() {
    string command;

    showHeader();

    while (true) {
        cout << endl;
        cout << "> ";
        getline(cin, command);

        if (command == "help") {
            showHelp();
        } else if (command == "exit") {
            break;
        } else if (command == "list" || command.rfind("list ", 0) == 0) {
            listDirectory(command);
        } else if (command == "clear") {
            system("clear");
            showHeader();
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}