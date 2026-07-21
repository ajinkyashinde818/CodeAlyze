import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[] s = (sc.next()).toCharArray();
        char[] t = (sc.next()).toCharArray();

        Arrays.sort(s);
        Arrays.sort(t);

        boolean isAns = false;
        for (int i = 0; i < s.length; i++) {
            if (i >= t.length)
                break;
            int tNum = t.length - i - 1;
            if (s[i] < t[tNum]) {
                isAns = true;
                break;
            }
        }

        if (s[s.length-1] == t[0] && s.length < t.length)
            isAns = true;

        System.out.println(isAns ? "Yes" : "No");
    }
}
