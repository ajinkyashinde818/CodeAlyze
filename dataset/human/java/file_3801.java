import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		int n = s.length;
		int ans = 0, l = 0, r = n - 1;
		while(l < r) {
			if(s[l] == s[r]) {
				l++; r--;
			} else {
				if(s[l] != 'x' && s[r] != 'x') {
					System.out.println(-1);
					return;
				} else {
					if(s[l] == 'x') {
						l++;
						ans++;
					}
					if(s[r] == 'x') {
						r--;
						ans++;
					}
				}
			}
		}
		System.out.println(ans);
	}
}
