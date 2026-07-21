import java.awt.*;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

public class Main {

    static String br = System.getProperty("line.separator");
    static Scanner sc = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int N = nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N];

        for(int i=0; i<N; i++){
            A[i] = nextInt();
        }
        for(int i=0; i<N; i++){
            B[i] = nextInt();
        }
        for(int i=0; i<N-1; i++){
            C[i] = nextInt();
        }

        int count = 0;
        for(int i=0; i<N; i++){
            count += B[A[i]-1];
            if(i != 0 && A[i]-A[i-1]==1){
                count += C[A[i-1]-1];
            }
        }

        println(count);
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static Long nextLong() {
        return Long.parseLong(next());
    }

    static String next() {
        return sc.next();
    }

    static String nextLine(){
        return sc.nextLine();
    }

    static void println(Object o) {
        out.println(o);
        out.flush();
    }

    static void print(Object o) {
        PrintWriter out = new PrintWriter(System.out);
        out.print(o);
        out.flush();
    }
}
