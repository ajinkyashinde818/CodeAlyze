import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int K;
        int N;
        int[] Ai;
        try (Scanner sc = new Scanner(System.in)) {
            K = sc.nextInt();
            N = sc.nextInt();
            Ai = new int[N];
            for (int i = 0; i < N; i++) {
                Ai[i] = sc.nextInt();
            }
        }
        int dist = Ai[0] + (K-Ai[N-1]);
        for (int i = 0; i < N-1; i++) {
            if(dist < Ai[i+1] -Ai[i]){
                dist = Ai[i+1] -Ai[i];
            };
        }
        System.out.println(K - dist);
    }
}
