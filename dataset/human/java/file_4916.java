import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long n = sc.nextLong();
		
		long ans = 0;
		
		double log = Math.log10((double)n);
		
		if(n % 2 == 0) {
			n = n/2;
			for(int i = 1 ;; i++) {
				
				long temp = (long)Math.pow(5, i);
				if(n < temp) {
					break;
				}
				ans += (long)Math.floorDiv(n,temp);
				
				}
			System.out.println(ans);
		}
		
		else {
			System.out.println(0);
		}

	}

}
