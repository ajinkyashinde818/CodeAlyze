import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    void solve(Scanner in, PrintWriter out) {
        int t = in.nextInt();
        int cpt = 0;

        for (int i = 0; i < t; ++i) {
            int a1 = in.nextInt();
            int b1 = in.nextInt();
            if (a1 == b1) {
                cpt++;
            } else {
                cpt = 0;
            }

            if (cpt == 3) {
                out.println("Yes");
                break;
            }
        }
        if (cpt != 3)
            out.println("No");
    }

    public static void main(String[] args) {
        try(Scanner in = new Scanner(System.in);
            PrintWriter out = new PrintWriter(System.out)) {
            new Main().solve(in, out);
        }
    }
}
