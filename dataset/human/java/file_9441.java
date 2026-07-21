import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] x = new int[N];
		int[] y = new int[N];
		int maxc = 0;
		int c = 0;
		for (int i = 0; i < N; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			if (x[i] == y[i]) {
				c++;
			} else {
				if (c > maxc)
					maxc = c;
				c = 0;
			}
		}
		if (maxc >= 3 || c >= 3)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
