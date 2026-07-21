import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = Integer.parseInt(scan.next());
        int b = Integer.parseInt(scan.next());
        int k = Integer.parseInt(scan.next());
        scan.close();

        int ans = 0;
        int count = 0;

        for (int i = 100; i >= 1; i--) {
            if (a % i == 0 && b % i == 0) {
                count++;
            }
            if (count == k) {
                ans = i;
                break;
            }
        }

        System.out.println(ans);
    }

}
