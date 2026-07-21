import java.io.PrintWriter;
import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);

    PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i=0; i<n; i++) arr[i] = sc.nextInt();


        int ans = Integer.MAX_VALUE;

        for (int i=0; i<n; i++) {
            int rightS = i;
            int rightEnd = (i==0) ? n-1 : i-1;
            if (i==0) {
                ans = Math.min(ans, arr[n-1]-arr[0]);
            } else {
                ans = Math.min(ans, k-(arr[i]-arr[i-1]));
            }

            int leftS = i;
            int leftEnd = (i==n-1) ? 0 : i+1;
            if (i==n-1) {
                ans = Math.min(ans, arr[n-1]-arr[0]);
            } else {
                ans = Math.min(ans, k-(arr[i+1]-arr[i]));
            }
        }


        out.print(ans);
        out.flush();



    }

}
