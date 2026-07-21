import java.io.*;
import java.math.*;
import java.util.*;
public class Main { 
 
	public static void main(String[] args) { 
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		long sum = 0;
		int cntneg = 0;
		long min = Long.MAX_VALUE;
		for (int i = 0; i < N; i++) {
			long x = input.nextLong();
			if (x < 0) {
				x*=-1;
				cntneg++;
			} 
			sum+=x;
			min=Math.min(x, min);
		}
		if (cntneg%2==1) sum-=min*2; //Times 2 because after excluding, 
		//we also subtract the minimum value
		System.out.println(sum);
	}
}
