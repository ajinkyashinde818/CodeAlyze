import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final PrintStream so = System.out;
    static final Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
        int N = ni();
        int[] A = new int[N];
        int min = Integer.MAX_VALUE;
        long sum = 0;
        int countMinus = 0;
        for (int i = 0; i < N; i++) {
            int Ai = ni();
            if (Ai < 0) {
                countMinus++;
            }
            if (Math.abs(Ai) < Math.abs(min)) {
                min = Ai;
            }
            sum += Math.abs(Ai);
        }
        if (countMinus % 2 == 0) {
            so.println(sum);
        } else {
            so.println(sum - 2*Math.abs(min));
        }
    }
        
       
    static int ni() {
        return sc.nextInt();
    }
    
    static long nl() {
        return sc.nextLong();
    }

    static char[] nsToChars() {
        return sc.next().toCharArray();
    }
}
