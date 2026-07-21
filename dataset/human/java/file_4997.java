import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        char[] c = S.toCharArray();
        int Q = sc.nextInt();
        int cnt = 0;
        ArrayDeque<Character> q = new ArrayDeque<Character>();
        for (int i=0;i<c.length;i++) {
            q.add(c[i]);
        }
        for (int i=0;i<Q;i++) {
            int T = sc.nextInt();
            if (T==1) {
                cnt++;
            } else { // T==2
                int F = sc.nextInt();
                char C = sc.next().charAt(0);
                if ((F+cnt)%2==1) {
                    q.addFirst(C);
                } else { // (F+cnt)%2==0
                    q.add(C);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!q.isEmpty()) {
            sb.append(q.poll());
        }
        if (cnt%2==1) sb.reverse();
        System.out.println(sb);
    }
}
