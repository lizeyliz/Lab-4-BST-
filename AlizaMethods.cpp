#include "DatabaseNode.cpp"
#include <iostream>
class AlizaMethods {
    DatabaseNode* root = nullptr;
        //puts all contact nodes from the tree into the txt file
    //needs inorderArray method first
    /*void writeToFile() {
    //put contact nodes from tree into array (inorder)
    DatabaseNode[] contactArray = inorderArray(root);

    }*/
    public:
    ////iterative inorder traversal, returns array of nodes inorder
    /*DatabaseNode* inorderArray(DatabaseNode root) {

    }//end inorderArray*/

    //inorder traversal: takes in root
    void printInOrder(DatabaseNode* node){
        if(node == nullptr){
            return; //tree is empty
        }//end if statement

        //left tree
        printInOrder(node->left);
        //print the current node
        std::cout << node->toString();
        //right tree
        printInOrder(node->right);
    }//end printInOrder

    //add a node to BST based on id number
    void addNode(DatabaseNode* newNode) {
        //if tree is empty
        if(root == nullptr) {
            root = newNode;
            std::cout << "Record added successfully.";
            std::cout << "Your ID number is: " + newNode->getIdNum();
            return;
        }//end if statement

        //starting from the top
        DatabaseNode* current = root;
        DatabaseNode* parent = nullptr;

        //while loop for placement if the tree is not empty
        while(current != nullptr) {
            parent = current;
            if(newNode->getIdNum() < current->getIdNum()) {
                current = current->left; //move left
            } else if (newNode->getIdNum() > current->getIdNum()){
                current = current->right; //move right
            } else {//duplicate node
                std::cout << "Node is a duplicate and cannot be placed.";
                return;
            }//end if/else
        }//end while loop

        //insert the new node in the correct position
        if(newNode->getIdNum() < parent->getIdNum()){
            parent->left = newNode;//set as left child
        } else {
            parent->right = newNode; //set as right child
        }//end if/else
        std::cout << "Record added successfully.";
        std::cout << "Your ID number is: " + newNode->getIdNum();
    }//end addNode
};//end class AlizaMethods
