import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		long N = stdIn.nextInt();
		long K = stdIn.nextInt();
		long S = stdIn.nextInt();
		
		long len = N-(K-1);
		if(S >= len) {
			long a = S/(len);
			long b = S-a*(len-1);
			
			for(int i = 0; i < N; i++) {
				if((i+1)%len == 0) {
					System.out.println(b);
				}
				else {
					System.out.println(a);
				}
			}
		}
		else {
			for(int i = 0; i < N; i++) {
				if(i < S+K-1) {
					System.out.println(1);
				}
				else {
					System.out.println(S+1);
				}
			}
		}
		

	}

}
