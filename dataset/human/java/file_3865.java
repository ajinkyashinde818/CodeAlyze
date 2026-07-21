import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    static Scanner in;

    void solve() {
        String s = in.nextLine();
        Deque<Character> q = new ArrayDeque<>();
        for(char c:s.toCharArray()) {
            q.addLast(c);
        }
        int ans = 0;
        while(q.size() > 1) {
            char a = q.getFirst();
            char b = q.getLast();
            if(a == b) {
                q.removeFirst();
                q.removeLast();
            }else if(a == 'x') {
                q.addLast('x');
                ans++;
            }else if(b == 'x') {
                q.addFirst('x');
                ans++;
            }else{
                System.out.println("-1");
                return;
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        new Main().solve();
    }
}
