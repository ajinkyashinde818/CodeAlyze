import java.util.*;

public class Main {

    static int gcd (int a, int b) {return b>0?gcd(b,a%b):a;}
    static int mod = 1000000007;

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int[] C = new int[N];
        int[][]A  = new int[N][M];
        int ans = Integer.MAX_VALUE;

        for(int i=0;i<N;i++){
            C[i] = sc.nextInt();
            for(int j=0;j<M;j++){
                A[i][j] = sc.nextInt();
            }
        }

        for(int i = 0;i<Math.pow(2,N);i++){

            int[] level = new int[M];
            int totalPrice = 0;
            boolean allMastered = true;
            int bit = i;
            for(int j=0;j<N;j++){

                if(bit % 2 == 1){
                    totalPrice += C[j];
                    for(int k=0;k<M;k++){
                        level[k] += A[j][k];
                    }
                }
                bit = bit / 2;
            }

            for(int j=0;j<M;j++){
                if(level[j] < X){
                    allMastered = false;
                }
            }
            if(allMastered){
                ans = Math.min(ans,totalPrice);
            }
        }


        if(ans == Integer.MAX_VALUE){
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }

}
