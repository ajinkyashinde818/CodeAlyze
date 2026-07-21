import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		String t = scan.next();
		int s_length = s.length();
		int t_length = t.length();
		String[] s_list = new String[s_length];
		String[] t_list = new String[t_length];
		String message = "No";
		int i = 0;
		for(i = 0; i < s_length; i++) {
			s_list[i] = s.charAt(i) + "";
		}
		for(i = 0; i < t_length; i++) {
			t_list[i] = t.charAt(i) + "";
		}
		Arrays.sort(s_list);
		Arrays.sort(t_list);
		for(i = 0; i < s_length && i < t_length; i++) {
			if(s_list[i].compareTo(t_list[t_length - i - 1]) < 0) {
				message = "Yes";
				break;
			} else if(s_list[i].compareTo(t_list[t_length - i - 1]) > 0) {
				break;
			}
		}
		if(i == s_length || i == t_length) {
			if(s_length < t_length) {
				message = "Yes";
			}
		}
		System.out.println(message);
	}
}
