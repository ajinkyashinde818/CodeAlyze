import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        try (Scanner in = new Scanner(System.in)) {
            int A = in.nextInt();
            int B = in.nextInt();
            int K = in.nextInt();
            int[] a = new int[100];
            int k = 0;
            for (int n = 1; n <= 100; n++) {
                if (A % n == 0 && B % n == 0) {
                    a[k] = n;
                    k++;
                }
            }

            for (int i = 0; i < K; i++) {
                k--;
            }

//            Utils.debug(a, k, K);
            System.out.println(a[k]);
        }
    }
}
