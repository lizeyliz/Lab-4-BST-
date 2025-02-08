import java.util.Stack;

public class AlizaMethods {
    DatabaseMethods database = new DatabaseMethods();
    //sort the tree
    //takes in root of tree
    public void sortTree(DatabaseNode root) {
        //traverse tree inorder and nodes in array
        inOrderArray(root);
        //make a new tree with the array and return it (replace old tree)
    }//end sortTree


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

    //recursive method: creates array of nodes from inorder traversal of tree
    //takes in root of tree
    //helper method for sortTree
    /*public DatabaseNode[] inOrderArray(DatabaseNode node, int index) { // INORDER TRAVERSAL
        //create a an array that is the size of the number of records in the tree
        //to store the nodes in the tree
        DatabaseNode[] treeArray = new DatabaseNode[database.countRecords(node)];

        // left tree
        inOrderArray(node.getLeftChild(), index);

        //add the current node to the array
        treeArray[index] = node;
        index++;
        // right tree
        inOrderArray(node.getRightChild(), index);

        return treeArray;
    }// end inOrderArray*/


}//end AlizaMethods

