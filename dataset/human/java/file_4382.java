import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int[] Ai = new int[N];
        int[] Bi = new int[N];
        int[] Ci = new int[N-1];

        for (int i = 0; i < N; i++) {

            Ai[i] = Integer.parseInt(sc.next());
        }

        for (int i = 0; i < N; i++) {

            Bi[i] = Integer.parseInt(sc.next());
        }

        for (int i = 0; i < N-1; i++) {

            Ci[i] = Integer.parseInt(sc.next());
        }

        sc.close();

        int ans = 0;

        for (int i = 0; i < N; i++) {

            ans += Bi[Ai[i]-1];

            if (i != 0 && Ai[i] == Ai[i-1] + 1) {

                ans += Ci[Ai[i-1]-1];
            }
        }

        System.out.println(ans);

    }

}
