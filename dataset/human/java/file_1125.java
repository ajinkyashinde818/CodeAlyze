import java.util.*;
public class Main {
	public static void main(String[] args)  {
		Scanner scan = new Scanner(System.in);
		int n = Integer.parseInt(scan.next());
		int[] a =new int [n];
		for (int i = 0;i < n; ++i){
			a[i] = Integer.parseInt(scan.next());
		}

		long[] sum_araiguma = new long[n-1];sum_araiguma[n-2]=a[n-1];
		long[] sum_sunuke = new long[n-1];sum_sunuke[0]=a[0];

		for(int i = 1;i < n-1; ++i){
			sum_sunuke[i]=sum_sunuke[i-1]+a[i];
			sum_araiguma[n-2-i]=sum_araiguma[n-1-i]+a[n-i-1];
		}

		long min=Long.MAX_VALUE;
		for (int i = 0;i < n-1; ++i){
			min=Math.min(Math.abs(sum_araiguma[i]-sum_sunuke[i]), min);
		}
		System.out.print(min);
	}
}
//end
