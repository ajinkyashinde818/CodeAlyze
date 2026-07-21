import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int a = in.nextInt();
		int b = in.nextInt();
		long r = solve(a, b);
		System.out.println(r);
	}

	private static long solve(int a, int b) {
		long r = cm(a, b);
		a /= r;
		return (long) a * (long) b;
	}

	private static int cm(int a, int b) {
		if (a == b)
			return a;
		if (a < b) {
			int t = a;
			a = b;
			b = t;
		}
		if (a % b == 0)
			return b;
		else
			return cm(a % b, b);
	}
}
