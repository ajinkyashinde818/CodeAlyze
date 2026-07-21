import java.util.Scanner;

public class Main {
    static Node SENTINEL = new Node(-1, null, null, null);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i, SENTINEL, SENTINEL, SENTINEL);
        }

        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            int left = sc.nextInt();
            int right = sc.nextInt();

            if (left != -1) {
                nodes[left].parent = nodes[id];
                nodes[id].left = nodes[left];
            }
            if (right != -1) {
                nodes[right].parent = nodes[id];
                nodes[id].right = nodes[right];
            }
        }
        for (int i = 0; i < n; i++) {
            Node nd = nodes[i];
            String kind = 
                    (isEmpty(nd.parent)) ? "root" :
                    (isEmpty(nd.left) && isEmpty(nd.right)) ? "leaf" : "internal node";
                
            System.out.println(
                    "node " + i + ": "
                   +   "parent = "  + nd.parent.val
                   + ", sibling = " + nd.getSibling().val 
                   + ", degree = "  + nd.getDigree()
                   + ", depth = "   + nd.getDepth()
                   + ", height = "  + nd.getHeight()
                   + ", " + kind);
        }
    }

    public static class Node {
        int  val;
        Node parent;
        Node left;
        Node right;

        public Node(int val, Node parent, Node left, Node right) {
            this.val = val;
            this.parent = parent;
            this.left = left;
            this.right = right;
        }

        public Node getSibling() {
            Node p = this.parent;
            if (p.val == -1)
                return SENTINEL;
            else if (p.left != null && p.left.val != this.val)
                return p.left;
            else if (p.right != null && p.right.val != this.val)
                return p.right;
            else
                return SENTINEL;
        }
        
        public int getDigree() {
            int count = 0;
            if (!isEmpty(this.left)) count++;
            if (!isEmpty(this.right)) count++;
            return count;
        }
        
        public int getDepth() {
            int depth = 0;
            Node p = this.parent;
            while (p.val != -1) {
                depth++;
                p = p.parent;
            }
            return depth;
        }
        
        public int getHeight() {
            int heightL = -1;
            int heightR = -1;
            if (!isEmpty(this.left)) {
                heightL = this.left.getHeight();
            }
            if (!isEmpty(this.right)) {
                heightR = this.right.getHeight();
            }
            
            return Math.max(heightL, heightR) + 1;
        }
    }
    static boolean isEmpty(Node n) {
        return n == null || n.val == -1;
    }
}
