import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder s = new StringBuilder(sc.next());
        int ans = 0;
        while (s.length() > 0) {
            if (s.charAt(0) == s.charAt(s.length() - 1)) {
                s.deleteCharAt(s.length() - 1);
                if (s.length() == 0) {
                    break;
                }
                s.deleteCharAt(0);
            } else {
                if (s.charAt(0) == 'x') {
                    s.append('x');
                    ans++;
                } else if (s.charAt(s.length() - 1) == 'x') {
                    s.insert(0, 'x');
                    ans++;
                } else {
                    System.out.println(-1);
                    return;
                }
            }
        }
        System.out.println(ans);
    }

}
