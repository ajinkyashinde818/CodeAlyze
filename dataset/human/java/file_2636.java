import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        boolean ok = false;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i) < t.charAt(j)) {
                    ok = true;
                }
            }
        }
        if (ok) {
            System.out.println("Yes");
        } else {
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < s.length(); i++) {
                for (int j = 0; j < t.length(); j++) {
                    if (set.contains(j)) {
                        continue;
                    }
                    if (s.charAt(i) == t.charAt(j)) {
                        set.add(j);
                        break;
                    }
                }
            }
            if (s.length() < t.length() && s.length() == set.size()) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        sc.close();
    }
}
