import java.io.*;
import java.util.*;

public class Main {

    public static void main(final String[] args) throws Exception {
        final Scanner sc = new Scanner(System.in);
        long A;
        A = sc.nextLong();
        long B;
        B = sc.nextLong();

        final Solver solver = new Solver();
        solver.solve(A, B);
    }
}

class Solver {
    public void solve(long A, long B) {
        System.out.println(A * B / lcd(A, B));
    }

    private long lcd(long A, long B) {
        if (B == 0) {
            return A;
        }
        return lcd(B, A % B);
    }
}
