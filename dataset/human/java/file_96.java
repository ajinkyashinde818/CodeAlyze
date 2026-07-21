import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        boolean even = true;
        boolean zeroExit = false;
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(sc.next());
            if (a[i] < 0) {
                even = !even;
            }
            if (a[i] == 0) {
                zeroExit = true;
            }
        }

        long result = 0;
        if (even || zeroExit) {
            for (int i = 0; i < n; i++) {
                result += Math.abs(a[i]);
            }
        } else {
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                result += Math.abs(a[i]);
                min = Math.min(min, Math.abs(a[i]));
            }
            result -= min * 2;
        }

        System.out.println(result);
    }
}
