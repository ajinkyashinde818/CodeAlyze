import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.Collection;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.LinkedList;
import java.util.Collections;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DStringFormation solver = new DStringFormation();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStringFormation {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String str = in.next();
            Character[] arr = str.chars().mapToObj(c -> (char) c).toArray(Character[]::new);
            LinkedList<Character> l = new LinkedList<>(Arrays.asList(arr));
            int q = Integer.parseInt(in.next());
            int t = 0;
            int f = 0;
            char c;

            boolean reverseFlg = false;
            for (int i = 0; i < q; i++) {
                t = Integer.parseInt(in.next());
                if (t == 1) {
                    reverseFlg = !reverseFlg;
                } else {
                    f = Integer.parseInt(in.next());
                    c = in.next().charAt(0);
                    if ((f == 2 && !reverseFlg) || (f == 1 && reverseFlg)) {
                        l.add(c);
                    } else {
                        l.addFirst(c);
                    }
                }
            }
            String r;
            if (reverseFlg) {
                Collections.reverse(l);
                r = l.stream().map(String::valueOf).collect(Collectors.joining());
            } else {
                r = l.stream().map(String::valueOf).collect(Collectors.joining());
            }
            out.append(r);
        }

    }
}
