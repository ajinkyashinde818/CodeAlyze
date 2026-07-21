import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws Exception {
		final Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long k = sc.nextLong();
		long s = sc.nextLong();

		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < k; i++) {
			sb.append(s).append(" ");
		}

		for (int i = 0; i < n - k; i++) {
			if (s == 1000000000) sb.append(1);
			else sb.append(s + 1);
			sb.append(" ");
		}

		System.out.println(sb.toString());
	}
}
