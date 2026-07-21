import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int Q = sc.nextInt();
        LinkedList<Character> tmp = new LinkedList<>();
        for (int i = 0; i < S.length(); i++) {
            tmp.add(S.charAt(i));
        }
        boolean reverse = false;
        for (int i = 0; i < Q; i++) {
            int T = sc.nextInt();
            if (T == 1) {
                reverse = !reverse;
            } else {
                int F = sc.nextInt();
                char C = sc.next().toCharArray()[0];
                if (!reverse) {
                    if (F == 1) {
                        tmp.addFirst(C);
                    } else {
                        tmp.add(C);
                    }
                } else {
                    if (F == 1) {
                        tmp.add(C);
                    } else {
                        tmp.addFirst(C);
                    }
                }
            }
        }
        StringBuilder ans = new StringBuilder();
        if (reverse) {
            while (!tmp.isEmpty()) {
                ans.append(tmp.removeLast());
            }
        } else {
            while (!tmp.isEmpty()) {
                ans.append(tmp.removeFirst());
            }
        }

        System.out.println(ans.toString());
    }
}
