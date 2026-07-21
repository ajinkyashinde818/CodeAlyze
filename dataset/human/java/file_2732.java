import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String sd = max(sc.next(), false);
		String td = max(sc.next(), true);
		if (td.compareTo(sd) > 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
	
	public static String max(String s, boolean flag) {
		char[] arr = s.toCharArray();
		Arrays.sort(arr);
		StringBuilder sb = new StringBuilder(new String(arr));
		if (flag) {
			sb.reverse();
		}
		return sb.toString();
	}
}
