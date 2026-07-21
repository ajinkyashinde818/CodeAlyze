import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[] price = new int[n];
        int[][] c = new int[n][m];
        for(int i=0; i<n; i++) {
            price[i] = sc.nextInt();
            for(int j=0; j<m; j++) {
                c[i][j] = sc.nextInt();
            }
        }
        sc.close();

        int ans = Integer.MAX_VALUE;
        for(int i=0; i<(1<<n); i++) {
            int cost = 0;
            int[] skill = new int[m];
            for(int j=0; j<n; j++) {
                if((i >> j & 1) == 1) {
                    cost += price[j];
                    for(int k=0; k<m; k++) {
                        skill[k] += c[j][k];
                    }
                }
            }
            boolean isQualified = true;
            for(int l=0; l<m; l++) {
                if(skill[l] < x) isQualified = false;
            }
            if(isQualified) ans = Math.min(ans, cost);
        }
        if(ans == Integer.MAX_VALUE) System.out.println("-1");
        else System.out.println(ans);
    }
}
