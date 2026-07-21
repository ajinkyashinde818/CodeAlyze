import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] E = new int[M];
        for (int i = 0; i < M; i++) {
            E[i] = sc.nextInt();
        }
        boolean[] used = new boolean[N+1];
        for (int i = M-1; i >= 0; i--) {
            if (!used[E[i]]) {
                System.out.println(E[i]);
                used[E[i]] = true;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (!used[i]) System.out.println(i);
        }
    }

}
