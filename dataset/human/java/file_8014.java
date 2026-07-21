import java.util.Scanner;

public class Main
{
    /*
     * a = bp + q
     * gcd(a, b) = gcd(b, q)
     */
    private static long gcd(long a, long b)
    {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    private static long lcm(long a, long b)
    {
        return a * b / gcd(a, b);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(lcm(a, b));
    }
}
