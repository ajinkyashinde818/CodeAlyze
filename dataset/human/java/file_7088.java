import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int max = 0;
        int sum = 0;
        int[] diff = new int[N];
        for (int i = 0; i < N; i++) {
            if (i != N-1) {
                diff[i] = A[i+1]-A[i];
            } else {
                diff[i] = A[0]+K-A[N-1];
            }
            max = Math.max(max, diff[i]);
            sum += diff[i];
        }
        System.out.println(sum-max);
    }
}
