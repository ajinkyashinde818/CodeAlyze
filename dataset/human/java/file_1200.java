import java.util.Scanner;
public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		long []s = new long [n];
		
		for(int i = 0; i < n ;i++) {
		 if(i > 0) {
			s[i] += s[i-1];
		}
		   long x = sc.nextLong();
			s[i] += x;
			
		}
		
		long min = 200000000000000L;
		
		for(int i = 0 ; i < n-1 ; i++) {
			long a = s[i];
			long b = s[n-1] - s[i];
			
			long temp = Math.abs(a - b);
			min = Math.min(temp, min);
		}
		
		System.out.println(min);
		

	}

}
