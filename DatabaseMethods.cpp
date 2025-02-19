#include <iostream>
#include <fstream>
#include <string>
#include "AlizaMethods.cpp"
#include <algorithm>
#include <random>
#include <list>

class DatabaseMethods {
    public:
    
        std::list<int> idNums;
        
    
        DatabaseMethods() {
            // Constructor
            
        }
    
        void userMethods(){
            AlizaMethods tree;
            DatabaseMethods db;
            
            while(true) {
                std::cout << "Menu\n";
                std::cout << "1. Add\n";
                std::cout << "2.Delete\n";
                std::cout << "3. Modify\n";
                std::cout << "4. Lookup\n";
                std::cout << "5. List number of records.\n";
                std::cout << "6. Exit\n";
                int choice;
                std::cin >> choice;
    
                switch (choice)
                {
                case 1: // ADD method
                    db.createNode();
                    break;
                
                case 2: // DELETE method
                    std::cout <<"Delete";
                    break;
                case 3: // MODIFY method
                    std::cout <<"modify";
                    break;
                case 4: // LOOKUP method
                    std::cout <<"look up";
                    break;
                case 5: //list number of records
                    //to wrok on
                    std::cout <<"list";
                    break;
                case 6:
                    //ADD write to file
                    std::cout << "Exiting program...\n";
                    break;
    
                default:
                    std::cout << "Invalid choice. Please try again.\n";    
                    break;    
                }//end switch/case
            } //end while loop
    
        } //end userMethods
    
        int generateIdNum() {
            // Generate random ID number
            std::random_device rd;
            std::mt19937 gen(rd());  
            std::uniform_int_distribution<> dist(100000000, 999999999);
            int ID = dist(gen);
            //check if the id is in the list
    
            auto it = std::find(idNums.begin(), idNums.end(), ID);
    
            if (it == idNums.end()) {
                // ID is already in the list
                std::uniform_int_distribution<> dist(100000000, 999999999);
                ID = dist(gen);
            }
    
            return ID;
          
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
            DatabaseMethods db;
        
            int ID = db.generateIdNum(); //generate id num
            std::string firstName;
            std::string lastName;
            std::string address;
            std::string city;
            std::string state;
            int zip = 0;
            std::string email;
            std::string phNum;
        
            std::cout << "Enter first name: \n";
            getline(std::cin, firstName);
            std::cout << "Enter last name: \n";
            getline(std::cin, lastName);
            std::cout << "Enter address: \n";
            getline(std::cin, address);
            std::cout << "Enter city: \n";
            getline(std::cin, city);
            std::cout << "Enter state: \n";
            getline(std::cin, state);
            std::cout << "Enter zipcode: \n";
            std::cin >> zip;
            std::cout << "Enter email: \n";
            std::cin >> email;
            std::cout << "Enter phone number: \n";
            getline(std::cin, phNum);
          
        
            idNums.push_front(ID);
            DatabaseNode contact(ID, firstName, lastName, address, city, state, zip, email, phNum);
            DatabaseNode* ptr = &contact; 
            tree.addNode(ptr);
        }
        
    };