import java.util.Scanner;

public class Main {
    //Buffet
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) A[i] = sc.nextInt() - 1;
        int[] B = new int[n];
        for (int i = 0; i < n; i++) B[i] = sc.nextInt();
        int[] C = new int[n - 1];
        for (int i = 0; i < n - 1; i++) C[i] = sc.nextInt();
        System.out.println(sln(A, B, C, n));
        sc.close();
    }

    private static int sln(int[] A, int[] B, int[] C, int n) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += B[i];
            if (i > 0 && A[i] - A[i - 1] == 1) res += C[A[i] - 1];
        }
        return res;
    }
}
