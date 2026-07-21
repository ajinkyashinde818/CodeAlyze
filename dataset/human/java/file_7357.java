import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String lis[] = {
            "dream", "dreamer", "erase", "eraser"
        };
        int slen = s.length();
        
        while (true) {
            if (slen == 0) {
                System.out.println("YES");
                return;
            }
            boolean updated = false;
            for (int i = 0; i < 4; ++i) {
                String k = lis[i];
                if (slen >= k.length()) { //  && s.substring(s.length() - k.length(), s.length()).equals(k)) {
                    boolean ok = true;
                    for (int j = k.length() - 1; j >= 0; --j) {
                        if (k.charAt(j) == s.charAt(slen - k.length() + j)) {
                            // ok
                        } else {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        slen = slen - k.length();
                        updated = true;
                        break;
                    }
                } else {
                    continue;
                }
            }
            if (!updated) {
                System.out.println("NO");
                return;
            }
        }
    }
}
