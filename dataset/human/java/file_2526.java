import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.next();
		String t = scanner.next();
		char[] sc = new char[s.length()];
		char[] tc = new char[t.length()];
		for (int i = 0; i < s.length(); i++) {
			sc[i] = s.charAt(i);
		}
		for (int i = 0; i < t.length(); i++) {
			tc[i] = t.charAt(i);
		}
		Arrays.sort(sc);
		Arrays.sort(tc);
		String ans = "No";
		for (int i = 0,j=t.length()-1; i < s.length() && j >= 0; i++,j--) {
			if(sc[i] < tc[j]) {
				ans = "Yes";
				break;
			}else if(sc[i] == tc[j]){
				if(s.length()<t.length() && i== s.length()-1){
					ans = "Yes";
				}
			}
		}
		System.out.println(ans);
	}
}
