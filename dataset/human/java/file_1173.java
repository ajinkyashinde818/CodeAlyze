import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			
			int N = scan.nextInt();
			int[]a = new int[N];
			long []s = new long[N+1];
			long min = Long.MAX_VALUE;
			for(int i = 0;i<N;i++) {
				a[i] = scan.nextInt();
				s[i+1] = a[i]+s[i];
			}
			
			for(int i = 1;i<N;i++) {
				long sunuke = s[i];
				long araigu = s[N]-s[i];
				long ze = Math.abs(sunuke-araigu);
				
				if(min>ze)min = ze;
				
				
			}
			
			System.out.println(min);
			
			
			
			
		}
		
		
	}
		

}
