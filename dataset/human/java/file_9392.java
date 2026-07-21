import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        var x = new ArrayList<Integer>();
        for (int i = 0; i<n; i++) {
            x.add(fs.nextInt());
            x.add(fs.nextInt());
        }
        int c = 0;
        String ans = "No";
        for (int i = 0; i<x.size()-1; i++) {
            if (x.get(i) == x.get(i+1)) {
                c++;
                i++;
            } else {
                c=0;
            }
            if (c==3) {
                ans = "Yes";
                break;
            }
        }
        System.out.println(ans);


    }


    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }

}
