import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner scan = new Scanner(is);
        int N = scan.nextInt();
        boolean first = false;
        boolean second = false;
        for(int i = 0; i < N; i++) {
            int D1 = scan.nextInt();
            int D2 = scan.nextInt();
            if(!first) {
                if(D1 == D2)
                    first = true;
            } else if (!second) {
                if(D1 == D2)
                    second = true;
                else
                    first = false;
            } else {
                if(D1 == D2) {
                    os.println("Yes");
                    return;
                } else {
                    first = false;
                    second = false;
                }
            }
        }


        os.println("No");
    }
}
