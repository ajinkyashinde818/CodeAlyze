import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    private static PrintWriter out;

    private static <T> void mprintln(T ... ar){
        for(T i: ar) out.print(i + " ");
        out.println();
    }

    public static void main(String[] args) throws FileNotFoundException{

        // Input from file
        // File inputFile = new File("JavaFile.txt");
        // File outputFile = new File("JavaOutputFile.txt");
        // FileReader fileReader = new FileReader(inputFile);
        // Here it ends

        MyScanner sc = new MyScanner();
        // MyScanner sc = new MyScanner(fileReader);

        out = new PrintWriter(new BufferedOutputStream(System.out)); // Output to console
        // out = new PrintWriter(new PrintStream(outputFile)); // Output to file

        getAns(sc);

        out.close();
    }

    /*
     *Don't use builtin function (Math.ceil)
     */

    static final long MOD = (long) (1e9 + 7);

    private static void getAns(MyScanner sc){
        int n = sc.ni();
        char[] ar = sc.nn().toCharArray();
        int[] count = new int[26];
        for(char ch: ar) ++count[ch - 'a'];

        long ans = modPow(2, n) - 1;
        if(ans < 0) ans += MOD;
        long mul = 1;

        for (int i = 0; i < count.length; i++) {
            int in = count[i];
            if(in <= 1){
                n -= in;
                continue;
            }
            long one = modPow(2, in) - 1 - in;
            if (one < 0) one += MOD;
//            out.println("One: " + one);

            long two = modPow(2, n - in);
//            out.println("Two: " + two);

            long temp = (one * two) % MOD;

            for(int j = 0; j < i; j++) temp = (temp * (count[j] + 1)) % MOD;

            ans -= temp;
            if (ans < 0) ans += MOD;

            n -= in;
        }

        out.println(ans);
    }

    private static long modPow(long x, long y) {
        long res = 1;

        while (y > 0){
            if(y % 2 == 1)
                res = (res * x) % MOD;

            y >>= 1;
            x = (x * x) % MOD;
        }

        return res;
    }

    static class MyScanner{
        BufferedReader br;
        StringTokenizer st;

        MyScanner(FileReader fileReader){
            br = new BufferedReader(fileReader);
        }

        MyScanner(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nn(){
            while(st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch(IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine(){
            String ans = "";
            try {
                ans = br.readLine();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
            return ans;
        }

        char nc(){
            return nn().charAt(0);
        }

        int ni(){
            return Integer.parseInt(nn());
        }

        long nl(){
            return Long.parseLong(nn());
        }

        double nd(){
            return Double.parseDouble(nn());
        }

        int[] niArr0(int n){
            int[] ar = new int[n];
            for(int i = 0; i < n; i++) ar[i] = ni();
            return ar;
        }

        int[] niArr1(int n){
            int[] ar = new int[n + 1];
            for(int i = 1; i <= n; i++) ar[i] = ni();
            return ar;
        }

        long[] nlArr0(int n){
            long[] ar = new long[n];
            for(int i = 0; i < n; i++) ar[i] = nl();
            return ar;
        }

        long[] nlArr1(int n){
            long[] ar = new long[n + 1];
            for(int i = 1; i <= n; i++) ar[i] = nl();
            return ar;
        }
    }
}
