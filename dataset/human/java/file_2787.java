import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int s[] = new int[26];
		int t[] = new int[26];
		String S = sc.next();
		String T = sc.next();
		for (int i=0;i<S.length();i++) {
			s[S.charAt(i)-'a']++;
		}
		for (int i=0;i<T.length();i++) {
			t[T.charAt(i)-'a']++;
		}
		int i = 0;
		for (;i<26;i++) {
			if (s[i]>0) {
				break;
			}
		}
		int j =25;
		for (;j>=0;j--) {
			if (t[j]>0) {
				break;
			}
		}
		if (j>i) {
			System.out.println("Yes");
		} else if (j==i){
			if (s[i]==S.length()) {
				if (s[i]<t[j]) {
					System.out.println("Yes");
				} else if (s[i]==t[j]&&S.length()<T.length()) {
					System.out.println("Yes");
				} else {
					System.out.println("No");
				}
			} else {
				System.out.println("No");
			}
		} else {
			System.out.println("No");
		}
	}
}
