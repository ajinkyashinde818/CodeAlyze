import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();
        int count = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                if (s - (i + j) <= k && 0 <= s - (i + j))
                    count++;
            }
        }
        System.out.println(count);
    }
}
