import java.util.*;

class Main {
    final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new Main().run();
    }

    private void run() {
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt()-1;
        }

        int now = 0;

        // 前回、残り何手のときに訪れたか
        long[] before = new long[n];
        Arrays.fill(before, -1);

        before[0] = k;
        while (true) {
            // 1手進める
            k--;
            now = a[now];

            // 既に訪れていたところであれば、そこから先はループなので、ショートカット
            if (before[now] != -1 && k > before[now] - k) {
                k = k % (before[now] - k);
            }
            before[now] = k;

            if (k == 0) {
                System.out.println(now+1);
                return;
            }
        }
    }
}
