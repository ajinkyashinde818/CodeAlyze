import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for(int i = 0; i < N; i++) A[i] = sc.nextInt();

        int[] B = new int[N];
        for(int i = 0; i < N; i++) {
            if(i==0){
                B[i] = K - A[N-1] + A[i];
            } else {
                B[i] = A[i] - A[i-1];
            }
        }
        Arrays.sort(B);
        int res = 0;
        for(int i = 0; i < N-1; i++) res += B[i];
        System.out.println(res);
    }
}
