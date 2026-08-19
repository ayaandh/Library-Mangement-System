#include "login.h"
#include <iostream>
#include <fstream>
#include <string>
#include "main.h"

void LoginProcess() {
    std::string inputUsername;
    std::string inputPassword;

    std::cout << "Enter username: ";
    std::cin >> inputUsername;
    std::cout << "\nEnter password: ";
    std::cin >> inputPassword;

    std::ifstream file("src\\Data\\UserData.txt");

    if (file.is_open()) {
        std::string fileLine;
        bool loginSuccess = false;

        while (std::getline(file, fileLine)) {
            const size_t delimiterPos = fileLine.find(" : ");

            if (delimiterPos != std::string::npos) {
                std::string savedUsername = fileLine.substr(0, delimiterPos);
                std::string savedPassword = fileLine.substr(delimiterPos + 3);

                if (!savedPassword.empty() && savedPassword.back() == '\r') {
                    savedPassword.pop_back();
                }

                if (inputUsername == savedUsername && inputPassword == savedPassword) {
                    loginSuccess = true;
                    break;
                }
            }
        }
        file.close();

        if (loginSuccess) {
            std::cout << "\nLogin successful! Welcome back," << inputUsername << ".\n";
            StartupProcess();
        } else {
            std::cout << "\nLogin failed. Invalid username or password.\n";
        }
    } else {
        std::cout << "\nError: Could not open database file.\n";
    }
}
