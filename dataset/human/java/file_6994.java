import java.util.*;
import java.math.RoundingMode;
import java.math.BigDecimal;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int a[] = new int[n];
		int d[] = new int[n];
		int ans = 0;
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		for(int i = 0; i < n-1; i++) {
			d[i] = a[i+1]-a[i];
		}
		d[n-1] = k-a[n-1]+a[0];
		Arrays.sort(d);
		for(int i = 0; i < n-1; i++) {
			ans+=d[i];
		}
		System.out.println(ans);
	}
}
