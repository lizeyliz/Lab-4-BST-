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
}//end AlizaMethods

