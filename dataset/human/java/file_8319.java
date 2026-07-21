import java.util.*;

public class Main {

    static long gcd(long a,long b) {
        long temp;
        while ((temp=a%b)!=0) {
            a=b;
            b=temp;
        }
        return b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = Integer.parseInt(sc.next());
        long B = Integer.parseInt(sc.next());
        System.out.println(A*B/gcd(A, B));
    }
}
