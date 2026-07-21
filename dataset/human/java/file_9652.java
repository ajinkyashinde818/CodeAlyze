//package atcoder.beginner_179;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main (String[] args) throws Exception {

        String s = "5\n" +
                "1 2\n" +
                "6 6\n" +
                "4 4\n" +
                "3 3\n" +
                "3 2";

//        br = new BufferedReader(new StringReader(s));
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        rl(); int n=nin();
        boolean res = false;
        int c=0;
        for (int i = 0; i<n; ++i) {
            rl();
            if (nin() == nin()) {
                ++c;
            } else {
                c=0;
            }
            if (c==3) res = true;
        }
        bw.write((res ? "Yes" : "No") + "\n");
        bw.flush();

    }

    static BufferedReader br;
    static BufferedWriter bw;
    static StringTokenizer st;
    static void rl() throws Exception{
        st = new StringTokenizer(br.readLine());
    }
    static long nlo(){
        return Long.parseLong(st.nextToken());
    }
    static int nin(){
        return Integer.parseInt(st.nextToken());
    }
    /*private static void te(){
      }*/
    static double ndo(){
        return Double.parseDouble(st.nextToken());
    }
    static char[] nca(){
        return st.nextToken().toCharArray();
    }
    static String nstr(){
        return st.nextToken();
    }
}
