import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		int n = s.length();
		StringBuilder sb = new StringBuilder();
		
		sb.append(s);
		
		for(int i = n-1; i >= 0 ;i--) {
			if(sb.charAt(i) == 'x') {
				sb.deleteCharAt(i);
			}
		}
		
		char []c = sb.toString().toCharArray();
		int m = c.length;
		
		for(int i = 0 ; i < m ;i++) {
			if(c[i] != c[m - 1 -i]) {
				System.out.println(-1);
				return;
			}
		}
		
		int []x = new int [m+1];
		int cnt = 0;
		for(int i = 0 ; i < n ;i++) {
			if(s.charAt(i) != 'x') {
				cnt++;
			}
			else {
				x[cnt]++;
			}
		}
		
		int ans = 0;
		
		for(int i = 0 ; i <= m ;i++) {
			ans += Math.abs(x[m-i] - x[i]);
		}
		
		System.out.println(ans/2);
		
		
		
	}
}
