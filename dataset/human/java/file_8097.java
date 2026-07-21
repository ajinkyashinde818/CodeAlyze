import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		
		long min = Math.min(a, b);
		for (long i = min; 0 < i; i--) {
			if (a % i == 0 && b % i == 0) {
				min = i;
				break;
			}
		}
		
		System.out.println(a * b / min);
	}
}
