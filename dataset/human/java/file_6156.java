import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // @DONE: Plan solve [DOCUMENT TIME]
        // So basically there's this like, thing right lol
        // A + B + C = X, A > 0, B > 0, C > 0.
        // Number of ways to make A + B = 0 through X
        // WAIT HOLD UP THIS IS C&P LOLOL
        // Basically divide into pieces, probably subtract 3N - S JUST TO BE SAFE
        // @DONE: Test on paper [DOCUMENT TIME]
        // Not necessary
        // @DONE: Implement solve [DOCUMENT TIME]

        Scanner in = new Scanner(System.in);

        String s = in.nextLine();
        StringTokenizer st = new StringTokenizer(s);

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        a++;

        // sum to B, less than A
        // so... total of B + 2 choose 2 ways
        // and then B - A + 2 choose 2 ways? PIE

        // Since you can add 3 for zeroes or no oh wait no
        int original = (b + 2)*(b + 1)/2;

        if(b >= a) {
            // Subtract
            original -= (b - a + 2)*(b - a + 1)*3/2;
        }
        if(b >= 2*a) {
            original += (b - 2*a + 2)*(b - 2*a + 1)*3/2;
        }

        System.out.println(original);
    }
}
