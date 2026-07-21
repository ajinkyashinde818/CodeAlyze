import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        for (int i = 0; i < N; i++) {
            B[i] = scanner.nextInt();
        }
        for (int i = 0; i < N-1; i++) {
            C[i] = scanner.nextInt();
        }

        long ans = 0;
        int good = Integer.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            ans += B[A[i]-1];
            if((good +1) == A[i]) {
                ans += C[A[i]-2];
            }
//                System.out.println("good = " + (good+1) + " a[i] " + A[i] );
            good = A[i];
//            System.out.println(" i = " + i + " ans" + ans + " B[i] " + B[A[i]-1]);
        }
        System.out.println(ans);
    }
}
