/*  
 * @author : poindexter_21
 */
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    
    static MyScanner sc = new MyScanner();
    static Scanner scn = new Scanner(System.in);
    
    public static void main(String[] args) {
        
        long n = sc.nextLong();
        long count = 0, temp = n;
        int[] primefactor = new int[(int)1e7];
        
        for(long i = 2; i * i <= n + 3; ++i) {
            
            while(temp % i == 0) {
                
                primefactor[(int)i]++;
                temp /= i;
            }
        }
        
        for(long i = 2; i * i <= n + 3; ++i) {
            
            int curr = primefactor[(int)i];
            for(int j = 1; j <= curr; ++j) {
                
                curr -= j;
                ++count;
            }
        }
         
        if(temp > 1) ++count;
        
        out.println(count);
        
        out.close();
    }

    /**
     * *********************************************************************************************
     */
    static final int MOD = (int) 1e9 + 7;
    static final double PI = 3.14159265358979323846;

    // array of int type taking input
    public static int[] init(int n) {
        
        int[] arr = new int[n];
        
        for (int i = 0; i < n; ++i) {
            arr[i] = sc.nextInt();
        }
        
        return arr;
    }

    //return gcd of two numbers
    public static int gcd(int a, int b) {
        
        if (a == 0) {
            return b;
        }
        
        return gcd(b % a, a);
    }

    //checks whether a number is prime or not
    public static boolean prime(int n) {
        
        if (n < 2) {
            return false;
        }
        
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    }

    // Pair Class
    static class Pair<S extends Comparable<S>, T extends Comparable<T>> implements Comparable<Pair<S, T>> {
        
        S first;
        T second;
        
        public Pair() {
        }
        
        Pair(S f, T s) {
            first = f;
            second = s;
        }
        
        public S getX() {
            return this.first;
        }
        
        public T getY() {
            return this.second;
        }
        
        @Override
        public int compareTo(Pair<S, T> o) {
            int t = first.compareTo(o.first);
            if (t == 0) {
                return second.compareTo(o.second);
            }
            return t;
        }
        
        public void show() {
            System.out.println("[" + this.getX() + " , " + this.getY() + "]");
        }
        
        @Override
        public int hashCode() {
            return (31 + first.hashCode()) * 31 + second.hashCode();
        }
        
        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Pair)) {
                return false;
            }
            if (o == this) {
                return true;
            }
            Pair p = (Pair) o;
            return first.equals(p.first) && second.equals(p.second);
        }
        
        @Override
        public String toString() {
            return "Pair{" + first + ", " + second + "}";
        }
    }

    /**
     *********************************************************************************************
     */
    /**
     * Fast Input/ Output *
     */
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        
        BufferedReader br;
        StringTokenizer st;
        
        public MyScanner() {
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
        
        int nextInt() {
            return Integer.parseInt(next());
        }
        
        long nextLong() {
            return Long.parseLong(next());
        }
        
        double nextDouble() {
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
    }
}
