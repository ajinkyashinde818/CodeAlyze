import java.util.Arrays;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		
		int []a = new int [n];
		int []b = new int [n];
		
		int cnt = 0;
		
		for(int i = 0 ;i < n ;i++) {
			a[i] = Integer.parseInt(sc.next());
			if(a[i] <= 0) { 
				cnt++;
			}
			
			b[i] = Math.abs(a[i]);
		}
		
		Arrays.sort(b);
		long ans = 0;
		
		for(int i = 0 ; i < n;i++) {
			
			ans += (long)b[i];
		}
		
		if(cnt % 2 == 0) {
			System.out.println(ans);
		}
		else {
			ans -= (long)b[0] * 2;
			System.out.println(ans);
		}

	}

}
