import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = new int[M];
        int[] B = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = sc.nextInt();
            B[i] = sc.nextInt();
        }
        System.out.println( solve(N, M, A, B) );
    }

    private static String solve(int N, int M, int[] A, int[] B) {
        Set<Integer> from_1 = new HashSet<>();
        for (int i = 0; i < M; i++) {
            int a = A[i];
            int b = B[i];

            if( a == 1 ) {
                from_1.add(b);
            } else if( b == 1 ) {
                from_1.add(a);
            }
        }

        for (int i = 0; i < M; i++) {
            int a = A[i];
            int b = B[i];

            if( a == N && from_1.contains(b) ) return "POSSIBLE";
            if( b == N && from_1.contains(a) ) return "POSSIBLE";
        }
        return "IMPOSSIBLE";
    }
}
