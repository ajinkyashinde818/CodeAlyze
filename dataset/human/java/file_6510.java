import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int K = scan.nextInt();
        int S = scan.nextInt();
        long answer = 0;
        for (int x = 0; x <= K; x++) {
            int limit_y = Math.min(K, S - x);
            for (int y = 0; y <= limit_y; y++) {
                if (S - x - y <= K) {
                    answer += 1;
                }
            }
        }
        System.out.println(answer);
    }
}
