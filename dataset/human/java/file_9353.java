import java.io.*;
import java.util.*;

import static java.lang.Integer.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;
        int t = parseInt(in.readLine());
        int cnt = 0;
        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(in.readLine());
            int D1 = parseInt(st.nextToken()), D2 = parseInt(st.nextToken());
            if (D1 == D2) cnt++;
            else if (cnt < 3) cnt = 0;

        }
        if (cnt >= 3) pw.println("Yes");
        else pw.println("No");
        pw.close();
    }

    static void solve() {

    }
}
