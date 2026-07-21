import java.util.*;
import java.util.function.BiConsumer;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		int ans = 0;

		for(int i=2; i <= Math.sqrt(N); i++) {
			int count = 0;
			while(N%i == 0) {
				N = N / i;
				count ++;
			}
			
			for(int j=1; count-j>=0; j++) {
				ans ++;
				count -= j;
			}
		}
		
		
		if(N > 1) {
			ans ++;
		}
		System.out.println(ans);

	}
}
