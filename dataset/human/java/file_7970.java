import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a=sc.nextInt();
        long b=sc.nextInt();
        System.out.println(a*b/gcd(a,b));

    }

    static long gcd(long m, long n) {
        if(m<n){
            n=m+n;
            m=n-m;
            n=n-m;
        }
        m%=n;
        if(m==0){
            return n;
        }else{
            return gcd(n,m);
        }

    }

}
