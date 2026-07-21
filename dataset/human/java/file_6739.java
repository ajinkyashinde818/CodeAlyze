import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);;

    public static void main(String[] args) {
        int K = sc.nextInt();
        int N = sc.nextInt();
        int A1 = sc.nextInt();
        int prev = A1;
        int gap = 0;
        for (int i = 1; i < N; i++) {
            int A = sc.nextInt();
            if (gap < A - prev) {
                gap = A - prev;
            }
            prev = A;
        }
        if (gap < (A1 - prev + K) % K) {
            gap = (A1 - prev + K) % K;
        }
        System.out.println(K - gap);
    }
}
