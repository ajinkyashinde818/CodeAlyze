import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long  b = sc.nextLong();
        long ret = a*b/gcd(a,b);

        System.out.println(ret);
        // write your code here

    }
    static long gcd(long a, long b ){
        while(a==0){
            return b;
        }
        return gcd(b%a,a);
    }
}
