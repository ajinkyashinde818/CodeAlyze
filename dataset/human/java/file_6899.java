import java.util.*;
import java.lang.*;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int k = s.nextInt();
		int n = s.nextInt();
		int[] a = new int[n];

		for(int i=0;i<n;i++) {
			a[i]=s.nextInt();
		}
		int[] diff = new int[n];

		diff[0]=a[0]+k-a[n-1];
		for(int i=1;i<n;i++) {
			diff[i] =  a[i]-a[i-1];
		}
		int max = 0;
		for(int i=0;i<n;i++) {
			if(diff[i]>max) 
				max = diff[i];
		}
		System.out.println(k-max);
	}

 }
