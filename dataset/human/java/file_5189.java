import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int q = sc.nextInt();
        int[] t = new int[q];
        int[] f = new int[q];
        String[] c = new String[q];
        for (int i = 0; i < q; i++) {
            t[i] = sc.nextInt();
            if (t[i] == 1) {
                continue;
            }
            f[i] = sc.nextInt();
            c[i] = sc.next();
        }

        Deque<String> queue = new ArrayDeque<>();
        queue.addFirst(s);
        boolean reversed = false;
        for (int i = 0; i < q; i++) {
            if (t[i] == 1) {
                reversed = Boolean.logicalXor(reversed, true);
                continue;
            }
            if (f[i] == 1 && !reversed || f[i] == 2 && reversed) {
                queue.addFirst(c[i]);
                continue;
            }
            queue.addLast(c[i]);
        }
        StringBuilder sb = new StringBuilder();
        int qlen = queue.size();
        for (int i = 0; i < qlen; i++) {
            if (!reversed) {
                sb.append(queue.removeFirst());
                continue;
            }
            String str = queue.removeLast();
            if (s.equals(str)) {
                str = new StringBuilder(str).reverse().toString();
            }
            sb.append(str);
        }
        System.out.println(sb.toString());
    }

}
