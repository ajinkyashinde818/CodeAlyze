import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Main {
    static long MOD = (long)Math.pow(10, 9) + 7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long N = in.nextLong();
        if(N%2 != 0) System.out.println(0);
        else {
            long sum = 0;
            long m = 10;
            while(N/m >= 1) {
                sum += N/m;
                m *= 5;
            }
            System.out.println(sum);
        }
    }
}
