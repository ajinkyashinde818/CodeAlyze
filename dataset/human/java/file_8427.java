import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int left = 0, right = n + 2;
        int[] sizes = new int[n + 2];
        int[] value = new int[n + 2];
        while (right - left > 1) {
            int digits = (left + right) >> 1;
            int sz = 0;
            int curLen = 0;
            boolean ok = true;
//            System.err.println("digits=  " + digits);
            for (int l : a) {
                if (l > curLen) {
                    if (sz > 0 && value[sz - 1] == 0) {
                        sizes[sz - 1] += (l - curLen);
                    } else {
                        sizes[sz] = (l - curLen);
                        value[sz++] = 0;
                    }
                } else {
                    int rem = (curLen - l);
                    while (rem > 0) {
                        int sub = Math.min(sizes[sz - 1], rem);
                        sizes[sz - 1] -= sub;
                        rem -= sub;
                        if (sizes[sz - 1] == 0) {
                            sz--;
                        }
                    }
                    if (value[sz - 1] != digits - 1) {
                        if (sizes[sz - 1] == 1) {
                            value[sz - 1]++;
                            if (sz >= 2 && value[sz - 1] == value[sz - 2]) {
                                sizes[sz - 2] += sizes[sz - 1];
                                sz--;
                            }
                        } else {
                            sizes[sz - 1]--;
                            sizes[sz] = 1;
                            value[sz] = value[sz - 1] + 1;
                            sz++;
                        }
                    } else {
                        if (sz == 1) {
                            ok = false;
                            break;
                        } else {
                            int cntZeros = sizes[sz - 1];
                            sz--;

                            if (sizes[sz - 1] == 1) {
                                value[sz - 1]++;
                                if (sz >= 2 && value[sz - 1] == value[sz - 2]) {
                                    sizes[sz - 2] += sizes[sz - 1];
                                    sz--;
                                }
                            } else {
                                sizes[sz - 1]--;
                                sizes[sz] = 1;
                                value[sz] = value[sz - 1] + 1;
                                sz++;
                            }

                            sizes[sz] = cntZeros;
                            value[sz++] = 0;
                        }
                    }
                }
                curLen = l;
//                for (int i = 0; i < sz; i++) {
//                    System.err.print("(cnt = " + sizes[i] + ", val = " + value[i] + "), ");
//                }
//                System.err.println();
            }
            if (ok) {
                right = digits;
            } else {
                left = digits;
            }
        }
        out.println(right);
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}
