import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        Integer[] Ms = new Integer[M];
        int[] checks = new int[N+1];
        List<Integer> MsList = Arrays.asList(Ms);

        for (int m = 0; m < M; m++){
            Ms[m] = sc.nextInt();
            checks[Ms[m]] = 1;
        }
        long[] memo = new long[N+1];
        for (int n = 1; n <= N; n++){
            if (n == 1) {
                if (checks[1] == 1){memo[1] = 0;}
                else {memo[1] = 1;}
                continue;
            }
            if (n == 2){
                if (checks[2] == 1){memo[2] = 0;}
                else if (checks[1] == 1){memo[2] = 1;}
                else {memo[2] = 2;}
                continue;
            }
            boolean inN = (checks[n] == 1);
            if ((inN) && (checks[n-1] == 1)) {
                break;
            }
            if (inN) {
                continue;
            }
            memo[n] = (memo[n-2] + memo[n-1])%1000000007;
        }
        System.out.println(memo[N]%1000000007);
      }
}
