import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.LinkedList;

public class Main {
    public static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

    public static int nextInt() {
        try {
            in.nextToken();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return (int) in.nval;
    }

    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        in.nextToken();
        String s = in.sval;
        LinkedList<Character> st = new LinkedList<Character>();
        int len = s.length();
        for (int i = 0; i < len; i++)
            st.add(s.charAt(i));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = nextInt();
        boolean a = false;
        for (int i = 0; i < n; i++) {
            int op = nextInt();
            if (op == 1)
                a = !a;
            else {
                int x = nextInt();
                in.nextToken();
                String c = in.sval;
                if ((x == 1 && !a) || (x == 2 && a))
                    st.addFirst(c.charAt(0));
                else
                    st.addLast(c.charAt(0));
            }
        }
        if (!a)
            while (!st.isEmpty())
                out.print(st.pollFirst());
        else {
            while (!st.isEmpty())
                out.print(st.pollLast());
        }
        out.flush();
    }

}
