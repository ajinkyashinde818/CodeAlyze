import java.util.Scanner;
import java.util.Arrays;

class Main {
    public static void main(String... args) {
        int D = IN.nextInt();
        int G = IN.nextInt();
        int[] p = new int[D + 1];
        int[] c = new int[D + 1];
        // pad index 0
        for (int i = 1; i <= D; i++) {
            p[i] = IN.nextInt();
            c[i] = IN.nextInt();
        }
        int[] complete = new int[D + 1];
        for (int i = 1; i <= D; i++) {
            complete[i] = 100 * i * p[i] + c[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < (1 << D); i ++) {
            int score = 0;
            int num = 0;
            for (int j = 1; j <= D; j++) {
                int k = 1 << (j - 1);
                if ((i & k) > 0) {
                    score += complete[j];
                    num += p[j];
                }
            }
            if (score >= G) {
                ans = num < ans ? num : ans;
            } else {
                int notCompInd = 0;
                for (int m = 0; m < D; m++) {
                    if (((~i >> m) & 1) == 1) {
                        notCompInd = m + 1;
                    }
                }
                if (notCompInd == 0) {
                    continue;
                }
                int solvNum = (G - score) / (notCompInd * 100);
                if (((G - score) % (notCompInd * 100)) > 0) {
                    solvNum++;
                }
                if (solvNum > (p[notCompInd] - 1)) {
                    continue;
                }
                num += solvNum;
                ans = num < ans ? num : ans;
            }
        }
        puts(ans);
    }

    static final Scanner IN = new Scanner(System.in);
    static <T> void puts(T arg) { System.out.println(arg); }
}
