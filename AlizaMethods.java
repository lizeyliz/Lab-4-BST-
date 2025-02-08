import java.util.Stack;

public class AlizaMethods {
    DatabaseMethods database = new DatabaseMethods();
    //sort the tree
    //takes in root of tree
    //UNFINISHED
    public void sortTree(DatabaseNode root) {
        //traverse tree inorder and nodes in array
        inOrderArray(root);
        //make a new tree with the array and return it (replace old tree)
    }//end sortTree

    //UNTESTED
    //iterative inorder traversal, returns array of nodes
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
                current = current.left;
            }

            current = stack.pop();
            treeArray[index] = current;
            index++;
            current = current.right;
        }
        return treeArray;
    }//end inorderArray

    //checks which node has greater value by checking first character of each name
    //if first character is same, checks next character
    //if last name same, check first name
    //if both names same, sort by ID
    //returns greater name
    public BoardNode getGreaterValue(Boardnode newNode, BoardNode oldNode){
        //needs to check by char ASCII value, so convert to lowercase
        String newLast = newNode.getLastName().toLowerCase();
        String oldLast = newNode.getLastName().toLowerCase();
        //loop until reached last character of newnode last name
        for (int i = 0; i < newLast.length(); i++){
            if (newLast.charAt(i) < oldLast.charAt(i)){
                return oldNode;
            } else if (newLast.charAt(i) > oldLast.charAt(i)) {
                return newNode;
            }
        }//if you reach here, last names are same

        //if last names are same, check first names
        String newFirst = newNode.getFirstName().toLowerCase();
        String oldFirst = newNode.getFirstName().toLowerCase();
        //loop until reached last character of newnode last name
        for (int i = 0; i < newLast.length(); i++){
            if (newFirst.charAt(i) < oldFirst.charAt(i)){
                return oldNode;
            } else if (newFirst.charAt(i) > oldFirst.charAt(i)) {
                return newNode;
            }
        }//if you reach here, first names are same

        //if first names are same, sort by ID
        if (newNode.getID() < oldNode.getID()){
            return oldNode;
        } else {
            return newNode;
        }//end if/else
    }//end getGreaterValue
}//end AlizaMethods

