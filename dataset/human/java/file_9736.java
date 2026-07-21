import java.util.Scanner;
import java.util.Stack;

class Node {
    int id;
    int left;
    int right;
    int parent;
    int sibling;
    int degree;
    int depth;
    int height;
    String type;

    Node(int id, int left, int right) {
        this.id = id;
        this.left = left;
        this.right = right;
        parent = -1;
        sibling = -1;
        degree = 0;
        height = 0;
    }

    static void setInfo(Node[] tree) {
        for(Node node : tree) {
            if(node.left >= 0) {
                tree[node.left].parent = node.id;
                node.degree++;
            }
            if(node.right >= 0) {
                tree[node.right].parent = node.id;
                node.degree++;
            }
            if(node.degree == 2) {
                tree[node.left].sibling = node.right;
                tree[node.right].sibling = node.left;
            }
        }

        int root = -1;
        Stack<Integer> leaves = new Stack<>();
        for(Node node : tree) {
            if(node.degree == 0) {
                leaves.push(node.id);
                node.type = "leaf";
            }
            if(node.parent < 0) {
                root = node.id;
                node.type = "root";
            }
            if(node.type == null) {
                node.type = "internal node";
            }
        }

        while(!leaves.isEmpty()) {
            Node tmp = tree[leaves.pop()];
            if(tmp.parent >= 0 && tree[tmp.parent].height < tmp.height + 1) {
                tree[tmp.parent].height = tmp.height + 1;
                leaves.push(tmp.parent);
            }
        }

        Stack<Integer> task = new Stack<>();
        task.push(root);
        tree[root].depth = 0;
        while(!task.isEmpty()) {
            Node tmp = tree[task.pop()];
            if(tmp.left >= 0) {
                tree[tmp.left].depth = tmp.depth + 1;
                task.push(tmp.left);
            }
            if(tmp.right >= 0) {
                tree[tmp.right].depth = tmp.depth + 1;
                task.push(tmp.right);
            }
        }
    }

    void printInfo() {
        System.out.printf(
            "node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
            id, parent, sibling, degree, depth, height, type
        );
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        int n = sc.nextInt();
        Node[] tree = new Node[n];
        for(int i = 0; i < n; i++) {
            int id = sc.nextInt();
            int left = sc.nextInt();
            int right = sc.nextInt();
            tree[id] = new Node(id, left, right);
        }

        Node.setInfo(tree);
        for(Node node : tree) {
            node.printInfo();
        }

        sc.close();
    }
}
