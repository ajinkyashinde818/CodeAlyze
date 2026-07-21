import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int Q = sc.nextInt();
        boolean order = true;
        Deque<String> deq = new ArrayDeque<>();
        for (String s : S.split("")) {
            deq.addLast(s);
        }
        for (int i = 0; i < Q; i++) {
            int Ti = sc.nextInt();
            if (Ti == 2) {
                int Fi = sc.nextInt();
                String P = sc.next();
                if (order) {
                    if (Fi == 1) {
                        deq.addFirst(P);
                    } else {
                        deq.addLast(P);
                    }
                } else {
                    if (Fi == 1) {
                        deq.addLast(P);
                    } else {
                        deq.addFirst(P);
                    }
                }
            } else {
                order = !order;
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!deq.isEmpty()) {
            String s = null;
            if (order) {
                s = deq.pollFirst();
            } else {
                s = deq.pollLast();
            }
            sb.append(s);
        }
        System.out.println(sb);
    }
}
