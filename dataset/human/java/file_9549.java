import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int cnt = 0;
		String ans = "No";
		for(int i = 0; i < n; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			if(a == b) cnt += 1;
			else cnt = 0;
			if(cnt >= 3) {
				ans = "Yes";
				break;
			}
		}
		System.out.println(ans);
	}
}
