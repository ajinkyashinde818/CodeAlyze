import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[]a = sc.nextIntArr(n);
        int[]b = sc.nextIntArr(n);
        Stack<Integer>[]ids= new Stack[n+1];
        for (int i =0;i<=n;i++)ids[i]=new Stack<>();
        int sum=0;
        for (int i =0;i<n;i++){
            if (a[i]==b[i]){
                ids[b[i]].add(i);
            }
        }
        Stack<Integer>cur = new Stack<>();
        for (int i =0;i<=n;i++){
            while (!cur.isEmpty()&&!ids[i].isEmpty()){
                int c= cur.pop();
                int d = ids[i].pop();
                int t =b[c];
                b[c]=b[d];
                b[d]=t;
            }
            while (!ids[i].isEmpty())cur.add(ids[i].pop());
        }
        if (!cur.isEmpty()){
            for (int i =0;i<n&&!cur.isEmpty();i++){
                if (a[i]!=b[cur.peek()]&&b[i]!=b[cur.peek()]){
                    int t = b[cur.peek()];
                    b[cur.pop()]=b[i];
                    b[i]=t;
                }
            }
            if (cur.isEmpty()){
                pw.println("Yes");
                for (int i =0;i<n;i++)
                    pw.print(b[i]+" ");
                pw.println();
            }
            else pw.println("No");
        }
        else {
            pw.println("Yes");
            for (int i =0;i<n;i++)
                pw.print(b[i]+" ");
            pw.println();
        }
        pw.flush();
    }
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader f) {
            br = new BufferedReader(f);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public int[] nextIntArr(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(next());
            }
            return arr;
        }

    }

}
