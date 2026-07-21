import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int q = Integer.parseInt(sc.next());
        Deque<String> dq = new ArrayDeque<>();
        dq.add(s);
        boolean isR = false;
        for (int i = 0; i < q; i++) {
            int t = Integer.parseInt(sc.next());
            if (t == 1) {
                isR = !isR;
            } else {
                int f = Integer.parseInt(sc.next());
                String c = sc.next();
                if (f == 1) {
                    if (isR) {
                        dq.addLast(c);
                    } else {
                        dq.addFirst(c);
                    }
                } else {
                    if (isR) {
                        dq.addFirst(c);
                    } else {
                        dq.addLast(c);
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (String temp : dq) {
            sb.append(temp);
        }
        System.out.println(isR ? sb.reverse().toString() : sb.toString());
    }
}
