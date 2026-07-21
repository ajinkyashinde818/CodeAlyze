import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int N = sc.nextInt();
            int[] p = new int[N];
            for (int i = 0; i < N; i++) {
                p[i] = sc.nextInt();
            }

            int score;
            for (score = N; score >= 0; score--) {
                int cnt = 0;
                for (int j = 0; j < N; j++) {
                    if ( p[j] >= score ) {
                        cnt++;
                    }
                }
                if ( cnt >= score ) {
                    break;
                }
            }
            System.out.println(score);
        }
    }
}
