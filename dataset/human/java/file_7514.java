import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        inputClass in = new inputClass(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CDaydream solver = new CDaydream();
        solver.solve(1, in, out);
        out.close();
    }

    static class CDaydream {
        public void solve(int testNumber, inputClass sc, PrintWriter out) {
            StringBuilder s = new StringBuilder(sc.nextLine());
            String dream = "dream";
            String dreamer = "dreamer";
            String erase = "erase";
            String eraser = "eraser";
            int n = s.length();
            int i = n - 1;
            while (i >= 0) {
                if (s.charAt(i) == 'r') {
                    int k = 5;
                    boolean ok = true;
                    if (i >= 5) {
                        for (int j = i; j > i - 6; j--) {
                            if (s.charAt(j) == eraser.charAt(k))
                                k--;
                            else
                                ok = false;
                        }
                        if (ok) {
                            i = i - 6;
                            continue;
                        }
                    }
                    k = 6;
                    ok = true;
                    if (i >= 6) {
                        for (int j = i; j > i - 7; j--) {
                            if (s.charAt(j) == dreamer.charAt(k))
                                k--;
                            else
                                ok = false;
                        }
                        if (ok) {
                            i = i - 7;
                            continue;
                        }
                    }
                    out.println("NO");
                    return;
                } else {
                    int k = 4;
                    boolean ok = true;
                    if (i >= 4) {
                        for (int j = i; j > i - 5; j--) {
                            if (s.charAt(j) == erase.charAt(k))
                                k--;
                            else
                                ok = false;
                        }
                        if (ok) {
                            i = i - 5;
                            continue;
                        }
                    }
                    k = 4;
                    ok = true;
                    if (i >= 4) {
                        for (int j = i; j > i - 5; j--) {
                            if (s.charAt(j) == dream.charAt(k))
                                k--;
                            else
                                ok = false;
                        }
                        if (ok) {
                            i = i - 5;
                            continue;
                        }
                    }
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
        }

    }

    static class inputClass {
        BufferedReader br;

        public inputClass(InputStream in) {

            br = new BufferedReader(new InputStreamReader(in));
        }

        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}
