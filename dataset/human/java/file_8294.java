import java.io.*;
import java.util.*;

public class Main{

    public static void main(String[] args) throws IOException {
        Reader.init();
        long A=Reader.nextLong();
      	long B=Reader.nextLong();
      	println(lcm(A, B));
    }

    static int mod=1000000007;
    public static void read(int arr[], int N) throws IOException{ for(int i=0;i<N;i++){ arr[i]=Reader.nextInt(); } }
    public static void read(long arr[], int N) throws IOException{ for(int i=0;i<N;i++){ arr[i]=Reader.nextLong(); } }
    public static void read(String arr[], int N) throws IOException{ for(int i=0;i<N;i++){ arr[i]=Reader.next(); } }
    public static void print(Object O){ System.out.print(O); }
    public static void println(Object O){ System.out.println(O); }
    public static void display(int arr[]){ System.out.println(Arrays.toString(arr)); }
    public static void display(int arr[][], int N){ for(int i=0;i<N;i++){ System.out.println(Arrays.toString(arr[i])); } }
  	static long gcd(long x, long y) { return y==0 ? x : gcd(y, x % y); }
    static long lcm(long x, long y) { return x*y / gcd(x, y); }
}


class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init() {
        reader=new BufferedReader(new InputStreamReader(System.in));
        tokenizer=new StringTokenizer("");
    }

    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens() ) {
            tokenizer=new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException { return Integer.parseInt(next()); }
    static double nextDouble() throws IOException { return Double.parseDouble(next()); }
    static long nextLong() throws IOException { return Long.parseLong(next()); }
    static String nextLine() throws IOException { return reader.readLine(); }
}
