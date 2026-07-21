import java.io.*;
import java.util.*;

public class Main {

    public static void main(final String[] args) throws Exception {
        final Scanner sc = new Scanner(System.in);
        long N;
        N = sc.nextLong();
        long R;
        R = sc.nextLong();

        final Solver solver = new Solver();
        solver.solve(N, R);
    }
}

class Solver {
    public void solve(long N, long R) {
        if (N < 10) {
            System.out.println(R + (100 * (10 - N)));
        }
        else {
            System.out.println(R);
        }
    }
}
