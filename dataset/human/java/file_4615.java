import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long count = 0l;
        long diffbc = Math.min(b, c);
        b -= diffbc;
        c -= diffbc;
        count += 2 * diffbc;
        if (c == 0) {
            count += b;
        } else {
            long diffac = Math.min(a, c);
            count += diffac;
            if (c > a) {
                count += 1;
            }
        }
        System.out.println(count);
    }

}
