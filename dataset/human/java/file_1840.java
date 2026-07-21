import java.util.*;
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        long G = sc.nextLong();
        int[] P = new int[D];
        int[] C = new int[D];
        for (int i = 0; i < D;i++) {
            P[i] = sc.nextInt();
            C[i] = sc.nextInt();
        }
        int res = Integer.MAX_VALUE;
        int score = 0;
        int num = 0;
        // Find case whether we get all question of specific point or none of them
        for (int bit = 0; bit < (1<<D); bit++) {
            score = 0;
            num = 0;
            for(int i = 0; i < D; i++) {
                if ((bit & (1<<i)) != 0) {
                    score += 100 * P[i] * (i + 1) + C[i];
                    num += P[i];
                }
            }
            if(score < G) {
                for (int i = D - 1; i >= 0; i--) {
                    if ((bit & (1<<i)) == 0) {
                        for(int j = 0; j < P[i] - 1; j++) {
                            score +=  100* (i + 1);
                            num += 1;
                            if (score >= G) {
                                break;
                            }
                        }
                    }
                    if (score >= G) {
                        break;
                    }
                }
            }
            if (score >= G) {
                res = Math.min(res, num);
            }
        }
        System.out.println(res);
    }
}
