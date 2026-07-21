import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
	static int max;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ar = new int[100003];
		ar[0] = 1;
		ar[100002] = -1;
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			ar[a]++;
			ar[b+1]--;
		}
		int max = 0;
		for(int i = 1; i < ar.length; i++) {
			ar[i] += ar[i-1];
			if(ar[i] >= i) max = Math.max(max, i);
		}
		
		
		System.out.println(max-1);
		
		
		
		
		
		
		
	}
}
