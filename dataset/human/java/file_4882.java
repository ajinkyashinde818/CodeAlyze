import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println(solve(n));
    }

    public static long solve(long n){
        if(n % 2 != 0 || n < 10){
            return 0;
        }
        long ret = 0;
        int i=0;
        while(10*Math.pow(5,i) <= n){
            long def = 10*(long)Math.pow(5,i);
            ret += n/def;
            i++;
        }
        return ret;
    }
}
