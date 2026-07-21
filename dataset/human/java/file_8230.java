import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();

        long g = gcd(A, B);
        long ans = (A/g) * (B/g) * g;
        System.out.println(ans);
    }

    static long gcd(long a, long b){
        return b == 0 ? a : gcd(b,a % b); 
    }
}
