import java.util.*;
import java.util.stream.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int D = in.nextInt(), G = in.nextInt();
        int[] p = new int[D], c = new int[D];
        for(int i = 0; i < D; i++) {
            p[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        int ans = Integer.MAX_VALUE;
        int loop = (int)Math.pow(2, D);
        for(int k = 0; k < loop; k++)  {
            int sum = 0, restMax = -1, cnt = 0;
            for(int i = 0; i < D; i++) {
                if((k>>i) % 2 == 1) {
                    sum += (i+1) * 100 * p[i] + c[i];
                    cnt += p[i];
                } else {
                    restMax = i;
                }
            }
            if(sum < G) {
                int point = 100 * (restMax + 1);
                int rest = (int)Math.ceil((G - sum) / (double)point);
                if(p[restMax] <= rest) {
                    continue;
                }
                cnt += rest;
            }
            ans = Math.min(ans, cnt);
        }
        System.out.println(ans);
    }
}
