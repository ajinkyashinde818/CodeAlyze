import java.util.Arrays;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws Exception {
        //スキャン
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N+1];
        A[0] =0;
        int sum = 0;
        int bigMan =0;

        for(int i=1; i <= N ; i++){
            int hoge = sc.nextInt();
            A[i] = hoge;
            sum += hoge;
            bigMan = Math.max(bigMan, A[i]-A[i-1]);
        }
        bigMan = Math.max(bigMan, K-A[N]+A[1]);

        System.out.println(K-bigMan);
    }
}
