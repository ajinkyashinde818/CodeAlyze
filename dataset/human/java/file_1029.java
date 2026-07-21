import java.util.Scanner;

class Main {
    static final long mod = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        sc.close();
        int array[] = new int[n * 2]; // 0は左1は右
        char tmp = s.charAt(0);
        if (s.charAt(0) == 'W') {
            System.out.println(0);
            return;
        }
        for (int i = 1; i < 2 * n; i++) {
            char c = s.charAt(i);
            if (tmp == c) {
                array[i] = 1 - array[i - 1];
            } else {
                array[i] = array[i - 1];
            }
            tmp = c;
        }
        long ans = 1;
        long left = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (array[i] == 0) {
                left++;
            } else {
                ans *= left;
                ans %= mod;
                left--;
                if (left < 0) {
                    System.out.println(0);
                    return;
                }
            }
        }
        long fact[] = new long[n + 100];
        fact[0] = 1;
        fact[1] = 1;
        fact[2] = 2;
        for (int i = 3; i < n + 3; i++) {
            fact[i] = i * fact[i - 1];
            fact[i] %= mod;
        }
        ans *= fact[n];
        ans %= mod;
        if (left == 0) {
            System.out.println(ans);
        } else {
            System.out.println(0);
        }

    }
}
