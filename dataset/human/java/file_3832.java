import java.util.*;
import java.math.*;
import java.io.*;
import java.text.*;

class Main {

    //public static PrintWriter pw;
    public static PrintWriter pw = new PrintWriter(System.out);

    public static  void solve() throws IOException {
        //	pw=new PrintWriter(new FileWriter("C:\\Users\\shree\\Downloads\\small_output_in"));
        FastReader sc = new FastReader();
        String s1=sc.next();
        String s2=new String(s1);
        s2=s2.replaceAll("x","");
        if(!isPalindrome(s2)){
            pw.println(-1);
            pw.close();
            return;
        }
        int ans=0;
        int i=0,j=s1.length()-1;
        while(i<j){
            if(s1.charAt(i)!=s1.charAt(j)){
                if(s1.charAt(i)=='x'){
                    i++;

                }else j--;
                ans++;
            } else {
                i++; j--;
            }
        }
        pw.println(ans);
        pw.close();

    }
    static boolean isPalindrome(String s2){
        int i=0,j=s2.length()-1;
        while(i<j){
            if(s2.charAt(i)!=s2.charAt(j)) return false;
            i++; j--;
        }
        return true;
    }


    public static void main(String[] args) {
        new Thread(null, new Runnable() {
            public void run() {
                try {

                    solve();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }, "1", 1 << 26).start();

    }

    static BufferedReader br;
    static long M = (long) 1e9 + 7;

    static class FastReader {

        StringTokenizer st;

        public FastReader() throws FileNotFoundException {
            //br=new BufferedReader(new FileReader("C:\\Users\\shree\\Downloads\\B-small-practice.in"));
            br = new BufferedReader(new InputStreamReader(System.in));

        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int I() {
            return Integer.parseInt(next());
        }

        long L() {
            return Long.parseLong(next());
        }

        double D() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public boolean hasNext() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                String s = br.readLine();
                if (s == null) {
                    return false;
                }
                st = new StringTokenizer(s);
            }
            return true;
        }

    }
}
