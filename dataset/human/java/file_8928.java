import java.io.*;
import java.util.*;

public class Main {

    static PrintStream out = System.out;

    static void solve(Scanner in) {

        int A = in.nextInt();
        int B = in.nextInt();
        int k = in.nextInt();


        int res = 0;
        int cnt = 0;
        for(int i = Math.min(A, B); i >= 1; i--){
            if(A%i == 0 && B%i == 0){
                cnt++;
                if(cnt == k){
                    res = i;
                    break;
                }
            }
        }
        System.out.println(res);

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        solve(in);
    }
}
