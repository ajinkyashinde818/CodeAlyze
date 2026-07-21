import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.IntStream;

class Node {
    final static int NIL = -1;

    int id, parent, left, right, depth, height;

    Node(int id) {
        this.id = id;
        parent = NIL;
        left = NIL;
        right = NIL;
        depth = 0;
        height = 0;
    }

    boolean isRoot() {
        return parent == NIL;
    }

    boolean isLeaf() {
        return left == NIL && right == NIL;
    }

    boolean hasChild() {
        return !isLeaf();
    }

    String getType() {
        if (isRoot()) return "root";
        else if (isLeaf()) return "leaf";
        else return "internal node";
    }

    int getDegree() {
        int c = 0;
        if (left != NIL) c++;
        if (right != NIL) c++;
        return c;
    }

    int[] getChildren() {
        switch (getDegree()) {
            case 0:
                return new int[]{};
            case 1:
                if (left != NIL) return new int[]{left};
                else return new int[]{right};
            default:
                return new int[]{left, right};
        }
    }
}

class RootedTree {
    static Node findRoot(Node[] nodes) {
        for (Node node : nodes) {
            if (node.isRoot()) return node;
        }
        return null;
    }

    static void setDepth(Node node, Node[] nodes, int depth) {
        node.depth = depth;

        for (int id : node.getChildren()) {
            setDepth(nodes[id], nodes, depth + 1);
        }
    }

    static int setHeight(Node node, Node[] nodes) {
        int h1 = 0;
        int h2 = 0;

        if (node.left != Node.NIL) {
            h1 = setHeight(nodes[node.left], nodes) + 1;
        }
        if (node.right != Node.NIL) {
            h2 = setHeight(nodes[node.right], nodes) + 1;
        }

        if (h1 < h2) node.height = h2;
        else node.height = h1;

        return node.height;
    }

    static int getSibling(Node node, Node[] nodes) {
        if (node.isRoot()) return -1;

        Node parent = nodes[node.parent];
        if (parent.left != Node.NIL && parent.left != node.id) return parent.left;
        if (parent.right != Node.NIL && parent.right != node.id) return parent.right;

        return -1;
    }

    static String nodeToString(Node node, Node[] nodes) {
        return "node " + node.id
                + ": parent = " + node.parent
                + ", sibling = " + getSibling(node, nodes)
                + ", degree = " + node.getDegree()
                + ", depth = " + node.depth
                + ", height = " + node.height
                + ", " + node.getType()
                ;
    }
}

public class Main {
    public static void main(String[] args) {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {
            final int n = Integer.parseInt(in.readLine());
            Node[] nodes = IntStream.range(0, n).mapToObj(Node::new).toArray(Node[]::new);

            for (int i = 0; i < n; i++) {
                int[] arr = Arrays.stream(in.readLine().split(" "))
                        .mapToInt(Integer::parseInt).toArray();
                Node node = nodes[arr[0]];
                node.left = arr[1];
                node.right = arr[2];

                if (node.left != Node.NIL)
                    nodes[node.left].parent = node.id;
                if (node.right != Node.NIL)
                    nodes[node.right].parent = node.id;
            }

            Node root = RootedTree.findRoot(nodes);
            assert root != null;

            RootedTree.setDepth(root, nodes, 0);
            RootedTree.setHeight(root, nodes);

            for (Node node : nodes) {
                System.out.println(RootedTree.nodeToString(node, nodes));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
