import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int k = sc.nextInt();
		int n = sc.nextInt();

		int[] a = new int[n];
		int md = 0;
		for ( int i=0; i<n; i++ ) {
			a[i] = sc.nextInt();
			if ( i!=0 ) {
				md = Math.max(md, a[i]-a[i-1]);
			}
		}
		md = Math.max(md, a[0]+k-a[n-1]);

		System.out.println(k-md);
	}
}
