import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long a = sc.nextLong();
        long b = sc.nextLong();
        
        System.out.println(lcm(a, b));
    }
    
    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    private static long lcm(long a, long b) {
        long mult = a * b;
        return mult / gcd(a, b);
    }
}
