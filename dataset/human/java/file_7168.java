import java.util.Arrays;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();

        int[] H = new int[N];
        for (int i = 0; i < N; i++) {
            H[i] = sc.nextInt();
        }

        Arrays.sort(H);

        int maxDis = H[0]-H[N-1]+K;

        for (int i = 1; i < N ; i++) {
            maxDis = Math.max(maxDis,H[i]-H[i-1]);
        }



        System.out.println( K-maxDis);
    }

}
