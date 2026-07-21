import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] a = new int[n];
		long sum=0;
		int count=0;
		for(int i=0;i<n;i++) {
			a[i]=scn.nextInt();
			if(a[i]<0) {
				count++;
			}
			a[i]=Math.abs(a[i]);
			sum += a[i];
		}
		if(count%2==1) {
			Arrays.sort(a);
			sum-=a[0]*2;
		}
		System.out.println(sum);
		scn.close();
	}
}
