import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < n; i++) {
            Node node = nodes[scanner.nextInt()];
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            int degree = 0;
            if (left != -1) {
                node.childLeft = nodes[left];
                nodes[left].parent = node;
                degree++;
            }
            if (right != -1) {
                node.childRight = nodes[right];
                nodes[right].parent = node;
                degree++;
            }
            if (node.childLeft != null && node.childRight != null) {
                node.childLeft.sibling = node.childRight;
                node.childRight.sibling = node.childLeft;
            }
            node.degree = degree;
        }
        Node root = null;
        for (int i = 0; i < n; i++) {
            if (nodes[i].parent == null) {
                root = nodes[i];
                break;
            }
        }
        root.setDepth(0);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            Node node = nodes[i];
            sb.append("node " + String.valueOf(i) + ": parent = ");
            if (node.parent == null) {
                sb.append("-1");
            } else {
                sb.append(node.parent.id);
            }
            sb.append(", sibling = ");
            if (node.sibling == null) {
                sb.append("-1");
            } else {
                sb.append(node.sibling.id);
            }
            sb.append(", degree = " + String.valueOf(node.degree));
            sb.append(", depth = " + String.valueOf(node.depth));
            sb.append(", height = " + String.valueOf(node.height()));
            sb.append(", ");
            if (node.parent == null) {
                sb.append("root");
            } else if (node.childLeft != null || node.childRight != null) {
                sb.append("internal node");
            } else {
                sb.append("leaf");
            }
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }

    private static class Node {
        int id;
        Node parent;
        Node childLeft;
        Node childRight;
        Node sibling;
        int degree;
        int depth;

        private Node(int id) {
            this.id = id;
        }

        private void setDepth(int depth) {
            this.depth = depth;
            if (childLeft != null) {
                childLeft.setDepth(depth + 1);
            }
            if (childRight != null) {
                childRight.setDepth(depth + 1);
            }
        }

        private int height() {
            int height = 0;
            if (childLeft != null) {
                height = childLeft.height() + 1;
            }
            if (childRight != null) {
                height = Math.max(height, childRight.height() + 1);
            }
            return height;
        }
    }
}
