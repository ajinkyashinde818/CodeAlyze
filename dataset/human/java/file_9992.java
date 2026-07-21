import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[] cash = new int[n];
        int[][] exp = new int[n][m];
        int ans = Integer.MAX_VALUE;
        /**Input */
        for(int i = 0;i<n;i++){
            cash[i] = sc.nextInt();
            for(int j = 0;j < m;j++)
                exp[i][j] = sc.nextInt();
        }

        /**calc */
        for(int i = 1;i < 1<<n;i++){
            boolean jdg = true;
            int[] ar = new int[m];
            int sum = 0;
            for(int j = 0;j < n;j++){
                if((1&(i>>j))==1){
                    sum += cash[j];
                    for(int k = 0;k < m;k++)
                        ar[k] += exp[j][k];
                }
            }

            for(int j = 0;j < m;j++){
                if(ar[j] < x)
                    jdg = false;
            }
            if(jdg)
                ans = Math.min(ans,sum);
        }

        System.out.println(ans < Integer.MAX_VALUE? ans : -1);
    }
}
