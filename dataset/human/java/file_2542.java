import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		for(int i = 0 ; i < s.length - 1 ; i++) {
			for(int j = i + 1 ; j < s.length ; j++) {
				if(s[i] > s[j]) {
					char w = s[i];
					s[i] = s[j];
					s[j] = w;
				}
			}
		}
		for(int i = 0 ; i < t.length - 1 ; i++) {
			for(int j = i + 1 ; j < t.length ; j++) {
				if(t[i] < t[j]) {
					char w = t[i];
					t[i] = t[j];
					t[j] = w;
				}
			}
		}
		if(new String(t).compareTo(new String(s)) > 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
