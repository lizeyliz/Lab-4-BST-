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
        
    }
};