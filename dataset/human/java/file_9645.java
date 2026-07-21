import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        boolean res = false;

        for (int i = 0, chain = 0; i < n; ++i) {
            String[] line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]), b = Integer.parseInt(line[1]);
            if (a == b) {
                res |= ++chain >= 3;
            } else {
                chain = 0;
            }
        }

        bw.write(res ? "Yes" : "No");

        bw.close();
        br.close();
    }
}
