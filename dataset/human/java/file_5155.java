import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class Main implements Runnable {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        // Run with 32MB stack
        Thread thread = new Thread(null, new Main(), "", 32 * 1024 * 1024);
        thread.start();
    }

    @Override
    public void run() {
        final Scanner scanner = new Scanner(System.in);
        solve(scanner);
    }

    static void solve(Scanner scanner) {
        String s = scanner.next();
        LinkedList<Character> l = new LinkedList();
        for(char c: s.toCharArray()) {
            l.add(c);
        }
        
        int Q = Integer.parseInt(scanner.next());
        boolean rev = false;
        for (int i = 0; i < Q; i++) {
            int q = Integer.parseInt(scanner.next());
            if (q == 1) {
                rev = !rev;
            } else {
                int t = Integer.parseInt(scanner.next());
                char c = scanner.next().charAt(0);
                if (t == 1) {
                    if (!rev) {
                        l.addFirst(c);
                    } else {
                        l.addLast(c);
                    }
                } else {
                    if (!rev) {
                        l.addLast(c);
                    } else {
                        l.addFirst(c);
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        Iterator<Character> ite;
        if (rev) {
            ite = l.descendingIterator();
        } else {
            ite = l.iterator();
        }
        while (ite.hasNext()) {
            sb.append(ite.next());
        }

        System.out.println(sb.toString());
    }

}
