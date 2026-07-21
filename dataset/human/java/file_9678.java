import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.StreamTokenizer;
import java.util.InputMismatchException;
 
 
public class Main {
 
    public static Node[] nodes;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        Printer pr = new Printer(System.out);
 
        int n = sc.nextInt();
        nodes = new Node[n];
         
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            nodes[id] = new Node(id, sc.nextInt(), sc.nextInt());
        }
 
        for (int i = 0; i < n; i++) {
            setParent(i);
        }
        int root = seekRoot();
        setDepth(root, 0);
        for (int i = 0; i < n; i++) {
            setHeight(i);
        }
 
 
        for (int i = 0; i < n; i++) {
            pr.println(nodes[i].toString());
        }
         
        pr.close();
        sc.close();
    }
     
    private static void setParent(int id) {
        nodes[id].degree = 0;
        if (nodes[id].l_child != -1) {
            nodes[nodes[id].l_child].parent = id;
            nodes[id].degree++;
        }
        if (nodes[id].r_child != -1) {
            nodes[nodes[id].r_child].parent = id;
            nodes[id].degree++;
        }
    }
     
    private static int seekRoot() {
        for (int i = 0; i < nodes.length; i++) {
            if (nodes[i].parent == -1){
                return i;
            }
        }
         
        return -1;
    }
     
    private static void setDepth(int id, int depth) {
        if (nodes[id].parent == -1) {
            nodes[id].type = NodeType.ROOT;
        } else {
            if (nodes[id].degree == 0) {
                nodes[id].type = NodeType.LEAF;
                nodes[id].height = 0;
            } else {
                nodes[id].type = NodeType.INTERNAL_NODE;
                nodes[id].height = -1;
            }
        }
        nodes[id].depth = depth;
 
        if (nodes[id].degree == 2) {
            nodes[nodes[id].l_child].sibling = nodes[id].r_child;
            nodes[nodes[id].r_child].sibling = nodes[id].l_child;
        }
         
        if (nodes[id].l_child != -1) {
            setDepth(nodes[id].l_child, depth + 1);
        }
        if (nodes[id].r_child != -1) {
            setDepth(nodes[id].r_child, depth + 1);
        }
 
        return;
    }
         
    private static void setHeight(int id) {
        if (nodes[id].height != 0) {
            return;
        } else {
            for (int j = nodes[id].parent, h = 0; j != -1; j = nodes[j].parent, h++) {
                if (nodes[j].height < h + 1) {
                    nodes[j].height = h + 1;
                }
            }
        }
    }
 
    private static enum NodeType {
        ROOT, INTERNAL_NODE, LEAF;
    }
     
    private static class Node {
        public int id;
        public int parent;
        public int l_child;
        public int r_child;
        public int sibling;
        public int depth;
        public int height;
        public int degree;
        public NodeType type;
     
        public Node(int id, int l_child, int r_child) {
            this.id = id;
            this.l_child = l_child;
            this.r_child = r_child;
            this.sibling = -1;
            this.parent = -1;
        }
         
        @Override
        public String toString() {
            StringBuffer str = new StringBuffer();
 
            str.append("node ");
            str.append(id);
            str.append(": parent = ");
            str.append(parent);
            str.append(", sibling = ");
            str.append(sibling);
            str.append(", degree = ");
            str.append(degree);
            str.append(", depth = ");
            str.append(depth);
            str.append(", height = ");
            str.append(height);
            str.append(", ");
            String type;
            switch (nodes[id].type) {
            case INTERNAL_NODE:
                type = "internal node";
                break;
            case LEAF:
                type = "leaf";
                break;
            case ROOT:
                type = "root";
                break;
            default:
                type = null;
            }
            str.append(type);
             
            return str.toString();
        }
    }
 
 
    private static class Scanner {
        InputStreamReader isr;
        BufferedReader br;
        StreamTokenizer st;
         
        Scanner (InputStream in) {
            isr = new InputStreamReader(in);
            br = new BufferedReader(isr);
            st = new StreamTokenizer(br);
        }
         
        String next() throws RuntimeException  {
            try {
                if (st.nextToken() != StreamTokenizer.TT_WORD) {
                }
            } catch (IOException e) {
                throw new IllegalStateException();
            }
             
            return st.sval;
        }
         
        int nextInt() throws RuntimeException {
            try {
                if (st.nextToken() != StreamTokenizer.TT_NUMBER) {
                    throw new InputMismatchException();
                }
            } catch (IOException e) {
                throw new IllegalStateException();
            }
             
            return (int)st.nval;
        }
 
        void close() {
        }
    }
     
    private static class Printer {
        PrintStream out;
        StringBuffer strbuf;
        int bufSize;
        final String CR;
 
        Printer(PrintStream out) {
            this.out = out;
            strbuf = new StringBuffer();
            bufSize = 64 * 1024;
            CR = System.getProperty("line.separator");
        }
 
        void println(String str) {
            strbuf.append(str);
            strbuf.append(CR);
            checkStringBuffer();
        }
 
        void print(String str) {
            strbuf.append(str);
            checkStringBuffer();
        }
 
        void println(int n) {
            strbuf.append(n);
            strbuf.append(CR);
            checkStringBuffer();
        }
 
        void print(int n) {
            strbuf.append(n);
            checkStringBuffer();
        }
 
        void print(char c) {
            strbuf.append(c);
            checkStringBuffer();
        }
 
        void printArray(int[] array) {
            for (int i = 0; i < array.length; i++) {
                checkStringBuffer();
                strbuf.append(array[i]);
                strbuf.append(" ");
            }
            strbuf.delete(strbuf.length() - 1, strbuf.length());
            strbuf.append(CR);
        }
 
        void close() {
            flashStringBuffer();
        }
         
        private void flashStringBuffer() {
            if (strbuf.length() > 0) {
                out.print(strbuf);
                strbuf.setLength(0);
            }
        }
         
        private void checkStringBuffer() {
            if (strbuf.length() > bufSize) {
                out.print(strbuf);
                strbuf.setLength(0);
            }
        }
    }
}
