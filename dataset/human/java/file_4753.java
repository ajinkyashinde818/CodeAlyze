import java.util.*;

class Main{
    int L;
    int[] A;

    Main(){
        Scanner SC = new Scanner(System.in);

        String N = SC.next();
        L = N.length();
        A = new int[L+1];
        for(int i=1;i<=L;i++){
            A[i] = N.charAt(i-1) - 48;
        }

        int[][] DP = new int[L+1][2];
        DP[L][0] = A[L];
        DP[L][1] = 10-A[L];
        for(int i=L-1;i>=0;i--){
            DP[i][0] = Math.min(DP[i+1][0]+A[i], DP[i+1][1]+A[i]+1);
            DP[i][1] = Math.min(DP[i+1][0]+10-A[i], DP[i+1][1]+10-(A[i]+1));
        }

        System.out.println(Math.min(DP[0][0], DP[0][1]));
    }

    public static void main(String[] args){
        Main main = new Main();
    }
}
