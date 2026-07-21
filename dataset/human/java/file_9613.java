import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static PrintWriter out;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = Integer.parseInt(sc.next());
        int zoromeCount = 0;
        for (int i = 0; i < n; i++) {
            if (zoromeCount >= 3) {
                break;
            }
            int d1 = Integer.parseInt(sc.next());
            int d2 = Integer.parseInt(sc.next());
            if (d1 == d2) {
                zoromeCount++;
            } else {
                zoromeCount = 0;
            }
        }
        if (zoromeCount >= 3) {
            out.println("Yes");
        } else {
            out.println("No");
        }
        sc.close();
        out.close();
    }

}
