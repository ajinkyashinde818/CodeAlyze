import java.util.Arrays;
import java.util.Scanner;
import java.util.StringJoiner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long s = sc.nextLong();
        long[] a = new long[n];
        if (s < Math.pow(10, 9)) {
            Arrays.fill(a, s + 1);
        } else {
            Arrays.fill(a, 1);
        }
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                break;
            }
            a[i] = s;
        }

        StringJoiner sj = new StringJoiner(" ");
        for (int i = 0; i < n; i++) {
            sj.add(String.valueOf(a[i]));
        }
        System.out.println(sj.toString());
    }

}
