import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            c[i] = in.nextInt();
        }

        int result = 0;

        int lastPlace = -1;
        for (int i = 0; i < n; i++) {
            result += b[a[i] - 1];
            if (lastPlace != -1) {
                if (a[i] == lastPlace + 1) {
                    result += c[lastPlace - 1];
                }
            }
            lastPlace = a[i];
        }
        System.out.println(result);
    }
}
