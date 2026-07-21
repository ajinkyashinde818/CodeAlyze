import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception {
        InputStreamReader r = new InputStreamReader(System.in);
        long A = nextInt(r);
        long B = nextInt(r);

        long ans = A > B ? calcLCM(A, B) : calcLCM(B, A);
        System.out.println(ans);
    }

    public static int nextInt(InputStreamReader r) throws Exception {
        String str = "";
        while (true) {
            int c = r.read();
            if (c == 32 || c == 10 || c == -1) {
                break;
            }
            str += (char)c;
        }
        return Integer.parseInt(str);
    }

    public static long calcLCM(long large, long small) {
        long result = 0;
        long tmp = small;
        while (true) {
            if (small % large == 0) {
                result = small;
                break;
            } else {
                small += tmp;
            }
        }
        return result;
    }
}
