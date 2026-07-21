import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main
{
    public static void main (String[] args) throws java.lang.Exception {
        Scanner io = new Scanner(System.in);
        /*for(long i = 1; i <= 1000; i++)
            System.out.println(i + " " + leadingzeros(foo(BigInteger.valueOf(i))));*/
        long s = 0;
        long n = io.nextLong();
        if(n < 10 || n % 2 == 1) {
            System.out.println(0);
            return;
        }
        s += n/10;
        for(long i = 50; i <= n; i*=5)
            s += n / i;
        System.out.println(s);
    }
    /*public static BigInteger foo(BigInteger n) {
        return n.equals(BigInteger.ONE) || n.equals(BigInteger.TWO) ? BigInteger.ONE : n.multiply(foo(n.subtract(BigInteger.TWO)));
    }
    public static long leadingzeros(BigInteger n) {
        String str = n.toString();
        long c = 0;
        for(int i = 1; i <= str.length(); i++)
            if(str.charAt(str.length()-i) != '0' || c++ < 0) break;
        return c;
    }*/
}
