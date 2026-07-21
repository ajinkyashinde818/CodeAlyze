import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		long a = in.nextLong();
		long b = in.nextLong();
		long gcd = gcd(a, b);
		System.out.println(a * b / gcd);
	}

	public static long gcd(long n1, long n2) {
    if (n2 == 0)
        return n1;
    return gcd(n2, n1 % n2);
	}
}
