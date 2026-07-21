import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // KEYENCE-C - Subarray Sum

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();

        int out = s;
        for (int i = 0; i < n; i++) {
            out = s;
            if (i >= k) {
                if (s < 1000000000) {
                    out++;
                } else {
                    out--;
                }
            }
            System.out.print((i > 0 ? " " : "") + out);
        }

        System.out.println();
    }
}
