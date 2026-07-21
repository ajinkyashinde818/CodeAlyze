import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Washoum
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        inputClass in = new inputClass(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CAllGreen solver = new CAllGreen();
        solver.solve(1, in, out);
        out.close();
    }

    static class CAllGreen {
        public void solve(int testNumber, inputClass sc, PrintWriter out) {
            int d = sc.nextInt();
            int g = sc.nextInt();
            int[] p = new int[d];
            int[] c = new int[d];
            for (int i = 0; i < d; i++) {
                p[i] = sc.nextInt();
                c[i] = sc.nextInt();
            }
//        int a=0;
//        int at=0;
//        int j=d-1;
//        while (a<g && j>=0){
//            long rem = g - a;
//            if (rem <=(p[j]-1)*(j+1)*100){
//                at+= rem /((j+1)*100) + ((rem%((j+1)*100))==0 ? 0 : 1);
//                break;
//            }
//            else{
//                a+=(p[j]-1)*(j+1)*100;
//                at+=p[j]-1;
//                j--;
//            }
//        }
            int ans = Integer.MAX_VALUE;
//        if (j>=0){
//            ans=a;
//        }
            for (int mask = 0; mask < (1 << d); mask++) {
                int act = 0;
                long score = 0;
                boolean[] active = new boolean[d];
                for (int i = 0; i < d; i++) {
                    if ((mask & (1 << i)) > 0) {
                        act += p[i];
                        score += p[i] * 100 * (i + 1) + c[i];
                        active[i] = true;
                    }
                }
                int i = d - 1;
                while (score < g && i >= 0) {
                    if (active[i]) {
                        i--;
                    } else {
                        long rem = g - score;
                        if (rem <= (p[i] - 1) * (i + 1) * 100) {
                            score = g + 1;
                            act += rem / ((i + 1) * 100) + ((rem % ((i + 1) * 100)) == 0 ? 0 : 1);
                            break;
                        } else {
                            score += (p[i] - 1) * (i + 1) * 100;
                            act += p[i] - 1;
                            i--;
                        }
                    }
                }
                if (score >= g) {
                    ans = Math.min(ans, act);
                }
            }
            out.println(ans);
        }

    }

    static class inputClass {
        BufferedReader br;
        StringTokenizer st;

        public inputClass(InputStream in) {

            br = new BufferedReader(new InputStreamReader(in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
