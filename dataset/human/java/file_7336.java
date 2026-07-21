import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		String s = sc.next();
		StringBuilder sb = new StringBuilder(s);
		final String d = "dream";
		final String eer = "eraser";
		final String ee = "erase";
		final String er = "er";
		boolean ok = true;
		boolean AfterDream = false;
		while(sb.length()!=0) {
			if(sb.length() >= 5&&sb.substring(0, 5).equals(d)) {
				sb.delete(0, 5);
				AfterDream = true;
				continue;
			} else 	if(sb.length() >= 6&&sb.substring(0, 6).equals(eer)) {
				sb.delete(0, 6);
			} else if(sb.length() >= 5&&sb.substring(0, 5).equals(ee)) {
				sb.delete(0, 5);
			} else if(AfterDream==true&&sb.length() >= 2 &&sb.substring(0, 2).equals(er)) {
				sb.delete(0, 2);
				AfterDream = false;
			} else {
				ok = false;
				break;
			}
			AfterDream = false;
		}
		System.out.println(ok ? "YES" : "NO");
	}
}
