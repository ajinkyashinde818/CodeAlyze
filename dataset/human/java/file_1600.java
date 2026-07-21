import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        long mod = 1000000007;
        int[] counts = new int[26];

        for (int i = 0; i < n; ++i) {
            int current = s.charAt(i) - 'a';
            counts[current]++;
        }
        long result = 1;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == 1) {
                result *= 2;
                result %= mod;

            } else if (counts[i] > 1) {
                result *= (counts[i] + 1);
                result %= mod;
            }
        }
        result--;
        System.out.println(result);

    }
}
