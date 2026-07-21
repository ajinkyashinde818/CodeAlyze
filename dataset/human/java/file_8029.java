import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    public static void main (String[] args) throws java.lang.Exception {
        Scanner io = new Scanner(System.in);
        long a = io.nextInt(), b = io.nextInt();
        System.out.println((a * b) / gcd(a, b));
    }
    public static long gcd(long a, long b) {
        return a == 0 ? b : gcd(b % a, a);
    }
}
