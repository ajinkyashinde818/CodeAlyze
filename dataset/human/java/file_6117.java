import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int K = cin.nextInt();
        int S = cin.nextInt();
        int c = 0;
        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                int z = S - x - y;
                if (z >= 0 && z <= K) {
                    c++;
                }
            }
        }
        System.out.println(c);
    }
}
