import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		
		int ans = new String(s).compareTo(new StringBuilder(new String(t)).reverse().toString());
    System.out.println(ans < 0 ? "Yes" : "No");
	}
}
