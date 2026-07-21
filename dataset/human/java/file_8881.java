import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = Integer.parseInt(sc.next());
        int B = Integer.parseInt(sc.next());
        int K = Integer.parseInt(sc.next());
        int count = 0;

        for (int i = Math.min(A, B); i >= 1; i--) {
            if (A % i == 0 && B % i == 0) {
                count++;
            }

            if (count == K) {
                count = i;
                break;
            }
        }

        PrintWriter out = new PrintWriter(System.out);
        out.println(count);

        sc.close();
        out.flush();
    }
}
