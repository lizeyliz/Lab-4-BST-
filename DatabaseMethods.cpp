#include <iostream>
#include <fstream>
#include <string>
#include "AlizaMethods.cpp"

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
    AlizaMethods tree;

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
            //id
            substring = "ID#";
            if (getline(ContactsList, line)) {
                //if(line.find("ID#") != std::string::npos) { //checks if ID# is there
                ID = std::stoi(line.substr(substring.length(), line.length()));
            } //end of if statements
            
            //first name
            substring = "First Name: ";
            if(getline(ContactsList, line)) {
                //if(line.find("First Name: ") != std::string::npos) {
                firstName = line.substr(substring.length(), line.length());
            } //    end of if statements
            
            //last name
            substring = "Last Name: ";
            if(getline(ContactsList, line)) {
                //if(line.find("Last Name: ") != std::string::npos) {
                lastName = line.substr(substring.length(), line.length());
            } //end of if statements
            
            //address
            substring = "Address: ";
            if(getline(ContactsList, line)) {
                //if(line.find("Address: ") != std::string::npos) {
                address = line.substr(substring.length(), line.length());
            } //end of if statements
            
            //city
            substring = "City: ";
            if(getline(ContactsList, line)) {
                //if(line.find("City: ") != std::string::npos) {
                city = line.substr(substring.length(), line.length());
            } //end of if statements
            
            //state
            substring = "State: ";
            if(getline(ContactsList, line)) {
                //if(line.find("State: ") != std::string::npos) {
                state = line.substr(substring.length(), line.length());
            } //end of if statements
            
            //zipcode
            substring = "Zip Code: ";
            if(getline(ContactsList, line)) { 
                //if(line.find("Zip Code: ") != std::string::npos) {
                zip = std::stoi(line.substr(substring.length(), line.length()));
            } //end of if statements
            
            //email
            substring = "Email: ";
            if(getline(ContactsList, line)) {
                //if(line.find("Email: ") != std::string::npos) {
                email = line.substr(substring.length(), line.length());
            } //end of if statements
            
            //phone number
            substring = "Phone #:";
            if(getline(ContactsList, line)) {
                //if(line.find("Phone #: ") != std::string::npos) {
                phNum = line.substr(substring.length(), line.length());
            } //end of if statements

            DatabaseNode contact(ID, firstName, lastName, address, city, state, zip, email, phNum);
            DatabaseNode* contactPtr = &contact;
            tree.addNode(contactPtr);
            }
        } 
    }      