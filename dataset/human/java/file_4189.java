import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N];
        for(int n = 0; n < N; n++) {
            A[n] = sc.nextInt();
        }
        for(int n = 0; n < N; n++) {
            B[n] = sc.nextInt();
        }
        for(int n = 0; n < N-1; n++) {
            C[n] = sc.nextInt();
        }

        int X = 0;
        int Y = A[0];
        X = X + B[Y-1];

        for (int i = 1; i < N; i++) {
            Y = A[i]-1;
            if (A[i] - A[i-1] == 1) {
                X = X + B[Y] + C[Y-1];
            }
            else {
                X = X + B[Y];
            }
        }
        System.out.println(X);
    }
}
