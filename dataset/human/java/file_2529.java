import java.util.Arrays;
import java.util.Scanner;
import java.util.Comparator;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		
		Integer[] sh = new Integer[s.length()];
		Integer[] th = new Integer[t.length()];
		
		for(int i = 0; i < s.length(); i++) {
			int x = s.charAt(i);
			sh[i] = x;
		}
		
		for(int i = 0; i < t.length(); i++) {
			int x = t.charAt(i);
			th[i] = x;
		}
		
		Arrays.sort(sh);
		Arrays.sort(th, Comparator.reverseOrder());
		
		int check = 0;
		
		if(s.length() <= t.length()) {
			for(int i = 0; i < s.length(); i++) {
				if(sh[i] > th[i]) {
					System.out.println("No");
					check = 1;
					break;
				} else if(sh[i] < th[i]) {
					System.out.println("Yes");
					check = 1;
					break;
				}
			}
			if(check == 0 && s.length() == t.length()) {
				System.out.println("No");
			} else if(check == 0 && s.length() < t.length()){
				System.out.println("Yes");
			}
		} else {
			for(int i = 0; i < t.length(); i++) {
				if(sh[i] > th[i]) {
					System.out.println("No");
					check = 1;
					break;
				} else if(sh[i] < th[i]) {
					System.out.println("Yes");
					check = 1;
					break;
				}
			}
			if(check == 0) {
				System.out.println("No");
			}
		}
	}
}
