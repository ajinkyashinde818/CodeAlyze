import java.io.PrintWriter;
import java.util.Scanner;

class D {
    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int k = (int) Math.round(.5 + .5 * Math.sqrt(1 + 8 * N));
        if (k * (k - 1) / 2 == N) {
            final PrintWriter pw = new PrintWriter(System.out, false);
            pw.println("Yes");
            pw.println(k);
            final int[][] map = new int[k][k];
            for (int i = 0, c = 1; i < k; i++)
                for (int j = 0; j < i; j++)
                    map[i][j] = map[j][i] = c++;
            for (int i = 0; i < k; i++) {
                pw.print(k - 1);
                for (int j = 0; j < k; j++)
                    if (i != j) {
                        pw.print(' ');
                        pw.print(map[i][j]);
                    }
                pw.println();
            }
            pw.flush();
        } else {
            System.out.println("No");
        }
    }
}
public class Main {
    public static void main(String...args) {
		D.main();
    }
}
