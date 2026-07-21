import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        System.out.println(lcm(a,b));
    }
    static long lcm(long a, long b) {
        long t;
        long c=a;
        c *= b;
        while((t = a%b)!=0) {
            a = b;
            b = t;
        }
        return (long)(c/b);
    }
}
