import java.util.Scanner;

public class Main{

    static long gcd(long a, long b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }

    static long lcm(long a, long b) {
        return (a*b)/gcd(a, b);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long A = sc.nextInt();
        long B = sc.nextInt();
        System.out.println(lcm(A,B));
    }
}
