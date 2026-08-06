#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>

using std::cin;
using std::cout;
using std::string;
using std::vector;

// Variables

vector<string> books;

string bookname;
string name;
string password;

string log_name;
string log_password;

string return_book_name;
string renew_book_name;

int opt;
int tries = 0;


// Functions

void InputChecker();
void book_functions();
void homepage();
void login();
void signup();
void StartupFunctions();
void CustomerSupport();
void ViewBooks();


// Menu Input

void InputChecker()
{
    cin >> opt;
    cin.ignore();

    if (opt == 1)
    {
        book_functions();
    }

    else if (opt == 2)
    {
        return_book_name = "";
        cout << "Which book do you want to return?: ";

        getline(cin, return_book_name);

        auto book = std::find(books.begin(), books.end(), return_book_name);

        if (book != books.end())
        {
            books.erase(book);
            cout << "Book returned successfully!\n";
        }
        else
        {
            cout << "You never borrowed this book.\n";
        }

        homepage();
    }

    else if (opt == 3)
    {
        cout << "Enter book name to renew: ";
        getline(cin, renew_book_name);

        auto book = std::find(books.begin(), books.end(), renew_book_name);

        if (book != books.end())
        {
            cout << "Book renewed successfully!\n";
        }
        else
        {
            cout << "You never borrowed this book.\n";
        }

        homepage();
    }

    else if (opt == 4)
    {
        ViewBooks();
        homepage();
    }

    else if (opt == 5)
    {
        CustomerSupport();
        homepage();
    }

    else if (opt == 6)
    {
        cout << "Exited Program Successfully\n";
        exit(0);
    }

    else
    {
        cout << "Invalid option.\n";
        homepage();
    }
}


// Homepage

void homepage()
{
    cout << "\n==============================\n";
    cout << " Library Management System\n";
    cout << "==============================\n\n";

    cout << "1. Borrow Book\n";
    cout << "2. Return Book\n";
    cout << "3. Renew Book\n";
    cout << "4. View Borrowed Books\n";
    cout << "5. Customer Support\n";
    cout << "6. Exit\n";

    cout << "\nChoose option: ";

    InputChecker();
}


// Signup

void signup()
{
    cout << "\n===== Sign Up =====\n";

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Choose a password: ";
    getline(cin, password);


    std::ofstream file("user_data.txt", std::ios::app);

    if(file.is_open())
    {
        file << name << " " << password << "\n";
        file.close();
    }


    cout << "\nWelcome " << name 
         << ", you are now a library member!\n\n";


    login();
}


// Login

void login()
{
    while(tries < 5)
    {
        cout << "Enter your name: ";
        getline(cin, log_name);

        cout << "Enter your password: ";
        getline(cin, log_password);


        std::ifstream file("user_data.txt");


        string saved_name;
        string saved_password;

        bool found = false;


        while(file >> saved_name >> saved_password)
        {
            if(log_name == saved_name &&
               log_password == saved_password)
            {
                found = true;
                break;
            }
        }


        file.close();


        if(found)
        {
            cout << "\nLogin Successful!\n";
            homepage();
            return;
        }

        else
        {
            tries++;
            cout << "\nWrong username or password.\n";
            cout << "Attempts left: "
                 << 5 - tries << "\n\n";
        }
    }


    cout << "Too many failed attempts. Session locked.\n";
    exit(0);
}


// Borrow / Renew

void book_functions()
{
    cout << "Enter the name of the book to borrow: ";

    getline(cin, bookname);


    books.push_back(bookname);


    cout << "Book borrowed successfully!\n";

    homepage();
}


// View Books

void ViewBooks()
{
    cout << "\n===== Borrowed Books =====\n";


    if(books.empty())
    {
        cout << "No books borrowed.\n";
    }

    else
    {
        for(int i = 0; i < books.size(); i++)
        {
            cout << i + 1 << ". "
                 << books[i] << "\n";
        }
    }

    cout << "\n";
}


// Customer Support

void CustomerSupport()
{
    cout << "\n===== Customer Support =====\n";
    cout << "Thank you for contacting support.\n";
    cout << "A librarian will contact you soon.\n\n";
}


// Startup

void StartupFunctions()
{
    int sign_opt;


    cout << "\n1. Login\n";
    cout << "2. Sign Up\n";

    cout << "Choose option: ";

    cin >> sign_opt;
    cin.ignore();


    if(sign_opt == 1)
    {
        login();
    }

    else if(sign_opt == 2)
    {
        signup();
    }

    else
    {
        cout << "Invalid option.\n";
        StartupFunctions();
    }
}


// Main

int main()
{
    cout << "=================================================\n";
    cout << "       Library Management System\n";
    cout << "=================================================\n";


    StartupFunctions();


    return 0;
}
