import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    static String br = System.getProperty("line.separator");
    static Scanner sc = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int N = nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N-1];

        int Answer = 0;

        for(int i=0; i<N; i++){
            A[i] = nextInt();
        }
        for(int i=0; i<N; i++){
            B[i] = nextInt();
        }
        for(int i=0; i<N-1; i++){
            C[i] = nextInt();
        }

        for (int i=1; i<N; i++) {
        	if (A[i] - 1 == A[i - 1]) {
        		int test = A[i - 1] - 1;
        		Answer += C[test];
        	}
        	Answer += B[i];
        }

        Answer += B[0];

        println(Answer);
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
