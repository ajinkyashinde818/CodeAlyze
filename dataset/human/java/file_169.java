import java.util.Scanner;

import java.util.Arrays;
import java.util.ArrayList;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int [] A = new int[N];
		int [] B = new int[N];
		int negacnt = 0;
		long abstotal = 0;
		for (int i=0; i<N; i++) {
			A[i] = sc.nextInt();
			B[i] = Math.abs(A[i]);
			if(A[i] <= 0) {
				negacnt++;
			}
			abstotal += B[i];
		}
		
		if(negacnt % 2 == 1) {
			Arrays.sort(B);
			abstotal -= B[0] * 2;
		}
	
		System.out.println(abstotal);
		
	}
}
