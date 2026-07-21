import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();
		String ans[] = { "Yes", "No"};
		int a = 0;
		char s2[] = s.toCharArray();
		Arrays.sort(s2);
		String tmp = "abc";
		for(int i = 0; i < s.length(); ++i) {
			if(tmp.charAt(i) != s2[i])a = 1;
		}
		System.out.println(ans[a]);
	}

}
