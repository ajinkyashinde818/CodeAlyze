import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            String S = sc.next();
            Str str = new Str(S);
            int Q = sc.nextInt();
            for (int q = 0; q < Q; q++) {
                int T = sc.nextInt();
                if (T == 1) {
                    str.flip();
                } else {
                    int F = sc.nextInt();
                    char C = sc.next().charAt(0);
                    if (F == 1) {
                        str.addFirst(C);
                    } else {
                        str.addLast(C);
                    }
                }
            }
            System.out.println(str.toString());
        }
    }
}

class Str {
    LinkedList<Character> list;
    boolean isReverse = false;

    public Str(String s) {
        list = new LinkedList<Character>();
        for (int i = 0; i < s.length(); i++) {
            list.add(s.charAt(i));
        }
    }

    public void flip() {
        isReverse = !isReverse;
    }

    public void addFirst(char c) {
        if (isReverse) {
            list.addLast(c);
        } else {
            list.addFirst(c);
        }
    }

    public void addLast(char c) {
        if (isReverse) {
            list.addFirst(c);
        } else {
            list.addLast(c);
        }
    }

    public String toString() {
        StringBuilder res = new StringBuilder();
        if (isReverse) {
            while (!list.isEmpty()) {
                res.append(list.pollLast());
            }
        } else {
            while (!list.isEmpty()) {
                res.append(list.pollFirst());
            }
        }
        return res.toString();
    }
}
