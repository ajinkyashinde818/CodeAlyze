import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] dist = new int[N];
        int tmp = 0;
        for (int i=0;i<N;i++) {
            int A = sc.nextInt();
            dist[i] = A-tmp;
            tmp = A;
        }
        dist[0] += K-tmp;

        int max = 0;
        for (int i=0;i<N;i++) {
            max = Math.max(max, dist[i]);
        }
        System.out.println(K-max);
    }
}
