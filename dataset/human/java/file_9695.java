import java.util.*;
import java.io.*;

public class Main {
    
    public static void main(String[] args) {
        Main main = new Main();
        main.solv();
    }
    
    private void solv() {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < n; i++) {
            int id = input.nextInt();
            int left = input.nextInt();
            int right = input.nextInt();
            nodes[id].setLeft(left);
            nodes[id].setRight(right);
            if (left != -1) {
                nodes[left].setParent(id);
                nodes[left].setSibling(right);
            }
            if (right != -1) {
                nodes[right].setParent(id);
                nodes[right].setSibling(left);
            }
        }
        for (Node node : nodes) {
            if (node.getParent() == -1) {
                updateNodes(node, nodes);
                break;
            }
        }
        for (Node node : nodes) {
            System.out.println(node);
        }
    }
    
    private int updateNodes(Node node, Node[] nodes) {
        int l = 0;
        if (node.hasLeft()) {
            nodes[node.getLeft()].setDepth(node.getDepth() + 1);
            l = updateNodes(nodes[node.getLeft()], nodes);
        }
        int r = 0;
        if (node.hasRight()) {
            nodes[node.getRight()].setDepth(node.getDepth() + 1);
            r = updateNodes(nodes[node.getRight()], nodes);
        }
        node.setHeight(Math.max(l,r));
        return node.getHeight()+1;
    }
    
    private static class Node {
        int id;
        int sibling = -1;
        int left = -1;
        int right = -1;
        int parent = -1;
        int depth = 0;
        int height = 0;
        Node(int id) {
            this.id = id;
        }
        int getId() {
            return id;
        }
        int getSibling() {
            return sibling;
        }
        void setSibling(int sibling) {
            this.sibling = sibling;
        }
        int getLeft() {
            return left;
        }
        void setLeft(int left) {
            this.left = left;
        }
        boolean hasLeft() {
            return left != -1;
        }
        int getRight() {
            return right;
        }
        void setRight(int right) {
            this.right = right;
        }
        boolean hasRight() {
            return right != -1;
        }
        int getParent() {
            return parent;
        }
        void setParent(int parent) {
            this.parent = parent;
        }
        int getDepth() {
            return depth;
        }
        void setDepth(int depth) {
            this.depth = depth;
        }
        int getHeight() {
            return height;
        }
        void setHeight(int height) {
            this.height = height;
        }
        int getDegree() {
            return (hasLeft() ? 1 : 0) + (hasRight() ? 1 : 0);
        }
        String getType() {
            if (depth == 0) return "root";
            if (getDegree() == 0) return "leaf";
            return "internal node";
        }
        private static String TEMPLATE = "node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s";
        @Override public String toString() {
            StringBuilder sb = new StringBuilder();
            int degree = getDegree();
            sb.append(String.format(TEMPLATE, id, parent, sibling, degree, depth, height, getType()));
            return sb.toString();
        }
    }
    
    private void print(Object[] xs) {
        StringBuilder sb = new StringBuilder();
        for (Object x : xs) sb.append(x.toString()).append(' ');
        System.out.println(sb.toString().trim());
    }
    
    private void print(int[] xs) {
        StringBuilder sb = new StringBuilder();
        for (int x : xs) sb.append(x).append(' ');
        System.out.println(sb.toString().trim());
    }
    
    private static class Scanner {
        BufferedReader r;
        StreamTokenizer st;
        
        public Scanner(InputStream in) {
            r = new BufferedReader(new InputStreamReader(in));
            st = new StreamTokenizer(r);
        }
        
        public String next() {
            nextToken();
            return st.sval;
        }
        
        public Integer nextInt() {
            nextToken();
            return (int)st.nval;
        }
        
        private int nextToken() {
            int token = st.TT_EOF;
            try {
                token = st.nextToken();
            } catch (IOException e) {
            }
            return token;
        }
    }
}
