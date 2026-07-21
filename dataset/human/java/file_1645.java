import java.util.*;

import static java.lang.System.*;

public class Main {
    final static long prime = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();

        long charCount[] = new long['z' - 'a' + 1];
        for (int i = 0; i < N; i++) {
            char c = S.charAt(i);
            charCount[c - 'a']++;
        }

        long ans = 1;
        for (int i = 0; i <= 'z' - 'a'; i++) {
            ans = (ans * (charCount[i] + 1)) % prime;
        }
        ans--;

        out.println(ans);
    }
}
