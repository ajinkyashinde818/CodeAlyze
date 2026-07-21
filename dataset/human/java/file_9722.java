import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
    static node[] t;
    public static void main(String[] args) throws IOException{
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int n = Integer.parseInt(br.readLine());
        t = new node[n];
        for(int i = 0; i<n; i++)
            t[i] = new node();
        for(int i = 0; i<n; i++){
            final StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            final int id = Integer.parseInt(st.nextToken());
            final int left = Integer.parseInt(st.nextToken());
            final int right = Integer.parseInt(st.nextToken());
            if(left!=-1) t[left].parent = id;
            if(right!=-1) t[right].parent = id;
            t[id].left = left;
            t[id].right = right;
            if(left!=-1&&right!=-1){
                t[left].sibling = right;
                t[right].sibling = left;
            }
        }
        int root = 0;
        while(t[root].parent!=-1)
            root = t[root].parent;
        setdh(root, 0);
        final StringBuilder sb = new StringBuilder();
        for(int i = 0; i<n; i++){
            int degree = 0;
            if(t[i].left!=-1) degree++;
            if(t[i].right!=-1) degree++;
            sb.append("node "+i+": parent = "+t[i].parent+", sibling = "+t[i].sibling+", degree = "+degree+", depth = "+t[i].depth+", height = "+t[i].height+", ");
            if(t[i].parent==-1) sb.append("root\n");
            else if(degree==0) sb.append("leaf\n");
            else sb.append("internal node\n");
        }
        System.out.print(sb);
    }
    static int setdh(int id, int d){
        if(id==-1) return 0;
        t[id].depth = d;
        t[id].height = Math.max(setdh(t[id].left, d+1), setdh(t[id].right, d+1));
        return t[id].height+1;
    }
}

class node{
    int parent;
    int left;
    int right;
    int sibling;
    int depth;
    int height;
    node(){
        parent = -1;
        left = -1;
        right = -1;
        sibling = -1;
        depth = -1;
        height = -1;
    }
}
