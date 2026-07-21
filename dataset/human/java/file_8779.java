import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		int k = sc.nextInt();
		
		boolean[] array = new boolean[101];
		Arrays.fill(array, false);
		
		int min = Math.min(a, b);
		
		for (int i = 1; i <= min; i++) {
			if (a % i == 0 && b % i == 0) {
				array[i] = true;
			}
		}
		
		int count = 0;
		
		for (int i = 100; i >= 0; i--) {
			if (array[i]) {
				if (++count == k) {
					System.out.println(i);
					break;
				}
			}
		}
	}
}
