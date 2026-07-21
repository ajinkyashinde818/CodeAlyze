import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    private static final PrintStream so = System.out;
    private static final Scanner     sc = new Scanner(System.in);

    public static void main(String[] args) {
        int K = sc.nextInt();
        int S = sc.nextInt();
        
        int count = 0;
        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                int z = S - (x+y);
                if (0 <= z && z <= K) {
                    count++;
                }
            }
        }
        so.println(count);
    }
}
