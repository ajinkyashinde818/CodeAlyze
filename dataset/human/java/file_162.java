import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();



        int[] a = new int[n];
        long min = Integer.MAX_VALUE;
        int c = 0;
        for (int i = 0 ; i < n ; i++) {
            a[i] = sc.nextInt();
            min = Math.min(min, Math.abs(a[i]));
            if (a[i] < 0) {
                c++;
            }
        }

        long sum = 0;

        for (int i = 0 ; i < n ; i++) {
            sum += Math.abs(a[i]);
        }

        if (c % 2 == 0) {
            System.out.println(sum);
        } else {
            System.out.println(sum - 2 * min);
        }




    }

}
