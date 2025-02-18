#include <string>
#include <iostream>

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

int main() {
    // Initialize class
    AlizaMethods aliza;

    DatabaseNode* node1 = new DatabaseNode(256843154, "Pat", "Emard", "5137 W Chicago Ave", "Chicago", "Illinois", 60651,
        "pemard@hotmail.com", "(773) 379-7548");

    DatabaseNode* node2 = new DatabaseNode(156843154, "Sarah", "Emard", "5137 W Chicago Ave", "Chicago", "Illinois", 60651,
        "semard@hotmail.com", "(773) 379-7548");

    aliza.addNode(node1);
    aliza.addNode(node2);

    std::cout << "\nPrinting database in order:\n";
    aliza.printInOrder(aliza.root);

    return 0;
}
