import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        boolean[] s = new boolean[N];
        boolean[] t = new boolean[N];
        for (int i = 0; i < M; i++) {
            int A = sc.nextInt() - 1;
            int B = sc.nextInt() - 1;
            if (A == 0) {
                s[B] = true;
            }
            if (B == N - 1) {
                t[A] = true;
            }
        }
        boolean ans = false;
        for (int i = 0; i < N; i++) {
            if(s[i] && t[i]) ans = true;
        }
        System.out.println(ans ? "POSSIBLE" : "IMPOSSIBLE");
    }

}
