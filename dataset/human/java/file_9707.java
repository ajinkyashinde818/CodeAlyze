import java.util.Scanner;

public class Main {

    static class Node{
        int parent;
        int left;
        int right;

        public Node() {
            this.parent = -1;
            this.left = -1;
            this.right = -1;
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        T = new Node[n];
        D = new int[n];
        H = new int[n];
        int t,l,r;
        for(int i = 0 ; i < n; i ++){
            T[i] = new Node();
        }
        for(int i = 0 ; i < n; i ++){
            t = sc.nextInt();
            l = sc.nextInt();
            r = sc.nextInt();
            T[t].left = l;
            T[t].right = r;
            if(l != -1){
                T[l].parent = t;
            }
            if(r != -1){
                T[r].parent = t;
            }
        }

        for(int i = 0; i < n; i ++){
            if(T[i].parent == -1){
                R = i;
                break;
            }
        }

        setDepth(R,0);
        setHeight(R);

        print();
    }


    static Node[] T;
    static int[] D,H;
    static int n;
    static int R;

    static void print(){
        for(int i = 0; i < n; i ++){
            System.out.print("node " + i +": parent = " + T[i].parent +", sibling = " + getSibling(i));
            System.out.print(", degree = " + getDegree(i) +", ");
            System.out.print("depth = " + D[i] +", ");
            System.out.print("height = " + H[i] +", ");
            System.out.print(type(i));
            System.out.println();
        }
    }

    static int getSibling(int u){
        if(T[u].parent != -1){
            int p = T[u].parent;
            if(T[p].left != -1 && T[p].left != u){
                return T[p].left;
            }
            else if(T[p].right != -1 && T[p].right != u){
                return T[p].right;
            }
        }
        return -1;
    }


    static int getDegree(int u){
        int d = 0;
        if(T[u].right != -1){
            d++;
        }
        if(T[u].left != -1){
            d++;
        }
        return d;
    }


    static void setDepth(int u,int d){
        if(u == -1) return;
        D[u] = d;
        setDepth(T[u].left,d + 1);
        setDepth(T[u].right,d + 1);
    }

    static int setHeight(int u){
        int h1= 0,h2 = 0;
        if(T[u].left != -1){
            h1 = setHeight(T[u].left) + 1;
        }
        if(T[u].right != -1){
            h2 = setHeight(T[u].right) + 1;
        }
        H[u] = Math.max(h1,h2);
        return Math.max(h1,h2);
    }


    static String type(int u){
        String type;
        if(T[u].parent == -1){
            type = "root";
        }
        else if(T[u].left == -1 && T[u].right == -1){
            type = "leaf";
        }
        else {
            type = "internal node";
        }
        return type;
    }
}
