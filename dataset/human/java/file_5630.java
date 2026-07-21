import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int S = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if (i < K) {
                sb.append(S + " ");
            } else if (S == 1000000000) {
                sb.append(999999999 + " ");
            } else {
                sb.append(1000000000 + " ");
            }
        }
        System.out.println(sb);
    }

}
