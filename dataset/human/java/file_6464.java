import java.math.BigDecimal;
import java.util.*;
import java.util.stream.Collectors;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();
        int cnt = 0;
        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= k; y++) {
                int a = s - y - x;
                if (a >= 0 && a <= k) {
                    cnt++;
                }
            }
        }
        System.out.println(cnt);

    }
}
