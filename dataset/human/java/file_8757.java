import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);

        int A = Integer.parseInt(sc.next());
        int B = Integer.parseInt(sc.next());
        int K = Integer.parseInt(sc.next());
        int cnt = 0;

        for (int i = Math.min(A, B); i >= 1; i--) {
            if (A % i == 0 && B % i == 0) {
                cnt++;
                if (cnt == K) {
                    System.out.println(i);
                    return;
                }
            }
        }
    }
}
