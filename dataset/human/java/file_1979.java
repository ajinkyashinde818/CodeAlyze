import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] a = new int[N];
        int[] b = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        long vMax = 0;
        for (int i = 0; i < 30; i++) {
            long vCur = 0;
            if (i == 0) {
                for (int j = 0; j < N; j++) {
                    if ((~K & a[j]) == 0) {
                        vCur += b[j];
                    }
                }
            } else if ((K >> i & 1) == 1) {
                for (int j = 0; j < N; j++) {
                    if (((~(K >> i & ~1) << i) & (a[j] >> i << i)) == 0) {
                        vCur += b[j];
                    }
                }
            }
            vMax = Math.max(vMax, vCur);
        }
        System.out.println(vMax);
    }
}
