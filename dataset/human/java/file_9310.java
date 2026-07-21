import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        String s = "";
        int[] set = new int[scanner.nextInt()];
        for (int i = 0; i < set.length; i++) {
            int a = scanner.nextInt();
            if (a == scanner.nextInt())
                if (i != 0)
                    set[i] = set[i - 1] + 1;
                else
                    set[0] = 1;
            if (set[i] == 3) {
                s = "Yes";
                break;
            }
        }
        if (!s.equals("Yes"))
            s = "No";
        System.out.println(s);
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(String s) {
        try {
            br = new BufferedReader(new FileReader(s));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String nextToken() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }
}
