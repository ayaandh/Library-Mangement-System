#include "add.h"
#include <fstream>
#include <iostream>

void AddBook() {
    struct BookTemplate {
        std::string name;
        std::string author;
    };

    BookTemplate book;

    std::cout << "Enter the name of the book you want to borrow: ";
    std::cin >> book.name;
    std::cout << "Enter the author's name of the book you want to borrow: ";
    std::cin >> book.author;
    std::ofstream file("src\\Data\\BookData.txt", std::ios::app);
    if (file.is_open()) {
        file << book.name << " : " << book.author << std::endl;
        file.close();
    }
}