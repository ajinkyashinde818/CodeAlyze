import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            int A = sc.nextInt();
            int B = sc.nextInt();

            System.out.println(lcm(A, B));
        }
    }

    static long gcd(long M, long N) {
        if (M < N) {
            return gcd(N, M);
        }
        return N > 0 ? gcd(N, M % N) : M;
    }

    static long lcm(long M, long N) {
        return M * N / gcd(M, N);
    }

}
