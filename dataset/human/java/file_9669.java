import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            int[] children = new int[]{sc.nextInt(), sc.nextInt()};
            nodes[id] = new Node(id, children);
        }

        solve(nodes);

        for (int i = 0; i < nodes.length; i++) {
            Node node = nodes[i];
            int degree = 0;
            for (int j = 0; j < node.children.length; j++) {
                if (node.children[j] != -1) {
                    degree++;
                }
            }
            String type = node.type == Type.INTERNAL_NODE ? "internal node" : node.type == Type.LEAF ? "leaf" : "root";
            System.out.println("node " + node.id + ": parent = " + node.parent + ", sibling = " + node.sibling
                               + ", degree = " + degree + ", depth = " + node.depth + ", height = " + node.height
                               + ", " + type);
        }
    }

    private static void solve(Node[] nodes) {
        for (int i = 0; i < nodes.length; i++) {
            Node n = nodes[i];
            if (n.children[0] != -1) {
                nodes[n.children[0]].parent = n.id;
                nodes[n.children[0]].sibling = n.children[1];
            }
            if (n.children[1] != -1) {
                nodes[n.children[1]].parent = n.id;
                nodes[n.children[1]].sibling = n.children[0];
            }
        }

        int root = -1;
        for (int i = 0; i < nodes.length; i++) {
            Node n = nodes[i];
            if (n.parent == -1) {
                root = n.id;
                n.type = Type.ROOT;
                n.depth = 0;
            }
        }

        nodes[root].height = rec(nodes, root, 1);
    }

    private static int rec(Node[] nodes, int parent, int depth) {
        int[] children = nodes[parent].children;
        int height = -1;
        for (int i = 0; i < children.length; i++) {
            if (children[i] != -1) {
                Node node = nodes[children[i]];
                node.depth = depth;
                node.height = rec(nodes, children[i], depth + 1);
                height = Math.max(height, node.height);
                if (node.height != 0) {
                    node.type = Type.INTERNAL_NODE;
                } else {
                    node.type = Type.LEAF;
                }
            }
        }
        return height + 1;
    }

    static class Node {

        Node(int id, int[] children) {
            this.id = id;
            this.children = children;
            this.parent = -1;
            this.sibling = -1;
        }

        int id;
        int sibling;
        int parent;
        int depth;
        int height;
        int[] children;
        Type type;
    }

    enum Type {
        ROOT, INTERNAL_NODE, LEAF;
    }
}
