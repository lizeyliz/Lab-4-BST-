#include <iostream>
#include "DatabaseNode.cpp"

void createNode() {

    int ID = 3;
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    int zip = 0;
    std::string email;
    std::string phNum;

    std::cout << "Enter first name:";
    std::cin >> firstName;
    std::cout << "Enter last name:";
    std::cin >> lastName;
    std::cout << "Enter address:";
    std::cin >> address;
    std::cout << "Enter city:";
    std::cin >> city;
    std::cout << "Enter state:";
    std::cin >> state;
    std::cout << "Enter zipcode:";
    std::cin >> zip;
    std::cout << "Enter email:";
    std::cin >> email;
    std::cout << "Enter phone number:";
    std::cin >> phNum;

    DatabaseNode test(ID, firstName, lastName, address, city, state, zip, email, phNum);

    
}