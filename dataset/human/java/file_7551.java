import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        if (s.length() < 5) {
            System.out.println("NO");
            return;
        }
        String[] ary = {"dreamer", "eraser", "dream", "erase"};
        Set<String> set = new LinkedHashSet<>(Arrays.asList(ary));
        int idx = s.length() - 1;
        while (idx >= 0) {
            boolean isMatch = false;
            if (idx - 6 >= 0) {
                isMatch = set.contains(s.substring(idx - 6, idx + 1));
                if (isMatch) {
                    idx -= 7;
                }
            }
            if (!isMatch && idx - 5 >= 0) {
                isMatch = set.contains(s.substring(idx - 5, idx + 1));
                if (isMatch) {
                    idx -= 6;
                }
            }
            if (!isMatch && idx - 4 >= 0) {
                isMatch = set.contains(s.substring(idx - 4, idx + 1));
                if (isMatch) {
                    idx -= 5;
                }
            }
            if (!isMatch) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
