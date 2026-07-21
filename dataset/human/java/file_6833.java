import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    static class FastScanner {
        BufferedReader br, br1;
        StringTokenizer st;
        public FastScanner() {br = new BufferedReader(new InputStreamReader(System.in));}
        public FastScanner(String fileName) throws FileNotFoundException{br = new BufferedReader(new FileReader(fileName));}
        String next() {while (st == null || !st.hasMoreElements()){try{st = new StringTokenizer(br.readLine());}catch (IOException  e){e.printStackTrace();}}return st.nextToken();}
        int nextInt() {return Integer.parseInt(next());}
        long nextLong() {return Long.parseLong(next());}
        double nextDouble() {return Double.parseDouble(next());}
        char[][] readCharArray(int n, int m) {
        	String str;
        	char[][] arr = new char[n][m];
        	for(int i = 0; i < n; ++i) {
        		str=nextLine();
        		for(int j = 0;j < n; ++j) {
        			arr[i][j] = str.charAt(j);
        		}
        	}
        	return arr;
        }
        char[][] readCharArray(int n) {
        	return readCharArray(n,n);
        }
        int[] readArray(int n) {int[] a = new int[n]; for (int i = 0; i < n; ++i) a[i] = nextInt(); return a;}
        long[] readLongArray(int n) {long[] a=new long[n];for (int i = 0; i < n; ++i) a[i] = nextLong(); return a;}
        String nextLine() {String str = "";try{str = br.readLine();} catch (IOException e){e.printStackTrace();} return str;}
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int k = fs.nextInt(), n = fs.nextInt();
        int a[] = fs.readArray(n);
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans = Math.max(ans, a[i + 1] - a[i]);
        }
        ans = Math.max(ans, k - a[n - 1] + a[0]);
        out.println(k - ans);
        out.close();
    }
}
