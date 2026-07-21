import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		char[] s = sc.next().toCharArray();
		int l = 0;
		int r = s.length - 1;
		int cnt = 0;
		while (l <= r) {
			if (s[l] == s[r]) {
				l++;
				r--;
			} else if (s[l] == 'x') {
				l++;
				cnt++;
			} else if (s[r] == 'x') {
				r--;
				cnt++;
			} else {
				cnt = -1;
				break;
			}
		}
		System.out.println(cnt);
	}
}
