import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        c[n - 1] = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }

        for (int i = 0; i < n - 1; i++) {
            c[i] = in.nextInt();
        }

        int total = 0;
        int prevDinner = -1;
        for (int i = 0; i < n; i++) {
            int dinner = a[i];
            total += b[dinner - 1];

            if (prevDinner != -1 &&
                prevDinner + 1 == dinner) {
                total += c[prevDinner - 1];
            }

            prevDinner = dinner;
        }

        System.out.println(total);
    }
}
