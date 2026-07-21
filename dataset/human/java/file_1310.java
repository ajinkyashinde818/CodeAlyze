import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        System.out.println( solve(N, A) );
    }

    private static long solve(int N, int[] A) {
        long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
        }

        long ans = Long.MAX_VALUE;
        long x = 0;
        for (int i = 0; i < N-1; i++) {
            x += A[i];
            long y = sum - x;
            long abs = Math.abs(x - y);

            if( abs < ans ) {
                ans = abs;
            }
        }
        return ans;
    }
}
