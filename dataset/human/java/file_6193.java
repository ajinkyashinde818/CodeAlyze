import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int K = scan.nextInt();
		int S = scan.nextInt();
		
		int count = 0;
		
		for (int X = 0; X <= K; X++) {
			for (int Y = 0; Y <= K; Y++) {
				if (S - X - Y >= 0 && S - X - Y <= K) {
					count++;
				}
			}
		}
		
		System.out.print(count);
		
	}

}
