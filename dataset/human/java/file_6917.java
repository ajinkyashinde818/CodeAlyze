import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {

		Scanner scn = new Scanner(System.in);
		long k = scn.nextLong();
		int n = scn.nextInt();
		Long d[] = new Long[n];
		long s = scn.nextLong();
		long p = s;
		for (int i = 1; i < n - 1; i++) {
			long v = scn.nextLong();
			d[i] = v - p;
			p = v;
		}
		long v = scn.nextLong();
		d[n - 1] = v - p;
		d[0] = k - v + (s);
		Arrays.sort(d);
		System.out.println(k - d[n - 1]);
	}
}
