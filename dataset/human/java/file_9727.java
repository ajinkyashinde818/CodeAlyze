import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static void main (String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        boolean[] isRoot = new boolean[n];
        Arrays.fill(isRoot, true);

        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            int left = sc.nextInt();
            int right = sc.nextInt();
            if (left != -1) isRoot[left] = false;
            if (right != -1) isRoot[right] = false;
            nodes[id] = new Node(id, left, right);
        }

        for (int i = 0; i < n; i++) {
            if (isRoot[i]) {
                solve(nodes, -1, i, 0);
                break;
            }
        }

        StringBuilder sb = new StringBuilder("");
        for (Node node: nodes) {
            sb.append("node ").append(node.id);
            sb.append(": parent = ").append(node.parent);
            sb.append(", sibling = ").append(node.sibling);
            sb.append(", degree = ").append(node.degree);
            sb.append(", depth = ").append(node.depth);
            sb.append(", height = ").append(node.height);
            sb.append(", ").append(node.type);
            sb.append("\n");
        }
        System.out.print(sb);
    }

    public static int solve(Node[] nodes, int parent, int id, int depth) {
        if (id == -1) {
            return -1;
        }

        Node node = nodes[id];

        node.parent = parent;

        if (node.left != -1) nodes[node.left].sibling = node.right;
        if (node.right != -1) nodes[node.right].sibling = node.left;

        node.degree = ((node.left == -1) ? 0 : 1) + ((node.right == -1) ? 0 : 1);
        node.depth = depth;
        node.height = Math.max(solve(nodes, id, node.left, depth + 1), solve(nodes, id, node.right, depth + 1)) + 1;

        if (node.parent == -1) node.type = "root";
        else if (node.left == -1 && node.right == -1) node.type = "leaf";
        else node.type = "internal node";

        return node.height;
    }
}

class Node {
    public int id;
    public int parent;
    public int sibling = -1;
    public int degree;
    public int depth;
    public int height;
    public String type;
    public int left;
    public int right;

    public Node(int id, int left, int right) {
        this.id = id;
        this.left = left;
        this.right = right;
    }
}
