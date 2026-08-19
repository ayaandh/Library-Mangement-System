#include <iostream>
#include "signup.h"
#include "login.h"
#include "add.h"
#include "list.h"
#include "main.h"

int option;
bool running = true;

void InputChecker();

void StartupProcess() {
    std::cout << "Select on of the following option (1 - 5)\n" << std::endl;
    std::cout << "1. Signup\n";
    std::cout << "2. Login\n";
    std::cout << "3. Add Book\n";
    std::cout << "4. List Books\n";
    std::cout << "5. Exit\n" << std::endl;
    std::cout << ">> ";
    std::cin >> option;
    std::cout << "\n" << std::endl;
    InputChecker();
}

void InputChecker() {
    if (option > 0 && option < 5) {
        if (option == 1) {
            signupProcess(running);
        }
        else if (option == 2) {
            LoginProcess();
        }
        else if (option == 3) {
            AddBook();
        }
        else if (option == 4) {
            list();
        }
        else {
            std::cout << "Invalid option. Please try again." << std::endl;
            StartupProcess();
        }
    }
}
int main() {
    while (running) {
        StartupProcess();
        if (option == 5) {
            running = false;
        }
    }
    return 0;
}
