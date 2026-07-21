import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long k = scanner.nextLong();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt() - 1;
        }

        int[] visit = new int[n];
        visit[0] = 1;
        int loopLen = 1;
        int loopStart = 0;
        for (int i = 0; i < n; i++) {
            if (visit[a[loopStart]] != 0) {
                if (k > visit[a[loopStart]] - 1) {
                    k -= visit[a[loopStart]] - 1;
                    loopLen = visit[loopStart] + 1 - visit[a[loopStart]];
                    k = k % loopLen;
                    loopStart = a[loopStart];
                } else {
                    loopStart = 0;
                }
                break;
            } else {
                visit[a[loopStart]] = visit[loopStart] + 1;
                loopStart = a[loopStart];
            }
        }
        for (int i = 0; i < k; i++) {
            loopStart = a[loopStart];
        }
        System.out.println(loopStart + 1);
    }
}
