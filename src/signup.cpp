#include <iostream>
#include <fstream>
#include "signup.h"

using std::cout;
using std::endl;
using std::cin;

void signupProcess(bool &running) {
    std::string username;
    std::string password;
    std::string ConfirmedPassword;
    while (running) {
        cout << "Pick a username: ";
        cin >> username;
        cout << "\n" << "Pick a Password: ";
        cin >> password;
        cout << "\n" << "Confirm Password: ";
        cin >> ConfirmedPassword;
        if (password == ConfirmedPassword) {
            cout << "Password accepted, new user created\n";

            std::ofstream file("src\\Data\\UserData.txt", std::ios::app);

            if (file.is_open()) {
                file << "\n" <<  username << " : " << password;
                file.close();
            }
            else if (!file.is_open()) {
                cout << "User creation failed\n";
            }
            running = false;
        } else {
            cout << "Password does not match.\n";
            running = true;
        }
    }
}