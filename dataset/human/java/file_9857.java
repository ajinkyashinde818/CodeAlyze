import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int C[] = new int[N+1];
        int A[][] = new int[N+1][M+1];
        for(int i=1; i<=N; i++) {
            C[i] = sc.nextInt();
            for(int t=1; t<=M; t++) {
                A[i][t] = sc.nextInt();
            }
        }

        int minPrice = Integer.MAX_VALUE;
        for(int p=0; p<(1 << N); p++) {
            int score[] = new int[M+1];
            int price = 0;
            for(int n=1; n<=N; n++) {
                if(!isOn(p, n-1)) continue;
                price+=C[n];
                for(int m=1; m<=M; m++) {
                    score[m] += A[n][m];
                }
            }
            // check threshold
            boolean flag = false;
            for(int m=1; m<=M; m++) {
                if(score[m]<X) {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            if(minPrice > price) {
                minPrice = price;
            }
        }
        if(minPrice != Integer.MAX_VALUE) {
            System.out.println(minPrice);
        } else {
            System.out.println(-1);
        }
    }

    static boolean isOn(long judge, int index) {
        return ((1 << index) & judge) == (1 << index);
    }
}
