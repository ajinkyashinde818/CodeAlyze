import java.util.ArrayDeque;
import java.util.Iterator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            final String s  = sc.next();
            final int q = sc.nextInt();

            ArrayDeque <String> deque = new ArrayDeque<>(300000);
            boolean reversed = false;

            deque.add(s);
            for (int i=0; i<q; i++) {
                int t = sc.nextInt();
                if (t == 1) {
                    reversed = !reversed;

                } else {
                    int f = sc.nextInt();
                    String c = sc.next();
                    if (f == 1) {
                        if (!reversed) {
                            deque.addFirst(c);
                        } else {
                            deque.addLast(c);
                        }
                    } else {
                        if (!reversed) {
                            deque.addLast(c);
                        } else {
                            deque.addFirst(c);
                        }
                    }
                }
            }

            if (!reversed) {
                Iterator<String> it = deque.iterator();
                while(it.hasNext()) {
                    System.out.print(it.next());
                }
            } else {
                Iterator<String> it = deque.descendingIterator();
                while(it.hasNext()) {
                    String next = it.next();
                    if (next.length() == 1) {
                        System.out.print(next);
                    } else {
                        StringBuilder sb = new StringBuilder(next);
                        sb.reverse();
                        System.out.print(sb);
                    }
                }
            }

            System.out.println();

        } finally {
            sc.close();
        }
    }
}
