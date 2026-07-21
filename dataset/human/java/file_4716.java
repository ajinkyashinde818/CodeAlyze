import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        int cnt = 0;
        int u = 0;
        for (int i = n.length() - 1; i >= 0; i--) {
            int m = n.charAt(i) - '0';
            if (m + u <= 4) {
                cnt += m + u;
                u = 0;
            }
            else if (m + u == 5) {
                cnt += 5;
                u = 0;
                if (i > 0) {
                    int mm = n.charAt(i - 1) - '0';
                    if (mm >= 5) u = 1;
                }
            }
            else if (m + u <= 9) {
                cnt += 10 - (m + u);
                u = 1;
            }
        }
        if (u == 1) cnt++;
        System.out.println(cnt);
    }
}
