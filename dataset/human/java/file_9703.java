import javax.xml.crypto.Data;
import java.util.*;
import java.io.*;

public class Main {
    public static int SENTINEL = 100000007;
    public static int MAX = 10007;
    public static int NIL = -1;

    public static int[] Depth = new int[MAX];
    public static int[] Height = new int[MAX];
    public static Tree[] Node = new Tree[MAX];
    public static int n;

    public static void main(String[] args) throws IOException {

        //??\???
        /*
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        */

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            Node[i] = new Tree(NIL, NIL, NIL);
        }
        int v, l, r;
        for (int i = 0; i < n; i++) {
            v = sc.nextInt();
            l = sc.nextInt();
            r = sc.nextInt();
            Node[v].left = l;
            Node[v].right = r;
            if(l != NIL) Node[l].parent = v;
            if(r != NIL) Node[r].parent = v;
        }

        int root = 0;
        for(int i = 0; i < n; i++) {
            if(Node[i].parent == NIL) root = i;
        }

        setDepth(root, 0);
        setHeight(root);
        // ??????
        for(int i = 0; i < n; i++) print(i);
    }

    public static void setDepth(int u, int d) {
        Depth[u] = d;
        if(Node[u].right != NIL) setDepth(Node[u].right, d + 1);
        if(Node[u].left != NIL) setDepth(Node[u].left, d + 1);
    }

    public static int setHeight(int u) {
        int h1 = 0, h2 = 0;
        if(Node[u].left != NIL) h1 = setHeight(Node[u].left) + 1;
        if(Node[u].right != NIL) h2 = setHeight(Node[u].right) + 1;
        return Height[u] = Math.max(h1, h2);
    }

    public static int degree(int u) {
        int deg = 0;
        if(Node[u].left != NIL) deg++;
        if(Node[u].right != NIL) deg++;
        return deg;
    }

    public static int sibling(int u) {
        if(Node[u].parent == NIL) return NIL;
        int p = Node[u].parent;
        if(Node[p].left == u) return Node[p].right;
        return Node[p].left;
    }

    public static void print(int u) {
        System.out.printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u, Node[u].parent, sibling(u), degree(u), Depth[u], Height[u]);
        if(Node[u].parent == NIL) System.out.print("root");
        else if(Node[u].left == NIL && Node[u].right == NIL) System.out.print("leaf");
        else System.out.print("internal node");
        System.out.println();
    }
}

class Tree {
    int parent;
    int left;
    int right;
    Tree(int p, int l, int r) {
        parent = p;
        left = l;
        right = r;
    }
}
