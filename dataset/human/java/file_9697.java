import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            Node node = new Node(scanner);
            nodes[node.id] = node;
        }

        for (Node node : nodes) {
            if (node.left != -1)
                nodes[node.left].parent = node.id;
            if (node.right != -1)
                nodes[node.right].parent = node.id;
            if (node.left != -1 && node.right != -1) {
                nodes[node.left].sibling = node.right;
                nodes[node.right].sibling = node.left;
            }
        }
        for (Node node : nodes) {
            int parent = node.parent;
            while (parent != -1) {
                node.depth++;
                parent = nodes[parent].parent;
            }
        }
        for (Node node : nodes)
            node.height = calculateHeight(nodes, node.id);

        for (Node node : nodes)
            print(node);

    }

    private static int calculateHeight(Node[] nodes, int id) {
        int h1 = 0;
        int h2 = 0;
        if (nodes[id].left != -1)
            h1 += calculateHeight(nodes, nodes[id].left) + 1;
        if (nodes[id].right != -1)
            h2 += calculateHeight(nodes, nodes[id].right) + 1;
        return Math.max(h1, h2);
    }

    public static void print(Node node) {
        System.out.println(
               "node " + node.id + ": " +
               "parent = " + node.parent + ", " +
               "sibling = " + node.sibling + ", " +
               "degree = " + node.degree + ", " +
               "depth = " + node.depth + ", " +
               "height = " + node.height + ", " +
               getTypeName(node)
               );
    }

    private static String getTypeName(Node node) {
        if (node.parent == -1) {
            return "root";
        }
        if (node.degree == 0) {
            return "leaf";
        }
        return "internal node";
    }

    private static class Node {
        int id;
        int left;
        int right;
        int parent  = -1;
        int sibling = -1;
        int degree  = 0;
        int depth   = 0;
        int height  = 0;

        Node(Scanner scanner) {
            id    = scanner.nextInt();
            left  = scanner.nextInt();
            right = scanner.nextInt();
            if (left != -1) degree++;
            if (right != -1) degree++;
        }
    }
}
