import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		long n = in.nextLong();

		if (n%2 == 1) {
			System.out.println(0);
		} else {
			long count = 0;
			for (long i=10; i<=1000000000000000000L; i*=5)
				count += n/i;
			System.out.println(count);
		}
	}
}
