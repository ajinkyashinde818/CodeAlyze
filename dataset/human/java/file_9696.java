import java.util.Scanner;

public class Main {
    
    static Node[] tree;
    static int[] depth;
    static int[] height;
    static final int NIL = -1;

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        tree = new Node[n];
        for(int i = 0; i < n; i++){
            tree[i] = new Node();
        }
        for(int i = 0; i < n; i++){
            int id = Integer.parseInt(sc.next());
            int left = Integer.parseInt(sc.next());
            int right = Integer.parseInt(sc.next());
            tree[id].left = left;
            tree[id].right = right;
            if(left != NIL) tree[left].parent = id;
            if(right != NIL) tree[right].parent = id;
        }
        
        depth = new int[n];
        height = new int[n];
        int u = 0;
        while(tree[u].parent != NIL){
            u = tree[u].parent;
        }
        setDepth(u, 0);
        setHeight(u);
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            sb.append("node ").append(i);
            sb.append(": parent = ").append(tree[i].parent);
            sb.append(", sibling = ").append(getSibling(i));
            sb.append(", degree = ").append(getDegree(i));
            sb.append(", depth = ").append(depth[i]);
            sb.append(", height = ").append(height[i]);
            sb.append(", ").append(getType(i));
            sb.append(System.lineSeparator());
        }
        System.out.print(sb);
    }
    
    static void setDepth(int u, int p){
        
        depth[u] = p;
        if(tree[u].left != NIL){
            setDepth(tree[u].left, p+1);
        }
        if(tree[u].right != NIL){
            setDepth(tree[u].right, p+1);
        }
    }
    
    static int setHeight(int u){
        
        int h1 = 0;
        int h2 = 0;
        if(tree[u].left != NIL){
            h1 = setHeight(tree[u].left) +1;
        }
        if(tree[u].right != NIL){
            h2 = setHeight(tree[u].right) +1;
        }
        height[u] = Math.max(h1, h2);
        return height[u];
    }
    
    static int getSibling(int u){
        
        int parent = tree[u].parent;
        if(parent == NIL){
            return NIL;
        }else{
            if(tree[parent].left != NIL && tree[parent].left != u){
                return tree[parent].left;
            }else if(tree[parent].right != NIL && tree[parent].right != u){
                return tree[parent].right;
            }else{
                return NIL;
            }
        }
    }
    
    static int getDegree(int u){
        
        int d = 0;
        if(tree[u].left != NIL) d++;
        if(tree[u].right != NIL) d++;
        return d;
    }
    
    static String getType(int u){
        
        if(tree[u].parent == NIL){
            return "root";
        }else if(tree[u].left != NIL || tree[u].right != NIL){
            return "internal node";
        }else{
            return "leaf";
        }
    }
    
    static class Node {
        int parent, left, right;

        public Node() {
            parent = NIL;
            left = NIL;
            right = NIL;
        }
    }
}
