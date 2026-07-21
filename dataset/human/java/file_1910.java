import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int D = sc.nextInt();
        int G = sc.nextInt();
        int[] p = new int[D];
        int[] c = new int[D];

        for (int i = 0; i<D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        int ans = Integer.MAX_VALUE;

        for (int mask=0; mask<(1<<D); mask++) {
            int score = 0, num = 0, rest_max = -1;

            for (int i=0; i<D; i++) {
                if ((mask>>i & 1) == 1) {
                    score += 100 * (i+1) * p[i] + c[i];
                    num += p[i];
                } else {
                    rest_max = i;
                }
            }

            if (score < G) {
                int s1 = 100 * (rest_max + 1);
                int need = (G - score + s1 - 1) / s1;
                if (need >= p[rest_max]) {
                    continue;
                }

                num += need;
            }
            ans = Math.min(ans, num);
        }
        System.out.println(ans);
    }

}
