#include <iostream>
#include <fstream>
#include <string>
#include "AlizaMethods.cpp"
#include <random>
#include <list>

class DatabaseMethods {
    std::list<int> idNums;

    DatabaseMethods() {
        // Constructor
    }

    int generateIdNum() {
        // Generate random ID number
        std::random_device rd;
        std::mt19937 gen(rd());  
        std::uniform_int_distribution<> dist(100000000, 999999999);
        int ID = dist(gen);
        //check if the id is in the list

        auto it = find(idNums.begin(), idNums.end(), ID);
        if (it == idNums.end()) {
            // ID is already in the list
            std::uniform_int_distribution<> dist(100000000, 999999999);
            ID = dist(gen);
        }
      
    }
    
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
       std::string phNum = "null";
       std::string data;
    
       ContactsList.open("Phonebook.txt");
       
       //read from txt file
    
       if(ContactsList.is_open()) {
           
           while (ContactsList.good()) {
            
            while(getline(ContactsList, line)) {
    
                phNum = "null";
    
                if (line.find("ID #") != std::string::npos) {
                    data = line.substr(4);
                    ID = std::stoi(data);
                    //std::cout << ID << std::endl;
                }
                if (line.find("First Name: ") != std::string::npos) {
                    data = line.substr(12);
                    firstName = data;
                    //std::cout << firstName << std::endl;
                }
                if (line.find("Last Name: ") != std::string::npos) {
                    data = line.substr(11);
                    lastName = data;
                    //std::cout << lastName << std::endl;
                }
                if(line.find("Address: ") != std::string::npos) {
                    data = line.substr(9);
                    address = data;
                    //std::cout << address << std::endl;
                }
                if (line.find("City: ") != std::string::npos) {
                    data = line.substr(6);
                    city = data;
                   // std::cout << city << std::endl;
                }
                if (line.find("State: ") != std::string::npos) {
                    data = line.substr(7);
                    state = data;
                    //std::cout << state << std::endl;
                }
                if (line.find("Zip Code: ") != std::string::npos) {
                    data = line.substr(10);
                    zip = std::stoi(data);
                    //std::cout << zip << std::endl;
                }
                if (line.find("Email: ") != std::string::npos) {
                    data = line.substr(7);
                    email = data;
                    //std::cout << email << std::endl;
                }
                if (line.find("Phone #: ") != std::string::npos) {
                    data = line.substr(9);
                    phNum = data;
                    //std::cout << phNum << std::endl;
                }
                if (phNum != "null") { //so that a node will only be created once all the values are saved
                    idNums.push_front(ID); //add IDs to list
                    DatabaseNode contact(ID, firstName, lastName, address, city, state, zip, email, phNum);
                    std::cout << contact.toString();
                    DatabaseNode* contactPtr = &contact;
                    tree.addNode(contactPtr);  
                }                  
            }
        }
    } else {
        std::cout <<"unable to open file";
    }
    ContactsList.close();
    } ; 
    
    void createNode() {
        AlizaMethods tree;
    
        int ID = 3; //generate id num
        std::string firstName;
        std::string lastName;
        std::string address;
        std::string city;
        std::string state;
        int zip = 0;
        std::string email;
        std::string phNum;
    
        std::cout << "Enter first name: ";
        getline(std::cin, firstName);
        std::cout << "Enter last name: ";
        getline(std::cin, lastName);
        std::cout << "Enter address: ";
        getline(std::cin, address);
        std::cout << "Enter city: ";
        getline(std::cin, city);
        std::cout << "Enter state:";
        getline(std::cin, state);
        std::cout << "Enter zipcode:";
        std::cin >> zip;
        std::cout << "Enter email:";
        std::cin >> email;
        std::cout << "Enter phone number:";
        getline(std::cin, phNum);
      
    
        idNums.push_front(ID);
        DatabaseNode contact(ID, firstName, lastName, address, city, state, zip, email, phNum);
        DatabaseNode* ptr = &contact; 
        tree.addNode(ptr);
    }
    
};

