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
        return "ID#" + std::to_string(idNum) + "\nFirst Name: " + firstName + "\nLast Name: " + lastName + 
        "\nAddress: " + address + "\nCity: " + city + "\nState: " + state + "\n Zip Code:" 
        + std::to_string(zip) + "\nEmail: " + email + "\nPhone #: " + phNum +"\n\n";
    }//end toString
};//end class DatabaseNode

class DatabaseMethods {
public:

    std::list<int> idNums;

    DatabaseNode* root = nullptr;

    // In-order traversal: takes in root
    void printInOrder(DatabaseNode* node) {
        if (node == nullptr) {
            return; // Tree is empty
        }//end if statement
        printInOrder(node->left);
        std::cout << node->toString();
        printInOrder(node->right);
    }//end printInOrder

    // Add a node to BST based on ID number
    void addNode(DatabaseNode* newNode) {
        if (root == nullptr) {
            root = newNode;
            std::cout << "Record added successfully.\n";
            std::cout << "Your ID number is: " << newNode->getIdNum() << "\n";
            return;
        }//end if/else

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
            }//end if/else
        }//end while loop

        if (newNode->getIdNum() < parent->getIdNum()) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }//end if/else
        std::cout << "Record added successfully.\n";
        std::cout << "Your ID number is: " << newNode->getIdNum() << "\n";
    }//end addNode
    
    void userMethods(){
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
                createNode();
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
        }//end if statement

        return ID;
    }//end generateIdNum
    
    void readFromFile(){ 
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
                        DatabaseNode* contact = new DatabaseNode(ID, firstName, lastName, address, city, state, zip, email, phNum);
                        std::cout << contact->toString();
                        addNode(contact);  
                    }//end if statements                
                }//end while loop
            }//end while loop
        } else {
            std::cout <<"unable to open file";
        }//end if/else
        ContactsList.close();
    }//end readFromFile
    
    void createNode() {
        int ID = generateIdNum(); //generate id num
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
        addNode(ptr);
    }//end createNode
};//end class DatabaseMethods

//main method
int main() {
    DatabaseMethods db;

    /*DatabaseNode* node1 = new DatabaseNode(256843154, "Pat", "Emard", "5137 W Chicago Ave", "Chicago", "Illinois", 60651,
        "pemard@hotmail.com", "(773) 379-7548");

    DatabaseNode* node2 = new DatabaseNode(156843154, "Sarah", "Emard", "5137 W Chicago Ave", "Chicago", "Illinois", 60651,
        "semard@hotmail.com", "(773) 379-7548");*/

    //db.addNode(node1);
    //db.addNode(node2);
    db.readFromFile(); //add nodes from text file

    std::cout << "\nPrinting database in order:\n";
    db.printInOrder(db.root);

    return 0;
}//end main method
