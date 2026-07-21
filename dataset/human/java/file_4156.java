import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.stream.Collectors;

class Main {

    private static PrintWriter out;

    private static void mprintln(Object... ar) {
        for (Object i : ar) {
            out.print(i + " ");
        }
        out.println();
    }

    public static void main(String[] args) throws FileNotFoundException {

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

    private static void getAns(MyScanner sc) {
        int n = sc.ni();
        int[] ar = sc.niArr1(n);
        int[] br = sc.niArr1(n);
        int[] cr = sc.niArr1(n - 1);

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            ans += br[ar[i]];
            if (i > 1 && ar[i] - ar[i - 1] == 1) ans += cr[ar[i - 1]];
        }

        out.println(ans);
    }

    static class MyScanner {

        BufferedReader br;
        StringTokenizer st;

        MyScanner(FileReader fileReader) {
            br = new BufferedReader(fileReader);
        }

        MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nn() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            String ans = "";
            try {
                ans = br.readLine();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
            return ans;
        }

        char nc() {
            return nn().charAt(0);
        }

        int ni() {
            return Integer.parseInt(nn());
        }

        long nl() {
            return Long.parseLong(nn());
        }

        double nd() {
            return Double.parseDouble(nn());
        }

        int[] niArr0(int n) {
            int[] ar = new int[n];
            for (int i = 0; i < n; i++) {
                ar[i] = ni();
            }
            return ar;
        }

        int[] niArr1(int n) {
            int[] ar = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                ar[i] = ni();
            }
            return ar;
        }

        long[] nlArr0(int n) {
            long[] ar = new long[n];
            for (int i = 0; i < n; i++) {
                ar[i] = nl();
            }
            return ar;
        }

        long[] nlArr1(int n) {
            long[] ar = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                ar[i] = nl();
            }
            return ar;
        }
    }
}
