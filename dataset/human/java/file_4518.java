import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        //String s = sc.next();
//        int[] a = new int[n];
//        for (int i = 0 ; i < n ; i++) {
//            a[i] = sc.nextInt();
//        }

        long ans = 0;
        if (a + b >= c - 1) {
            System.out.println(b + c);
        } else {
            System.out.println(a + b + 1 + b);
        }

    }

}
