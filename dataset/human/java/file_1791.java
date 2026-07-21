import java.util.Scanner;

// bit全探索、greedy
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        long G = sc.nextInt();
        long[] C = new long[D];
        long[] P = new long[D];
        for (int i = 0; i < D; i++) {
            P[i] = sc.nextInt();
            C[i] = sc.nextInt();
        }

        long res = 1 << 29;
        for (int bit = 0; bit < (1 << D); bit++) {
            long sum = 0;
            long num = 0;
            for (int i = 0; i < D; i++) {
                if (((bit >> i) & 1) == 1) {
                    sum += C[i] + P[i] * 100 * (i + 1);
                    num += P[i];
                }
            }
            if (sum >= G) {
                res = Math.min(res, num);
            } else {
                for (int i = D - 1; i >= 0; --i) {
                    if (((bit >> i) & 1) == 1) continue;
                    for (int j = 0; j < P[i]; ++j) {
                        if (sum >= G) break;
                        sum += 100 * (i + 1);
                        ++num;
                    }
                }
                res = Math.min(res, num);
            }
        }
        System.out.println(res);
    }

}
