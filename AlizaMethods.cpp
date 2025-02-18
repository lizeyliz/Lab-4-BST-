#include <string>
#include <iostream>

class DatabaseNode {
public:
    int idNum;
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    int zip;
    std::string email;
    std::string phone;
    DatabaseNode* left;
    DatabaseNode* right;

    DatabaseNode(int id, std::string fName, std::string lName, std::string addr, std::string c, std::string s, int z, std::string e, std::string p)
        : idNum(id), firstName(fName), lastName(lName), address(addr), city(c), state(s), zip(z), email(e), phone(p), left(nullptr), right(nullptr) {}

    int getIdNum() {
        return idNum;
    }

    std::string toString() {
        return firstName + " " + lastName + ", " + address + ", " + city + ", " + state + " " + std::to_string(zip) + ", " + email + ", " + phone + "\n";
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
