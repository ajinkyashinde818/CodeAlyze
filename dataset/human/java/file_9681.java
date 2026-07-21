import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        HashMap<Integer, TreeNode> nodes = new HashMap<>();
        int rootID = 0;
        ArrayList<Integer> notRoots = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int id = in.nextInt();
            int leftID = in.nextInt();
            int rightID = in.nextInt();
            if (leftID != -1) notRoots.add(leftID);
            if (rightID != -1) notRoots.add(rightID);
            TreeNode node = new TreeNode(id, leftID, rightID);
            nodes.put(node.id, node);
        }
        notRoots.sort(Integer::compareTo);
        for (Integer i : notRoots) {
            if (rootID == i) {
                rootID++;
            }
        }
        updateNodes(nodes, rootID, -1, 0, -1);

        int id = 0;
        TreeNode node = nodes.get(id);
        while (node != null) {
            System.out.println("node " + id + ": parent = " + node.parent + ", sibling = " + node.sibling
                    + ", degree = " + node.degree + ", depth = " + node.depth + ", height = " + node.height + ", "
                    + node.getType());
            node = nodes.get(++id);
        }
    }

    private static int updateNodes(HashMap<Integer, TreeNode> nodes, int currentID, int parent, int depth, int sibling) {
        TreeNode node = nodes.get(currentID);
        node.parent = parent;
        node.depth = depth;
        node.sibling = sibling;

        if (node.isLeaf()) {
            node.height = 0;
            return node.height;
        } else {
            int heightLeft = 0, heightRight = 0;
            if (node.left != -1) {
                heightLeft = updateNodes(nodes, node.left, currentID, depth + 1, node.right);
            }
            if (node.right != -1) {
                heightRight = updateNodes(nodes, node.right, currentID, depth + 1, node.left);
            }
            node.height = heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
            return node.height;
        }
    }
}

class TreeNode {
    int id;
    int degree;
    int parent;
    int depth;
    int sibling;
    int height;
    int left;
    int right;

    public TreeNode(int id, int left, int right) {
        this.id = id;
        this.left = left;
        this.right = right;
        if (left == -1 && right == -1) {
            degree = 0;
        } else if (left == -1 || right == -1) {
            degree = 1;
        } else {
            degree = 2;
        }
    }

    boolean isLeaf() {
        return degree == 0;
    }

    String getType() {
        if (depth == 0) {
            return "root";
        } else if (isLeaf()) {
            return "leaf";
        } else {
            return "internal node";
        }
    }
}
