import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();



        int[] a = new int[n];
        for (int i = 0 ; i < n ; i++) {
            if (i < k) {
                a[i] = s;
            } else {
                if (s == 1000000000) {
                    a[i] = 1;
                } else {
                    a[i] = s + 1;
                }
            }
        }

        for (int i = 0 ; i < n ; i++) {
            System.out.print(a[i]);
            if (i < n - 1) {
                System.out.print(" ");
            } else {
                System.out.print("\n");
            }
        }
    }

}
