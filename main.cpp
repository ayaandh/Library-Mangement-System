#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>

// namespaces

using std::cin;
using std::cout;

//variables

std::vector<std::string> books = {}; 
std::string bookname;
bool bookadded = false; 
std::string name;
std::string password;
std::string log_name;
std::string log_password; 
int opt;
bool bookremoved;
std::string return_book_name;
bool renewing;
std::string renew_book_name;
int tries = 0;
bool cservice;

//functions

void InputChecker();
void book_functions();
void homepage();
void login();
void signup();
void return_func();
void StartupFunctions();
void CustomerSupport();

void InputChecker() {
    cin >> opt; 
    if (opt == 1) {
        bookadded = true;
        bookremoved = false;
        renewing = false;
        cservice = false;
        book_functions();
    } 
    else if (opt == 2) {
        bookremoved = true;
        bookadded = false;
        renewing = false;
        cservice = false;
        book_functions();
    }
    else if (opt == 3) {
        bookadded = false;
        bookremoved = false;
        renewing = true;
        cservice = false;
        book_functions();
    }
    else if (opt == 4) { 
        cout << "Exited Program Successfully\n";
        std::quick_exit(0);
    }
    
    else if (opt == 4) {
        cservice = true;
        book_functions();
    }
}

void homepage() {
    cout << "\n Select an option to start (1-4)\n" << std::endl;
    cout << "1. Borrow Book" << std::endl;
    cout << "2. Return Book" << std::endl;
    cout << "3. Renew Book" << std::endl;
    cout << "4. Exit" << std::endl;
    cout << "5. Cusotmer Support" <<std::endl;
    InputChecker(); 
}

void signup() {
    cout << "===== Sign In =====";
    cout << "Enter your name: ";
    cin >> name;
    cout << "\nChoose a password: ";
    cin >> password;
    cout << "\nWelcome " << name << ", you are now a member of this Library\n" << std::endl;
    
    std::ofstream file("user_data.txt"); 
    if (file.is_open()) {
        file << name << " " << password << "\n"; 
        file.close();
    }
    login();
}    

void login() {
    cout << "Enter your Name: ";
    cin >> log_name;
    cout << "\nEnter your password: ";
    cin >> log_password;
    
    std::ifstream file("user_data.txt"); 
    if (file.is_open()) {
        file >> name >> password; 
        file.close();
    }
    
    if (log_name == name && log_password == password) {
        std::cout << "\nWelcome to the library!\n" << std::endl;
        homepage();
    }
    else {
        tries++;
        if (tries < 5) {    
            cout << "\nWrong username or password. Please try again later\n" << std::endl;
            login(); 
        }
        else {
            std::cout << "Too Many Tries, Session Locked.";
            std::quick_exit(0);
        }
    }
}

void return_func() {
    homepage();
}

void book_functions() {
    if (bookadded && !bookremoved && !renewing) {
        cout << "Enter the name of the book to borrow: ";
        cin >> bookname;
        books.push_back(bookname); 
        cout << "Book added to your borrowed list!\n" << std::endl; 
        return_func();
    }    
    else if (bookremoved && !bookadded && !renewing) {
        cout << "Which book do you want to return?: ";
        cin >> return_book_name;
        auto book = std::find(books.begin(), books.end(), return_book_name);
        if (book != books.end()) {
            books.erase(book);
            cout << "Book returned successfully!\n" << std::endl;
        }
        else {
            cout << "You never borrowed this book.\n" << std::endl;
        }
        return_func();
    }
    else if (renewing) {    
        cout << "Enter the name of the book to renew: ";
        cin >> renew_book_name;
        auto book = std::find(books.begin(), books.end(), renew_book_name);
        if (book != books.end()) {
            books.erase(book);
            books.push_back(renew_book_name);
            cout << "Book renewed successfully!\n" << std::endl;
        }
        else {
            cout << "You never borrowed this book.\n" << std::endl;
        }
        return_func();
    }

    else if (cservice == true) {
        CustomerService():
    }

}

void StartupFunctions() {
    int sign_opt;
    cout << "Select an Option (1-2)\n" << std::endl;
    cout << "1. Log In" << std::endl;
    cout << "2. Sign up\n" << std::endl;
    cin >> sign_opt;
    
    if (sign_opt == 1) {
        login();
    }
    else if (sign_opt == 2) {
        signup();
    }   
    else {
        cout << "Invalid Option. Select an Option from 1-2\n" << std::endl;
    }
}

// Customer Support

void customer_support_intro() {
	std::cout << "Thank you for contacting customer support! you will be contacted soon";
}

void CustomerSupport() {
	customer_support_intro();
}

int main() {
    cout << "================== Library Management System ==================\n" << std::endl;
    StartupFunctions();
    cout << "===============================================================\n" << std::endl;  
    return 0;
}
