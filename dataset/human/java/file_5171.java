import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        int q = sc.nextInt();

        boolean isHanten = false;

        Deque<String> deque = new ArrayDeque();
        for (char ch : s) {
            deque.addLast(String.valueOf(ch));
        }

        for (int i = 0; i < q; i++) {
            int f = sc.nextInt();
            if (f == 1) {
                isHanten = !isHanten;
            } else {
                int ff = sc.nextInt();
                if (isHanten) {
                    ff = 3 - ff;
                }
                if (ff == 1) {
                    deque.addFirst(sc.next());
                } else {
                    deque.addLast(sc.next());
                }
            }
        }

        if (isHanten) {
            while (!deque.isEmpty()) {
                System.out.print(deque.getLast());
                deque.pollLast();
            }
        } else {
            for (String str : deque) {
                System.out.print(str);
            }
        }
    }
}
