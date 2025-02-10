import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class DatabaseMethods {

    DatabaseNode root; // top of tree
    ArrayList<Integer> listIDs = new ArrayList<>(); // stores all IDs
    //public ArrayList<DatabaseNode> contactInfoList = new ArrayList<>(); //stores all the nodes to avoid overwritting
    Scanner scanner = new Scanner(System.in);

    public DatabaseMethods() {
        this.root = null;
    }// end constructor

    public DatabaseNode getRoot() {
        return root;
    }//end getRoot

    //UNTESTED (test with print statements)
    //iterative inorder traversal, returns array of nodes inorder
    public DatabaseNode[] inorderArray(DatabaseNode root) {
        //initialize array to store nodes (size of tree)
        DatabaseNode[] treeArray = new DatabaseNode[countRecords(root)];
        int index = 0;//start at beginning of array
        if (root == null) { //tree is empty
            return treeArray;//returns empty array
        }//end if statement
        
        //traverse inorder
        Stack<DatabaseNode> stack = new Stack<>(); //stack to hold nodes
        DatabaseNode current = root; //start at root

        while (current != null || !stack.isEmpty()) {
            //add left children to stack
            while (current != null) {
                stack.push(current);
                current = current.getLeftChild();
            }//end inner while loop

            current = stack.pop();
            treeArray[index] = current;
            index++;
            //add right children to stack
            current = current.getRightChild();
        }//end outer while loop
        return treeArray;
    }//end inorderArray

    //puts all nodes into the txt file
    //turn tree into array and write to file
    public void writeToFile(DatabaseNode contactInfo){
        //put contact nodes from tree into array (inorder)
        DatabaseNode[] contactArray = inorderArray(root);
        try {
            FileWriter myWriter = new FileWriter("Phonebook.txt");
            //write the other stuff in here
            for (int i = 0; i < contactArray.length; i++) { //write everything saved into the list into the file
                myWriter.write(contactArray[i].getID() + "," + 
                contactArray[i].getFirstName() + "," + 
                contactArray[i].getLastName() + "," + 
                contactArray[i].getaddress() + "," + 
                contactArray[i].getCity() + "," + 
                contactArray[i].getState() + "," + 
                contactArray[i].getZip() + "," + 
                contactArray[i].getEmail() + "," + 
                contactArray[i].getPhNum() + "\n");
            }//end for loop
            myWriter.close();
            System.out.println("Succesfully written into the file.");
        } catch (IOException e) {
            System.out.println("An error has occured.");
            e.printStackTrace();
        }//end try/catch
    }//end writeToFile method
    
    //reads nodes from the files and adds to tree
    public void addFromFile() {
        try {
            File phoneBookFile = new File("Phonebook.txt");
            Scanner reader = new Scanner(phoneBookFile);
            String beforeString = null;
            String line = null;

            //initialize variables to store contact info
            int idNum = 0;
            String firstName = null;
            String lastName = null;
            String address = null;
            String city = null;
            String state = null;
            int zip = 0;
            String email = null;
            String phNum = null;

            //read until end of file and get contact info
            while(reader.hasNextLine()) {
                //read ID number
                beforeString = "ID #";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    idNum = Integer.parseInt(data);
                }//end if statement
                
                //read first name
                beforeString = "First Name: ";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    firstName = data;
                }//end if statement

                //read last name
                beforeString = "Last Name: ";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    lastName = data;
                }//end if statement

                //read address
                beforeString = "Address: ";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    address = data;
                }//end if statement

                //read city
                beforeString = "City: ";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    city = data;
                }//end if statement

                //read state
                beforeString = "State: ";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    state = data;
                }//end if statement

                //read zip code
                beforeString = "Zip Code: ";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    zip = Integer.parseInt(data);
                }//end if statement

                //read email
                beforeString = "Email: ";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    email = data;
                }//end if statement

                //read phone number
                beforeString = "Phone #: ";
                line = reader.nextLine();
                if (line.contains(beforeString)) {
                    String data = line.substring(line.indexOf(beforeString) + beforeString.length());
                    phNum = data;
                }//end if statement

                //read empty line
                if (reader.hasNextLine()) {
                    line = reader.nextLine();
                }//end if statement
                System.out.println();

                //create node to add to tree
                DatabaseNode newNode = new DatabaseNode(idNum, firstName, lastName, address, city, state, zip, email, phNum);
                //add it to tree
                addNode(newNode);
            }//end while loop   
        } catch (FileNotFoundException e) {
            System.out.println("An error has occured.");
            e.printStackTrace();
        }//end try/catch
    } //end addFromFile method
    
    //create a node from user input
    public DatabaseNode createNode() {
        int idNum = generateID();
       
        System.out.println("Enter first name:");
        String firstName = scanner.next();
        System.out.println("Enter last name:");
        String lastName = scanner.next();
        System.out.println("Enter address:");
        scanner.nextLine();
        String address = scanner.nextLine();
        System.out.println("Enter city:");
        String city = scanner.nextLine();
        System.out.println("Enter state:");
        String state = scanner.nextLine();
        System.out.println("Enter zipcode:");
        int zip = scanner.nextInt();
        System.out.println("Enter email:");
        String email = scanner.next();
        System.out.println("Enter phone number:");
        String phNum = scanner.next();
        scanner.nextLine();

        return new DatabaseNode (idNum, firstName, lastName, address, city, state, zip, email, phNum);
    }// end createNode method
    
    public void addNode(DatabaseNode newNode) {
        // if tree is empty
        if (root == null) {
            root = newNode;
            System.out.println("Record added successfully.");
            System.out.println("Your ID number is: " + newNode.getID());
            return; // end method here if root == null
        }
    
        // starting from the top
        DatabaseNode current = root;
        DatabaseNode parent = null;
    
        // while loop for placement if tree is not empty
        while (current != null) {
            parent = current;
            if (newNode.getID() < current.getID()) {
                current = current.getLeftChild(); // Move left
            } else if (newNode.getID() > current.getID()) {
                current = current.getRightChild(); // Move right
            } else {
                // Duplicate node found
                System.out.println("Node is a duplicate and cannot be placed.");
                return; // Exit the method if it's a duplicate
            }
        }
    
        // Insert the new node in the correct position
        if (newNode.getID() < parent.getID()) {
            parent.setLeftChild(newNode); // Set as left child
        } else {
            parent.setRightChild(newNode); // Set as right child
        }
    
        // Success message
        System.out.println("Record added successfully.");
        System.out.println("Your ID number is: " + newNode.getID());
    }
    
    // Main Method: Combines node creation and insertion
    public void addNode() {
        DatabaseNode newNode = createNode(); // Get user input to create a new node
        addNode(newNode); // Insert the new node into the tree
    }

    // DELETE method //
    public void deleteNode() {
        System.out.print("Enter ID number of record you want to delete: ");
        int idNum = scanner.nextInt();
        scanner.nextLine(); // Consume newline

          // Check if the node exists before attempting deletion
        if (search(idNum, root) == null) {
        System.out.println("Record with ID " + idNum + " not found.");
        return;
        }

        root = delete(root, idNum);
        System.out.println("Record deleted successfully.");
    }
 
    //Recursive delete helper method
    private DatabaseNode delete(DatabaseNode root, int idNum) {
    
       // Base case: if the tree is empty
        if (root == null) {
            return null;
        }

        // Traverse the tree to find the node to delete
        if (idNum < root.getID()) {
            root.left = delete(root.left, idNum);
        } else if (idNum > root.getID()) {
            root.right = delete(root.right, idNum);
        } else {
            // Found the node to delete
            // Case 1: No child (leaf node)
            if (root.left == null && root.right == null) {
                return null;
            }
            // Case 2: One child
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }
            // Case 3: Two children
            DatabaseNode successor = findMin(root.right);
            root.setID(successor.getID()); // Replace the value
            root.right = delete(root.right, successor.getID()); // Remove successor
            //System.out.println("Record deleted successfully.");
        }
           //root = delete(root, idNum);
       //System.out.println("Record deleted successfully.");

        return root;
    }
    // end DELETE method //

    // MODIFY method //
    public void modifyNode() {
     
        //get ID for node to modify
        System.out.print("Enter ID number of record you want to modify: ");
        int idNum = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        DatabaseNode node = search(idNum, root);

        //search the tree for the node with that id number, and assign it to current
        if (node == null) {//if no node exists with that id number
            System.out.println("Record not found.");
            return;
        }//end if statement

        //give choice of what to modify
        System.out.println("What data would you like to modify?");
        System.out.println("Choose one: 1) First name 2)Last name 3)Address 4)City 5)State 6)Zip code 7)email 8)Phone number");
        int userChoice = scanner.nextInt();
        scanner.nextLine(); // Consume newline    
        System.out.print("Enter new value: ");
        String newValue = scanner.nextLine();
        scanner.nextLine(); // Consume newline

        switch (userChoice) {
            case 1: 
                node.setFirstName(newValue);
                break;
            case 2:
                node.setLastName(newValue);
                break;
            case 3:
                node.setaddress(newValue);
                break;
            case 4:
                node.setCity(newValue);
                break;
            case 5:
                node.setState(newValue);
                break;
            case 6:
                node.setZip(Integer.parseInt(newValue));
                break;
            case 7:
                node.setEmail(newValue);
                break;
            case 8:
                node.setPhNum(newValue);
                break;
            default:
                System.out.println("Invalid choice.");
        }
        System.out.println("Record modified successfully.");      
    }  // end MODIFY method //

    // LOOKUP method
    public void lookupNode() {
        System.out.print("Enter ID number to lookup: ");
        int idNum = scanner.nextInt();
        scanner.nextLine(); // to get next line

        DatabaseNode node = search(idNum, root);
        if (node == null) {
            System.out.println("Record not found.");
            return;
        }

        System.out.print("Enter order (preorder, inorder or postorder): ");
        String order = scanner.nextLine();

        if (order.equalsIgnoreCase("preorder")) {
            printPreorder(root);
        } else if (order.equalsIgnoreCase("inorder")) {
            printInOrder(root);
        } else if (order.equalsIgnoreCase("postorder")) {
            printPostOrder();
        } else {
            System.out.println("Invalid order. Please choose either "
                + "'preorder', 'inorder' or 'postorder'.");
        }
        System.out.println();
    }

    // print PREORDER TRAVERSAL using Iteration//
    public void printPreorder(DatabaseNode root) {

        if (root == null) { // BST empty
            return;
        } // end if
        
        // creating a stack to hold tree values
        Stack<DatabaseNode> preorder = new Stack<>();
        // put the root in the stack
        preorder.push(root);

        while (!preorder.isEmpty()) {
            // remove current node from stack (so no repeats) and print it
            DatabaseNode current = preorder.pop();
            System.out.print(current.toString() + " ");
            
            // do right subtree first (bc stacks are read opposite way they are added to)
            if (current.getRightChild() != null) {
                preorder.push(current.getRightChild()); // adding right side values to stack
            } // end if statement

            // left subtree
            if (current.getLeftChild() != null) {
                preorder.push(current.getLeftChild());// adding left side values to stack
            } // end if statement
        } // end while loop
    }// end printPreorder method

// IN ORDER TRAVERSAL //
    public void printInOrder(DatabaseNode node) { // INORDER TRAVERSAL
        if (node == null)
            return;

        // left tree
        printInOrder(node.getLeftChild());

        //Print the current node's toString
        System.out.print(node.toString());

        // right tree
        printInOrder(node.getRightChild());
    }// end INORDER TRAVERSAL

// POST-ORDER TRAVERSAL //
    public void printPostOrder() {
        if (root == null) {
            System.out.println("Empty Database");
        } else {
            Stack<DatabaseNode> stack = new Stack<>();
            DatabaseNode current = root;
            boolean check = true;

            while (true) { // infinite loop until break
                // go to extreme left
                while (current != null && check) {
                    stack.push(current);
                    current = current.left;
                }
                if (stack.empty()) {
                    break;
                }
                // to avoid infinite loop
                if (current != stack.peek().right) {
                    current = stack.peek().right;
                    check = true;
                    continue;
                }
                // if not caught in any above special case
                current = stack.pop();
                System.out.print(current.toString() + " ");
                //System.out.print(current.getID() + " ");
                check = false;
            } // end outer while loop
        } // end it/else statement
    }// end PrintPostOrder method
    // end LOOKUP methods //

    // HELPER methods //
    private DatabaseNode findMin(DatabaseNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    private DatabaseNode search(int idNum, DatabaseNode node) {
        if (node == null || node.getID() == idNum) {
            return node;
        }
        if (idNum < node.getID()) {
            return search(idNum, node.left);
        } else {
            return search(idNum, node.right);
        }
    }//end search

    //generate random ID number
    public int generateID() {
        int idNum = 0;
        // generate random number
        idNum = (int) (Math.random() * 1000000000);
        // check that idNum is unique
        while (listIDs.contains(idNum)) {
            idNum = (int) (Math.random() * 1000000000);
        }
        return idNum;
    }// end generateID metho

    //prints count using recursion
    public int countRecords(DatabaseNode node) {
        if (node == null) {
            return 0;//base case
        }
        // Traverse left subtree
        int left = countRecords(node.left);
        // Traverse right subtree
        int right = countRecords(node.right);
        int total = left + right;
        return total + 1;
    }//end countRecords method
}//end class
