import java.math.BigDecimal;
import java.util.*;
import java.util.stream.Collectors;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        int G = sc.nextInt();
        int[] p = new int[D];
        int[] c = new int[D];
        for(int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        int sumCnt = Integer.MAX_VALUE;
        for (int i = 0; i < Math.pow(2, D); i++) {
            int result = 0;
            int cnt = 0;
            int rest = 0;
            for (int j = 0; j < D; j++) {
                if ((1 << j & i) != 0) {
                    result += (j + 1) * 100 * p[j] + c[j];
                    cnt += p[j];
                } else {
                    rest = j;

                }
            }
            if (result < G) {
                int need = (int) Math.ceil((G - result) / ((rest + 1) * 100F));
                if (need > p[rest]) {
                    continue;
                }
                cnt += Math.ceil((G - result) / ((rest + 1) * 100F));
            }
            sumCnt = Math.min(sumCnt, cnt);
        }
        System.out.println(sumCnt);
    }
}
