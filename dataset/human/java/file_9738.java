import java.util.Scanner;

public class Main {
    public static class Node {
        int parent, left, right;
        Node() {
            this.left = -1;
            this.right = -1;
        }
    }
    public static int MAX = 100005;
    public static int n;
    public static Node[] T = new Node[MAX];
    static int[] D = new int[MAX];
    static int[] H = new int[MAX];

    static void setDepth(int u, int d) {
        if(u == -1) return;
        D[u] = d;
        setDepth(T[u].left, d+1);
        setDepth(T[u].right, d+1);
    }

    static int setHeight(int u) {
        int h1 = 0, h2 = 0;
        if(T[u].left != -1)
            h1 = setHeight(T[u].left) + 1;
        if(T[u].right != -1)
            h2 = setHeight(T[u].right) + 1;
        return H[u] = (h1 > h2 ? h1 : h2);
    }

    static int getSibling(int u) {
        if(T[u].parent == -1) return -1;
        if(T[T[u].parent].left != u && T[T[u].parent].left != -1)
            return T[T[u].parent].left;
        if(T[T[u].parent].right != u && T[T[u].parent].right != -1)
            return T[T[u].parent].right;
        return -1;
    }

    static void print(int u) {
        System.out.print("node " + u + ": ");
        System.out.print("parent = " + T[u].parent + ", ");
        System.out.print("sibling = " + getSibling(u) + ", ");
        int deg = 0;
        if(T[u].left != -1) deg++;
        if(T[u].right != -1) deg++;
        System.out.print("degree = " + deg + ", ");
        System.out.print("depth = " + D[u] + ", ");
        System.out.print("height = " + H[u] + ", ");

        if(T[u].parent == -1) {
            System.out.println("root");
        } else if(T[u].left == -1 && T[u].right == -1) {
            System.out.println("leaf");
        } else {
            System.out.println("internal node");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = 0, l = 0, r = 0, root = 0;
        n = sc.nextInt();

        for(int i = 0; i < n; i++) {
            T[i] = new Node();
            T[i].parent = -1;
        }

        for(int i = 0; i < n; i++) {
            v = sc.nextInt();
            l = sc.nextInt();
            r = sc.nextInt();

            T[v].left = l;
            T[v].right = r;
            if(l != -1) T[l].parent = v;
            if(r != -1) T[r].parent = v;
        }
        for(int i = 0; i < n; i++) if(T[i].parent == -1) root = i;

        setDepth(root, 0);
        setHeight(root);

        for(int i = 0; i < n; i++) print(i);
    
    }
}
