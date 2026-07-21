import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            int N = sc.nextInt();
            int K = sc.nextInt();
            int S = sc.nextInt();

            int X = 1000000000;
            if (S == X) {
                X--;
            }

            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < K; i++) {
                ans.append(S).append(" ");
            }
            for (int i = K; i < N; i++) {
                ans.append(X).append(" ");
            }
            ans.delete(ans.length() - 1, ans.length());

            System.out.println(ans.toString());
        }
    }

}
