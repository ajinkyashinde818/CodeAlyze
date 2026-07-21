import java.util.*;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		String ans = "No";
		for (int i=0; i < str.length(); i++) {
			String st = str.substring(i, i+1);
			if(st.equals("9")) {
				ans = "Yes";
			}
		}
		System.out.print(ans);
	}
}
