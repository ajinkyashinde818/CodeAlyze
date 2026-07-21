import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        List<Character> sli = new ArrayList<Character>(s.length());
        List<Character> tli = new ArrayList<Character>(t.length());
        for (int i = 0; i < s.length(); i++) {
            sli.add(s.charAt(i));
        }
        for (int i = 0; i < t.length(); i++) {
            tli.add(t.charAt(i));
        }
        sli.sort(Comparator.naturalOrder());
        tli.sort(Comparator.reverseOrder());
        int bre = 0;
        if (s.length() < t.length()) {
            for (int i = 0; i < s.length(); i++) {
                if (sli.get(i) < tli.get(i)) {
                    bre = 1;
                    break;
                } else if (sli.get(i) > tli.get(i)) {
                    bre = 2;
                    break;
                }
            }
            if (bre == 0) {
                bre = 1;
            }
        } else {
            for (int i = 0; i < t.length(); i++) {
                if (sli.get(i) < tli.get(i)) {
                    bre = 1;
                    break;
                } else if (sli.get(i) > tli.get(i)) {
                    bre = 2;
                    break;
                }
            }
            if (bre == 0) {
                bre = 2;
            }
        }
        if (bre == 1) {
            System.out.println("Yes");
        } else if (bre == 2) {
            System.out.println("No");
        }
    }
}
