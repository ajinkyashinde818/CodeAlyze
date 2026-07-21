import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static Scanner sc = null;
    static PrintWriter pw = null;

    static {

        try {
            sc = new Scanner(System.in);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static final long MOD = 1_000_000_007;

    private static String data;


    public static void main(String[] args) {
        data = sc.next();
        int [] dd = new int[2];
        int l = data.length() - 1;

        for (int endIndex = 0 ; endIndex < data.length() ; endIndex++) {
            int ii = data.charAt(endIndex) - '0';
            int [] dd1 = new int[2];
            for (int overcharge = 0 ; overcharge<= 1 ; overcharge++) {
                ii += overcharge;
                dd1[overcharge] = Math.min((endIndex == 0 ? 0 : dd[0]) + ii,
                        (endIndex == 0 ? 1 : dd[1]) + 10 - ii);
            }
            dd = dd1;

        }


        System.out.println(dd[0]);
    }





}
