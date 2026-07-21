import java.io.*;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Main {

    public static void main(final String[] args) throws Exception {
        final Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int Q = sc.nextInt();

        final Solver solver = new Solver();
        solver.solve(S, Q, sc);
    }
}

class Solver {
    public void solve(String S, int Q, Scanner sc) {
        final List<Character> str = new LinkedList<>();
        for (char ch : S.toCharArray()) {
            str.add(ch);
        }

        boolean rev = false;
        for (int i = 0; i < Q; i++) {
            int t = sc.nextInt();

            switch (t) {
                case 1:
                    rev = !rev;
                    break;
                case 2:
                    int f = sc.nextInt();

                    boolean addFirst = (f == 1) ? !rev : rev;

                    char c = sc.next().charAt(0);
                    str.add(addFirst ? 0 : str.size(), c);
                    break;
            }
        }

        if (rev) {
            Collections.reverse(str);
        }
        System.out.println(str.stream().map(String::valueOf).collect(Collectors.joining()));
    }
}
