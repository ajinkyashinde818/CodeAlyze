import java.util.Scanner;

class Problem {
    private int N;
    private String S;
    private final long D = (long) 1e9 + 7;

    Problem() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        S = sc.next();
    }

    long solve() {
        long[] counts = new long[26];

        for (int i = 0; i < N; i++) {
            int c = S.charAt(i) - 'a';
            counts[c]++;
        }

        long ans = 1;
        for (int i = 0; i < counts.length; i++) {
            ans *= (counts[i] + 1);
            ans %= D;
        }
        return ans - 1;
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println(new Problem().solve());
    }
}
