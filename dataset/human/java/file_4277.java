import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        int[] AN = new int[N];
        for (int i = 0; i < N; i++) {
            AN[i] = Integer.parseInt(sc.next());
        }
        int[] BN = new int[N];
        for (int i = 0; i < N; i++) {
            BN[i] = Integer.parseInt(sc.next());
        }
        int[] CN = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            CN[i] = Integer.parseInt(sc.next());
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int choice = AN[i];
            if (i + 1 < N && choice + 1 == AN[i + 1]) {
                ans += CN[choice - 1];
            }
            ans += BN[choice - 1];
        }
        System.out.println(ans);
    }

}
