import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
*/public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
static class TaskC   {
public void solve(int testNumber, Scanner in, PrintWriter out) {
        int D = in.nextInt();
        int G = in.nextInt();
        int p[] = new int[D];
        int c[] = new int[D];
        for (int i = 0; i < D; i++) {
            p[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        int ans = 1<<30;
        int[] magic = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
        for (int bit = 0; bit < 1 << D; bit++) {
            int sum = 0;
            int tans = 0;
            HashSet<Integer> hs = new HashSet<>();
            for(int idx = 0; idx < D; idx++){
                if((bit & 1<<idx) != 0){
                    sum += 100 * (idx + 1) * p[idx] + c[idx];
                    tans += p[idx];
                    hs.add(idx);
                }
            }
            a:if (sum < G) {
                for (int i = D - 1; i >= 0; i--) {
                    if (hs.contains(i)) continue;
                    for (int j = 0; j < p[i]; j++) {
                        sum += 100 * (i+1);
                        tans++;
                        if(sum >= G) break a;
                    }
                }
            }
            ans = Math.min(ans, tans);
        }
        out.println(ans);
    }

}
}
