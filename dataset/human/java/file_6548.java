import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int s = scanner.nextInt();
        int ans = 0;
        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= x; y++) {
                for (int z = 0; z <= y; z++) {
                    if (x + y + z == s) {
                        if (x == y && y == z) ans++;
                        else if (x == y || y == z || x == z) ans += 3;
                        else ans += 6;
                    }
                }
            }
        }
        System.out.println(ans);
    }

}
