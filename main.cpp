#include <iostream>
#include <filesystem>
using namespace std;

void showHelp() {
    cout << "Basic Commands:\n";
    cout << "  help               Show this help message\n";
    cout << "  exit               Exit the program\n";
    cout << "\nFile Operations:\n";
    cout << "  list               List directory contents\n";
    cout << "  SOON: info <file>        Show file information\n";
    cout << "  SOON: create <file>      Create a new file\n";
    cout << "  SOON: delete <file>      Delete a file\n";
    cout << "  SOON: copy <src> <dst>   Copy file\n";
    cout << "  SOON: move <src> <dst>   Move/rename file\n";
    cout << "\nNavigation:\n";
    cout << "  SOON: cd <path>          Change directory\n";
    cout << "  SOON: pwd                Print working directory\n";
}

void listDirectory(const string& path = ".") {
    for (const auto& entry : filesystem::directory_iterator(path)) {
        if (filesystem::is_directory(entry.status())) {
            cout << entry.path().filename() << " [DIR]" << endl;
        } else {
            cout << entry.path().filename() << " [FILE]" << endl;
        }
    }
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
        } else if (command == "list") {
            listDirectory();
        }
    }

    return 0;
}