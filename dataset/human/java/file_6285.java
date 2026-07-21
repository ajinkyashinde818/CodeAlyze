import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();

        int l = Math.min(s, k);
        int total = 0;
        for (int i = l; i >= 0; i--) {
            int m = Math.min(s - i, k);
            if (s - i < k) {
                total += m + 1;
            } else {
                total += Math.max(k - (s - i - m) + 1, 0);
            }
        }
        System.out.println(total);
    }
}
