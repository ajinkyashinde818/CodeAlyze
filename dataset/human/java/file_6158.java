import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int K = Integer.parseInt(scanner.next());
        int S = Integer.parseInt(scanner.next());
        scanner.close();

        int ans = 0;
        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                int z = S - x - y;
                if (z >= 0 && z <= K) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}
