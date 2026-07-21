import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0 ; i < n ; i++) {
            a[i] = sc.nextInt();
        }
        int[] b = new int[n];
        int[] c = new int[n - 1];
        int count = 0;
        for (int i = 0 ; i < n ; i++) {
            b[i] = sc.nextInt();
            count += b[i];
        }
        for (int i = 0 ; i < n - 1 ; i++) {
            c[i] = sc.nextInt();
        }


        for (int i = 0 ; i < n - 1 ; i++) {
            if (a[i + 1] == a[i] + 1 ) {
                count += c[a[i] - 1];
            }
        }

        System.out.println(count);
    }

}
