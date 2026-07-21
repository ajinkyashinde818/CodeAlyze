import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextInt();
        long b = sc.nextInt();
        System.out.println(lcm(a, b));
    }

    private static long lcm(long a, long b) {
        return a * b / gcb(a, b);
    }

    private static long gcb(long a, long b) {
        if (a < b) return gcb(b, a);
        if (b == 0) return a;
        return gcb(b, a%b);
    }
}
