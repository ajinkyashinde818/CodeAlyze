import java.util.Scanner;

class Solver {
    void solve(Scanner sc) {
        int N = sc.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N - 1];
        for (int i = 0; i < A.length; i++) {
            A[i] = sc.nextInt() - 1;
        }
        for (int i = 0; i < B.length; i++) {
            B[i] = sc.nextInt();
        }
        for (int i = 0; i < C.length; i++) {
            C[i] = sc.nextInt();
        }
        int sum = B[A[0]];
        for (int i = 1; i < N; i++) {
            int prev = A[i - 1];
            int next = A[i];
            if (prev + 1 == next) sum += C[prev];
            sum += B[next];
        }
        System.out.println(sum);
    }
}

class Main {
    public static void main(String... args) {
        Scanner in = new Scanner(System.in);

        new Solver().solve(in);

        in.close();
    }
}
