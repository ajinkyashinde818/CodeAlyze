import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int mx = Math.max(a,b);
		int mn = Math.min(a,b);
		//
		while ( mn > 0 ) {
			if ( mx > mn ) {
				mx = mx % mn;
			} else {
				int wk = mx;
				mx = mn;
				mn = wk;
			}
		} 
		long ans = ((long)a * (long)b) / (long)mx;
		System.out.println(ans);
	}
}
