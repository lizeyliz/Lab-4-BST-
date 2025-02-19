#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include <list>

class DatabaseNode {
    private:
    //instance variables
    int idNum; //9 digit
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    int zip;
    std::string email;
    std::string phNum;

    public:
    //pointing to left and right
    DatabaseNode *left, *right;
    //constructor
    DatabaseNode(int idNum, std::string firstName, std::string lastName, std::string address, 
    std::string city, std::string state, int zip, std::string email, std::string phNum){
        this->idNum = idNum;
        this->firstName = firstName;
        this->lastName = lastName;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->email = email;
        this->phNum = phNum;
        //pointing to left and right
        this-> left = this->right = NULL;
    }//end constructor

    //getters and setters
    int getIdNum(){
        return idNum;
    }
    void setIdNum(int idNum){
        this->idNum = idNum;
    }
    std::string getFirstName(){
        return firstName;
    }
    void setFirstName(std::string firstName){
        this->firstName = firstName;
    }
    std::string getLastName(){
        return lastName;
    }
    void setLastName(std::string lastName){
        this->lastName = lastName;
    }
    std::string getAddress(){
        return address;
    }
    void setAddress(std::string address){
        this->address = address;
    }
    std::string getCity(){
        return city;
    }
    void setCity(std::string city){
        this->city = city;
    }
    std::string getState(){
        return state;
    }
    void setState(std::string state){
        this->state = state;
    }
    int getZip(){
        return zip;
    }
    void setZip(int zip){
        this->zip = zip;
    }
    std::string getEmail(){
        return email;
    }
    void setEmail(std::string email){
        this->email = email;
    }
    std::string getPhNum(){
        return phNum;
    }
    void setPhNum(std::string phNum){
        this->phNum = phNum;
    }
 //to string (may change later)
    std::string toString(){
        return std::to_string(idNum) + " " + firstName + " " + lastName + " " + address + " " + city + " " + state + " " + std::to_string(zip) + " " + email + " " + phNum +"\n";
    }
};


class AlizaMethods {
public:
    DatabaseNode* root;

    // Constructor
    AlizaMethods() {
        root = nullptr;
    }

    // Destructor to prevent memory leaks
    ~AlizaMethods() {
        deleteTree(root);
    }

    void deleteTree(DatabaseNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;  // Free memory
    }

    // In-order traversal: takes in root
    void printInOrder(DatabaseNode* node) {
        if (node == nullptr) {
            return; // Tree is empty
        }
        printInOrder(node->left);
        std::cout << node->toString();
        printInOrder(node->right);
    }

    // Add a node to BST based on ID number
    void addNode(DatabaseNode* newNode) {
        if (root == nullptr) {
            root = newNode;
            std::cout << "Record added successfully.\n";
            std::cout << "Your ID number is: " << newNode->getIdNum() << "\n";
            return;
        }

        DatabaseNode* current = root;
        DatabaseNode* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (newNode->getIdNum() < current->getIdNum()) {
                current = current->left;  // Move left
            } else if (newNode->getIdNum() > current->getIdNum()) {
                current = current->right; // Move right
            } else { // Duplicate node
                std::cout << "Node is a duplicate and cannot be placed.\n";
                return;
            }
        }

        if (newNode->getIdNum() < parent->getIdNum()) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        std::cout << "Record added successfully.\n";
        std::cout << "Your ID number is: " << newNode->getIdNum() << "\n";
    }
};

class DatabaseMethods {
public:

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

int main() {
    // Initialize class
    AlizaMethods aliza;
    DatabaseMethods db;

    DatabaseNode* node1 = new DatabaseNode(256843154, "Pat", "Emard", "5137 W Chicago Ave", "Chicago", "Illinois", 60651,
        "pemard@hotmail.com", "(773) 379-7548");

    DatabaseNode* node2 = new DatabaseNode(156843154, "Sarah", "Emard", "5137 W Chicago Ave", "Chicago", "Illinois", 60651,
        "semard@hotmail.com", "(773) 379-7548");

    aliza.addNode(node1);
    aliza.addNode(node2);

    db.createNode();
    

    std::cout << "\nPrinting database in order:\n";
    aliza.printInOrder(aliza.root);

    return 0;
}
