#include <fstream>
#include <iostream>
#include <string>
#include "list.h"

void list() {
    std::ifstream file("src\\Data\\BookData", std::ios::app);
    std::cout << "\nThe following books are currently in the data base :- \n" << std::endl;
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}