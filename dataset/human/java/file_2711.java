import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next(), t = sc.next();
		String ans[] = { "Yes", "No" };
		sc.close();
		char s2[] = s.toCharArray();
		char t2[] = t.toCharArray();

		Arrays.sort(s2);
		Arrays.sort(t2);
		int n = t2.length;
		for (int i = 0; i < n / 2; ++i) {
			char tmp = t2[n - i - 1];
			t2[n - i - 1] = t2[i];
			t2[i] = tmp;
		}
		int a = 0;
		int n2 = s2.length;
		for (int i = 0; i < n2; ++i) {
			if (s2[i] > t2[i]) {
				a = 1;
				break;
			} else if (s2[i] < t2[i])
				break;
			if (i > n - 2) {
				a = 1;
				break;
			}
		}
		System.out.println(ans[a]);
	}

}
