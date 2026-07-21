import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer tok = new StringTokenizer("");

    String next() throws IOException {
        if (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long mod = (long) (1e9 + 7);

    void slave() throws IOException {
        int n = nextInt();
        String s = next();
        int col[] = new int[26];
        for (int i = 0; i < s.length(); i++) {
            col[s.charAt(i) - 'a']++;
        }
        long ans = 0;
        for (int i = 0; i < 26; i++) {
            long ans1 = 0;
            ans1 = (ans * col[i]) % mod;
            ans1 = (ans1 + ans) % mod;
            ans1 = (ans1 + col[i]) % mod;
            ans = ans1;
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        new Main().slave();
    }
}
