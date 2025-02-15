#include <iostream>
#include <fstream>
#include <string>
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

//reads the stuff from the file, puts them into the binary tree
void readFromFile(){ 
     //used for the output of the tx file

    std::fstream ContactsList;
    std::string line;
    std::string substring;
    int ID;
    std::string firstName;
    std::string lastName; 
    std::string address;
    std::string city;
    std::string state;
    int zip;
    std::string email;
    std::string phNum;

    

    ContactsList.open("Phonebook.txt");
    
    //read from txt file

    if(ContactsList.is_open()) {
        
        while (ContactsList) {
            while (getline(ContactsList, line)) {
                //id
                if(line.find("ID#") != std::string::npos) { //checks if ID# is there
                    substring = "ID#";
                    ID = std::stoi(line.substr(substring.length(), line.length()));
                }
                //first name
                if(line.find("First Name: ") != std::string::npos) {
                    substring = "First Name: ";
                    firstName = line.substr(substring.length(), line.length());
                }
                //last name
                if(line.find("Last Name: ") != std::string::npos) {
                    substring = "Last Name: ";
                    lastName = line.substr(substring.length(), line.length());
                }
                //address
                if(line.find("Address: ") != std::string::npos) {
                    substring = "Address: ";
                    address = line.substr(substring.length(), line.length());
                }
                //city
                if(line.find("City: ") != std::string::npos) {
                    substring = "City: ";
                    city = line.substr(substring.length(), line.length());
                }
                //state
                if(line.find("State: ") != std::string::npos) {
                    substring = "State: ";
                    state = line.substr(substring.length(), line.length());
                }
                //zip 
                if(line.find("Zip: ") != std::string::npos) {
                    substring = "Zip: ";
                    zip = std::stoi(line.substr(substring.length(), line.length()));
                }
                //email
                if(line.find("Email: ") != std::string::npos) {
                    substring = "Email:";
                    email = line.substr(substring.length(), line.length());
                }
                //phone number
                if(line.find("Phone #: ") != std::string::npos) {
                    substring = "Phone Number:";
                    phNum = line.substr(substring.length(), line.length());
                }
            }

        } 
       
    }
        
}


int main() {
    readFromFile();
    return 0;
}