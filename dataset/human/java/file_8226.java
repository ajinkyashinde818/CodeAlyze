import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextInt();
        long B = sc.nextInt();

        System.out.println(lcm(A, B));

        sc.close();
    }

    public static long lcm(long a, long b) {
        long c = a * b;
        long maxVal = Math.max(a, b);
        long minVal = Math.min(a, b);

        long tmp = 0;
        while ((tmp = maxVal % minVal) != 0) {
            maxVal = minVal;
            minVal = tmp;
        }

        return (c / minVal);
    }
}
