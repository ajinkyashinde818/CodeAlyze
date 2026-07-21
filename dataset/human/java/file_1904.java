import java.util.*;

public class Main {
    static int modP = 1000000007;
    static long inf  = 1 << 61;
    static int[] x4 = {-1, 0, 0, 1};
    static int[] y4 = {0, -1, 1, 0};

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int d = in.nextInt();
        int g = in.nextInt();
        int[] P = new int[11];
        int[] C = new int[11];
        int[] S = new int[11];
        for(int i = 1; i <= d; i++) {
            P[i] = in.nextInt();
            C[i] = in.nextInt();
            S[i] = (P[i]*i*100) + C[i];
        }

        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < (1 << d); i++) {
            int pointSum = 0;
            int problemCnt = 0;
            for(int j = 0; j < d; j++) {
                if(((i>>j)&1) == 1) {
                    pointSum += S[j+1];
                    problemCnt += P[j+1];
                }
            }

            if(pointSum >= g) {
                ans = Math.min(ans, problemCnt);
            }else{
                int pointsToGo = g - pointSum;

                for(int j = 0; j < d; j++) {
                    if(((i>>j)&1) == 0){
                        if(pointsToGo > (P[j+1]-1) * (j+1)*100) {
                            continue;
                        }else{
                            problemCnt += pointsToGo / ((j+1)*100);
                            ans = Math.min(ans, problemCnt);
                        }
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
