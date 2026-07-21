import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner scan = new Scanner(is);
        int K = scan.nextInt();
        int N = scan.nextInt();
        int first = 0;
        int last = 0;
        int prev = 0;
        int curr = 0;
        int maxD = 0;
        first = scan.nextInt();
        prev = first;
        for(int i = 1; i < N; i++) {
            curr = scan.nextInt();
            maxD = Math.max(maxD, curr - prev);
            prev = curr;
            if(i == N-1)
                last = curr;
        }
        maxD = Math.max(maxD, K + first - last);
        os.println(K-maxD);
    }
}
