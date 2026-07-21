import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }

    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String S = scan.next();
        int Q = scan.nextInt();
        boolean order = true;
        Deque<Character> prefix = new LinkedList<>();
        Deque<Character> postfix = new LinkedList<>();
        for (int i = 0; i < Q; i++) {
            int type = scan.nextInt();
            if (type == 1) {
                order = !order;
                continue;
            }
            int F = scan.nextInt();
            char c = scan.next().toCharArray()[0];
            if (order) {
                if (F == 1) {
                    prefix.addLast(c);
                } else {
                    postfix.addLast(c);
                }
            } else {
                if (F == 1) {
                    postfix.addLast(c);
                } else {
                    prefix.addLast(c);
                }
            }
        }
        StringBuilder t = new StringBuilder();
        t.append(S);
        StringBuilder ans = new StringBuilder();
        if (order) {
            while(!prefix.isEmpty()) {
                ans.append(prefix.pollLast());
            }
            ans.append(t.toString());
            while(!postfix.isEmpty()) {
                ans.append(postfix.pollFirst());
            }
        } else {
            while(!postfix.isEmpty()) {
                ans.append(postfix.pollLast());
            }
            ans.append(t.reverse().toString());
            while(!prefix.isEmpty()) {
                ans.append(prefix.pollFirst());
            }
        }
        System.out.println(ans.toString());
    }
}
