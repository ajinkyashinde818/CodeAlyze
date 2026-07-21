import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		
		int times = 0;
		int max = Math.max(A, B);
		int output = max;
		for(int i = max; i >= 1; i--) {
			if(A%i == 0 && B%i == 0) {
				times++;
				output = i;
				if(times == K) {					
					break;
				}
			}
		}
		System.out.println(output);	
	}
}
