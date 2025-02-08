import java.util.Stack;
//will need to update add search and delete methods
public class AlizaMethods {
    DatabaseMethods database = new DatabaseMethods();
    //sort the tree
    //takes in root of tree
    //UNFINISHED
    public void sortTree(DatabaseNode root) {
        //traverse tree inorder and nodes in array
        inorderArray(root);
        //make a new tree with the array and return it (replace old tree)
    }//end sortTree

    //UNTESTED
    //iterative inorder traversal, returns array of nodes inorder
    public DatabaseNode[] inorderArray(DatabaseNode root) {
        DatabaseNode[] treeArray = new DatabaseNode[database.countRecords(root)];
        int index = 0;
        if (root == null) {
            return treeArray;//returns empty array
        }

        Stack<DatabaseNode> stack = new Stack<>();
        DatabaseNode current = root;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.getLeftChild();
            }

            current = stack.pop();
            treeArray[index] = current;
            index++;
            current = current.getRightChild();
        }
        return treeArray;
    }//end inorderArray

    //checks which node has greater sort value
    //returns greater node
    public DatabaseNode getGreaterValue(DatabaseNode newNode, DatabaseNode currentNode){
        //needs to check by char ASCII value, so convert to lowercase
        String newLast = newNode.getLastName().toLowerCase();
        String currentLast = currentNode.getLastName().toLowerCase();
        String newFirst = newNode.getFirstName().toLowerCase();
        String currentFirst = currentNode.getFirstName().toLowerCase();

        //check last names first
        //loop until reached last character of newnode last name
        //breaks when it find a difference in characters
        for (int i = 0; i < newLast.length(); i++){
            if (newLast.charAt(i) < currentLast.charAt(i)){
                return currentNode;
            } else if (newLast.charAt(i) > currentLast.charAt(i)) {
                return newNode;
            }//end if/else
        }//if you reach here, last names are same

        //if last names are same, check first names
        for (int i = 0; i < newFirst.length(); i++){
            if (newFirst.charAt(i) < currentFirst.charAt(i)){
                return currentNode;
            } else if (newFirst.charAt(i) > currentFirst.charAt(i)) {
                return newNode;
            }
        }//if you reach here, first names are same

        //if first names are same, sort by ID
        if (newNode.getID() < currentNode.getID()){
            return currentNode;
        } else {
            return newNode;
        }//end if/else
    }//end getGreaterValue

    //adds a node to the tree using node value to choose placement
    public void addNode(DatabaseNode newNode) {
        // if tree is empty
        if (root == null) {
            root = newNode;
            System.out.println("Record added successfully.");
            System.out.println("ID number is: " + newNode.getID());
            return; // end method here if root == null
        }
    
        // starting from the top
        DatabaseNode current = root;
        DatabaseNode parent = null;
    
        // while loop for placement if tree is not empty
        while (current != null) {
            parent = current;
            if (getGreaterValue(newNode, current) == current) {  //if newNode is less than current node
                current = current.getLeftChild(); // Move left
            } else if (getGreaterValue(newNode, current) == newNode) {//if newNode is greater than current node
                current = current.getRightChild(); // Move right
            } else {
                // Duplicate node found
                System.out.println("Node is a duplicate and cannot be placed.");
                return; // Exit the method if it's a duplicate
            }
        }//end while
    
        // Insert the new node in the correct position
        if (getGreaterValue(newNode, parent) == parent) {//if newNode is less than parent
            parent.setLeftChild(newNode); // Set as left child
        } else {
            parent.setRightChild(newNode); // Set as right child
        }//end if/else
    
        // Success message
        System.out.println("Record added successfully.");
        System.out.println("Your ID number is: " + newNode.getID());
    }//end addNode
    
    // Main Method: Combines node creation and insertion
    public void addNode() {
        DatabaseNode newNode = createNode(); // Get user input to create a new node
        addNode(newNode); // Insert the new node into the tree
    }//end addNode

}//end AlizaMethods

